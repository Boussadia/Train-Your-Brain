#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QString>
#include <QPushButton>
#include <f_accueil.h>
#include <f_session.h>
#include <f_jeu.h>

class MainWindow : public QWidget
{
    Q_OBJECT

    public:
        MainWindow(F_Accueil *fenetre);

    public slots:
        void Afficher_Fenetre_Session(QString Nom_Session);
        void Retour_Accueil();
        void Retour_Session_From_Stats();
        void Retour_Session_From_Game();
        void Supprimer_Session(QString Nom_Session);
        void Afficher_Fenetre_Jeu(QString Nom_Session, QString Nom_Jeu, Historique* hist);

    private:
        F_Accueil *Fenetre_Accueil;
        F_Session *Fenetre_Session;
        F_Jeu *Fenetre_Jeu;
};

#endif // MAINWINDOW_H
