#include "MainWindow.h"
#include "f_accueil.h"
#include "f_session.h"
#include "f_stats.h"
#include "f_jeu.h"
#include "jeu_ui_calculate.h"
#include "jeu_ui_memorize.h"
#include "jeu_ui_quickshape.h"
#include "regles_calculate.h"
#include "regles_memorize.h"
#include "regles_quickshape.h"
#include "controleur_calculate.h"
#include "controlleur_memorize.h"
#include "controlleur_quickshape.h"
#include "historique.h"

#include <QWidget>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>


MainWindow::MainWindow(F_Accueil *fenetre) : QWidget()
{
    setFixedSize(730, 480);

    //insertion du bouton Quitter :
    QPushButton *Quitter_Bouton = new QPushButton("Non Merci, mon QI est déjà trop élevé...",this);
    Quitter_Bouton->setFont(QFont("MS Shell Dlg 2", 9));
    Quitter_Bouton->setCursor(Qt::PointingHandCursor);
    Quitter_Bouton->move(480, 440);
    Quitter_Bouton->show();

    QObject::connect(Quitter_Bouton, SIGNAL(clicked()), this, SLOT(close()));

    //On attache la fenêtre d'accueil à la fenêtre générale
    fenetre->setParent(this);
    fenetre->move(0,0);
    Fenetre_Accueil=fenetre;
    Fenetre_Accueil->show();

    //Ici on connecte le signal Ouvrir Session au Slot qui fera apparaitre la fenêtre session
    QObject::connect(Fenetre_Accueil,SIGNAL(Signal_Ouvrir_Session(QString)),this,SLOT(Afficher_Fenetre_Session(QString)));
}

void MainWindow::Afficher_Fenetre_Session(QString Nom_Session)
{
    //on instancie dans un premier temps la fenetre session :
    F_Session *fenetre = new F_Session(Nom_Session);
    fenetre->setParent(this);
    fenetre->move(0,0);
    Fenetre_Session=fenetre;

    //on cache la fenetre accueil et on affiche la fenetre session...:
    Fenetre_Accueil->hide();
    Fenetre_Session->show();

    //on connecte les signaux venant de f_session aux slots de mainwindow.
    QObject::connect(Fenetre_Session,SIGNAL(Signal_Supp_Session(QString)),this,SLOT(Supprimer_Session(QString)));
    QObject::connect(Fenetre_Session,SIGNAL(Signal_Retour_Acceuil()),this,SLOT(Retour_Accueil()));

    QObject::connect(Fenetre_Session,SIGNAL(Signal_Fenetre_Stats(QString,Historique*)),this,SLOT(Afficher_Fenetre_Stats(QString,Historique*)));
    QObject::connect(Fenetre_Session,SIGNAL(Signal_Fenetre_Jeu(QString,QString,Historique*)),this,SLOT(Afficher_Fenetre_Jeu(QString,QString,Historique*)));

}

void MainWindow::Afficher_Fenetre_Stats(QString Nom_Session, Historique* hist)
{
    //on instancie dans un premier temps la fenetre stats :
    F_Stats *nll_fenetre_stats = new F_Stats(Nom_Session, hist);
    nll_fenetre_stats->setParent(this);
    nll_fenetre_stats->move(0,0);
    Fenetre_Stats=nll_fenetre_stats;

    //on cache la fenetre session et on affiche la fenetre stats...:
    Fenetre_Session->hide();
    Fenetre_Stats->show();

    QObject::connect(Fenetre_Stats,SIGNAL(Signal_Retour_Session()),this,SLOT(Retour_Session_From_Stats()));
}

void MainWindow::Afficher_Fenetre_Jeu(QString nomS, QString nomJ, Historique* hist)
{
    if (nomJ == "Calculate!")
    {
        Jeu_Ui_Calculate *jeu_ui= new Jeu_Ui_Calculate ();
        Regles_Calculate *regles = new Regles_Calculate();
        Controleur_Calculate *controlleur = new Controleur_Calculate(regles,jeu_ui);

        F_Jeu *nll_fenetre_jeu = new F_Jeu(nomS,controlleur,hist,jeu_ui);
        nll_fenetre_jeu->setParent(this);
        nll_fenetre_jeu->move(0,0);
        Fenetre_Jeu=nll_fenetre_jeu;
    }
    else if (nomJ == "Memorize!")
    {
        Jeu_Ui_Memorize *jeu_ui= new Jeu_Ui_Memorize ();
        Regles_Memorize *regles = new Regles_Memorize();
        Controlleur_Memorize *controlleur = new Controlleur_Memorize(regles,jeu_ui);

        F_Jeu *nll_fenetre_jeu = new F_Jeu(nomS,controlleur,hist,jeu_ui);
        nll_fenetre_jeu->setParent(this);
        nll_fenetre_jeu->move(0,0);
        Fenetre_Jeu=nll_fenetre_jeu;
    }

    else if (nomJ == "QuickShape!")
    {
        Jeu_Ui_Quickshape *jeu_ui= new Jeu_Ui_Quickshape ();
        Regles_Quickshape *regles = new Regles_Quickshape();
        Controlleur_Quickshape *controlleur = new Controlleur_Quickshape(regles,jeu_ui);

        F_Jeu *nll_fenetre_jeu = new F_Jeu(nomS,controlleur,hist,jeu_ui);
        nll_fenetre_jeu->setParent(this);
        nll_fenetre_jeu->move(0,0);
        Fenetre_Jeu=nll_fenetre_jeu;
    }

    //on cache la fenetre session et on affiche la fenetre jeu...:
    Fenetre_Session->hide();
    Fenetre_Jeu->show();

    QObject::connect(Fenetre_Jeu,SIGNAL(Signal_Retour_Session()),this,SLOT(Retour_Session_From_Game()));
}

void MainWindow::Retour_Accueil()
{
        Fenetre_Session->hide();
        Fenetre_Accueil->show();
}

void MainWindow::Retour_Session_From_Stats()
{

        Fenetre_Stats->hide();
        Fenetre_Session->show();
}

void MainWindow::Retour_Session_From_Game()
{
        Fenetre_Jeu->hide();
        Fenetre_Session->show();
}

void MainWindow::Supprimer_Session(QString Nom_Session)
{
    int reponse = QMessageBox::question(this, "Vraiment?", "Etes-vous sûr de vouloir supprimer la session "+Nom_Session+" ?", QMessageBox::Yes | QMessageBox::No);
    if (reponse == QMessageBox::Yes)
    {
        //toute la philosophie est de ne modifier que le fichier liste_session et de réinstancier le paramètre F_Accueil !

        QFile *fichier = Fenetre_Accueil->get_Liste_Sessions();
        fichier->open(QIODevice::ReadWrite | QIODevice::Text);
        QTextStream flux(fichier);
        QString contenu;

        while (!flux.atEnd())
        {
            QString ligne=flux.readLine();
            if (ligne!=Nom_Session)
                contenu=contenu.append(ligne+"\n");
        }

        fichier->resize(0);

        fichier->write(contenu.toLatin1(),contenu.size());
        fichier->close();

        F_Accueil *Nlle_fenetre = new F_Accueil;
        Nlle_fenetre->setParent(this);
        Nlle_fenetre->move(0,0);
        Fenetre_Accueil=Nlle_fenetre;
        QObject::connect(Fenetre_Accueil,SIGNAL(Signal_Ouvrir_Session(QString)),this,SLOT(Afficher_Fenetre_Session(QString)));

        Retour_Accueil();
    }

}
