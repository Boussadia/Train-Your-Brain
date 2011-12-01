#include "f_session.h"
#include "ui_f_session.h"

#include <QFile>
#include <QDateTime>
#include <QTextStream>

F_Session::F_Session(QString nom) :
    QWidget(),
    ui(new Ui::F_Session)
{
    ui->setupUi(this);
    Nom_Session=nom;
    _historique = new Historique(nom);

    QString Nom_afficher=Nom_Session;
    Nom_afficher.truncate(17);
    ui->Label_Bienvenue->setText("Bienvenue "+Nom_afficher+"!");

    //connexion des différents boutons avec les signaux qui vont bien :
    QObject::connect(ui->Bouton_Supprimer_Session,SIGNAL(clicked()),this,SLOT(Envoi_Signal_Supp_Session()));
    QObject::connect(ui->Bouton_Retour_Accueil,SIGNAL(clicked()),this,SLOT(Envoi_Signal_Retour_Acceuil()));
    QObject::connect(ui->Bouton_Stats,SIGNAL(clicked()),this,SLOT(Envoi_Signal_Fenetre_Stats()));
    QObject::connect(ui->Bouton_Calculate,SIGNAL(clicked()),this,SLOT(Envoi_Signal_Fenetre_Jeu_Calculate()));
    QObject::connect(ui->Bouton_Memorize,SIGNAL(clicked()),this,SLOT(Envoi_Signal_Fenetre_Jeu_Memorize()));
    QObject::connect(ui->Bouton_QuickShape,SIGNAL(clicked()),this,SLOT(Envoi_Signal_Fenetre_Jeu_QuickShape()));

    //Affichage dernière connexion
    ui->Derniere_Connexion->setText(_historique->get_Derniere_Connexion());

    //Ecriture date de connexion dans l'historique
    _historique->Ecrire("Connexion");
}

F_Session::~F_Session()
{
    delete ui;
}

void F_Session::Envoi_Signal_Supp_Session()
{
    emit Signal_Supp_Session(this->Nom_Session);
    _historique->~Historique();
}

void F_Session::Envoi_Signal_Retour_Acceuil()
{
    emit Signal_Retour_Acceuil();
}

void F_Session::Envoi_Signal_Fenetre_Stats()
{
    emit Signal_Fenetre_Stats(this->Nom_Session, _historique);
}

void F_Session::Envoi_Signal_Fenetre_Jeu_Calculate()
{
    emit Signal_Fenetre_Jeu(this->Nom_Session,"Calculate!",_historique);
}

void F_Session::Envoi_Signal_Fenetre_Jeu_Memorize()
{
    emit Signal_Fenetre_Jeu(this->Nom_Session,"Memorize!",_historique);
}

void F_Session::Envoi_Signal_Fenetre_Jeu_QuickShape()
{
    emit Signal_Fenetre_Jeu(this->Nom_Session,"QuickShape!",_historique);
}

QString F_Session::get_Nom_Session()
{
    return Nom_Session;
}
