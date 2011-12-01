#include "f_jeu.h"
#include "ui_f_jeu.h"

#include <QMessageBox>
#include <QTime>
#include <controlleur.h>
#include <QDebug>
#include <Qimage>
#include <QTimer>

F_Jeu::F_Jeu(QString nomS, Controlleur *controlleur, Historique *hist, Jeu_Ui *jeu_ui) :
    QWidget(),
    ui(new Ui::F_Jeu)
{
    ui->setupUi(this);

    _jeu_ui=jeu_ui;
    _controlleur=controlleur;
    _historique=hist;

    //Gestion de l'attribut Nom_Session
    _Nom_Session=nomS;
    ui->Nom_Session->setText(_Nom_Session);

    //Gestion de l'attribut Nom_Jeu + Non affichage des Label Timer & Level
    _Nom_Jeu=_controlleur->get_nom_jeu();
    ui->Nom_Jeu->setText(_Nom_Jeu);
    if ((_Nom_Jeu=="Calculate!")||(_Nom_Jeu=="QuickShape!"))
    {
        ui->label_Niveau->hide();
        ui->Valeur_Niveau->hide();
        ui->Label_Essais->hide();
        ui->Valeur_Essais->hide();
    }
    else if (_Nom_Jeu=="Memorize!")
    {
        ui->label_Temp->hide();
        ui->Valeur_Temps->hide();
    }

    //connexion du bouton Retour
    QObject::connect(ui->Bouton_Retour_Session,SIGNAL(clicked()),SLOT(Envoi_Signal_Retour_Session()));

    //Affichage du jeu :
    _jeu_ui->setParent(ui->Widget_Jeu);
    _jeu_ui->move(0,0);
    QObject::connect(_controlleur,SIGNAL(changement_timer(QTime)),this,SLOT(AfficherTimer(QTime)));
    QObject::connect(_controlleur,SIGNAL(changement_score(int)),this,SLOT(AfficherScore(int)));
    QObject::connect(_controlleur,SIGNAL(changement_Niveau(int)),this,SLOT(AfficherNiveau(int)));
    QObject::connect(_controlleur,SIGNAL(changement_Essais(int)),this,SLOT(AfficherEssais(int)));

    QObject::connect(_controlleur,SIGNAL(Signal_Score_final(int)),this,SLOT(Fin_Jeu(int)));

    //On ajoute le pouce !
    QImage image("pouce_haut.png");
    ui->Label_Pouce->setPixmap(QPixmap::fromImage(image).scaled(ui->Label_Pouce->size()));
    ui->Label_Pouce->hide();

    //Gestion de l'affichage du pouce :
    _duree_pouce = new QTimer(this);
    _duree_pouce->setSingleShot(true);
    QObject::connect(_duree_pouce,SIGNAL(timeout()),ui->Label_Pouce,SLOT(hide()));
}

F_Jeu::~F_Jeu()
{
    delete ui;
}

void F_Jeu::Envoi_Signal_Retour_Session()
{
    _controlleur->end_game();
    emit Signal_Retour_Session();
}

void F_Jeu::AfficherTimer(QTime timeRemaining)
{
    ui->Valeur_Temps->setText(timeRemaining.toString("mm:ss"));
}

void F_Jeu::AfficherScore(int score)
{
    ui->Valeur_Score->setText((QString::number(score)));
    if (score!=0)
    {
        ui->Label_Pouce->show();
        _duree_pouce->start(400);
    }
}

void F_Jeu::AfficherNiveau(int niveau)
{
    ui->Valeur_Niveau->setText(QString::number(niveau));
}

void F_Jeu::AfficherEssais(int essai)
{
    ui->Valeur_Essais->setText(QString::number(essai));
}

void F_Jeu::Fin_Jeu(int score)
{
    //On écrit tout d'abord dans l'historique
    QString msg_hist=_Nom_Jeu+"/"+QString::number(score);
    _historique->Ecrire(msg_hist);

    //Puis on demande si l'utilisateur souhaite rejouer :
    int reponse = QMessageBox::question(this, "Fin de l'exercice "+_Nom_Jeu, "Votre Score est : "+QString::number(score)+"\n\nSouhaitez-vous recommencer l'exercice?", QMessageBox::Yes | QMessageBox::No);
    if (reponse == QMessageBox::Yes)
        _controlleur->init_game(60);
    else
        emit Signal_Retour_Session();
}
