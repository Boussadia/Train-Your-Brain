#include "f_stats.h"
#include "ui_f_stats.h"
#include "historique.h"
#include "graphe.h"

#include <QString>
#include <QStringList>
#include <QDebug>


F_Stats::F_Stats(QString nom, Historique* historique) :
    QWidget(),
    ui(new Ui::F_Stats)
{
    ui->setupUi(this);

    _historique=historique;
    _Nom_Session=nom;
    ui->Nom_Session->setText(_Nom_Session);

    QObject::connect(ui->Bouton_Retour_Session2,SIGNAL(clicked()),SLOT(Envoi_Signal_Retour_Session()));

    _liste_nom_jeu << "Calculate!" << "Memorize!" << "QuickShape!" ;
    _index_jeu=0;
    Afficher_stats();

    //on connecte le signal issu du menu déroulant afin de pouvoir changer le mois d'analyse:
    QObject::connect(ui->Choix_Mois,SIGNAL(activated(QString)),this,SLOT(Rafraichir_graphe(QString)));

    //on connecte les boutons exercice suivant et exercice précédent :
    QObject::connect(ui->Suivant_Bouton,SIGNAL(clicked()),this,SLOT(Afficher_Stats_Suiv()));
    QObject::connect(ui->Precedent_Bouton,SIGNAL(clicked()),this,SLOT(Afficher_Stats_Prec()));
}

F_Stats::~F_Stats()
{
    delete ui;
}

void F_Stats::Envoi_Signal_Retour_Session()
{
    emit Signal_Retour_Session();
}

void F_Stats::Afficher_stats()
{
    //Gestion de l'affichage des boutons suivant / précédent
    if (_index_jeu==0)
        ui->Precedent_Bouton->hide();
    else if (_index_jeu==_liste_nom_jeu.size()-1)
        ui->Suivant_Bouton->hide();
    else
    {
        ui->Suivant_Bouton->show();
        ui->Precedent_Bouton->show();
    }

    //Affichage des Stats demandées :
    ui->Nom_Jeu->setText(_liste_nom_jeu[_index_jeu]);
    QStringList Infos= _historique->get_Infos(_liste_nom_jeu[_index_jeu]);

    QString meilleur_score=Infos.value(0);
    ui->Meilleur_Score->setText(meilleur_score);

    QString str_mois=Infos.value(1);
    QStringList liste_mois=str_mois.split("/");
    ui->Choix_Mois->clear();
    foreach (QString mois, liste_mois)
        ui->Choix_Mois->addItem(mois);

    _graphe = new Graphe(_historique,_liste_nom_jeu[_index_jeu],liste_mois[0]);
    _graphe->setParent(ui->zone_graphe);
    _graphe->show();
}

void F_Stats::Rafraichir_graphe(QString mois)
{
    QString nomJ = this->ui->Nom_Jeu->text();

    this->_graphe = new Graphe(_historique,nomJ,mois);
    _graphe->setParent(ui->zone_graphe);
    _graphe->show();
}

void F_Stats::Afficher_Stats_Suiv()
{
    _index_jeu++;
    Afficher_stats();
}

void F_Stats::Afficher_Stats_Prec()
{
    _index_jeu--;
    Afficher_stats();
}
