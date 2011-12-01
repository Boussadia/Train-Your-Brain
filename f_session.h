#ifndef F_SESSION_H
#define F_SESSION_H

#include <QWidget>
#include <QString>
#include <historique.h>

namespace Ui {
    class F_Session;
}

class F_Session : public QWidget
{
    Q_OBJECT

public:
    F_Session(QString nom);
    ~F_Session();
    QString get_Nom_Session();


public slots:
    void Envoi_Signal_Supp_Session();
    void Envoi_Signal_Retour_Acceuil();
    void Envoi_Signal_Fenetre_Stats();
    void Envoi_Signal_Fenetre_Jeu_Calculate();
    void Envoi_Signal_Fenetre_Jeu_Memorize();
    void Envoi_Signal_Fenetre_Jeu_QuickShape();

signals:
    void Signal_Supp_Session(QString nom);
    void Signal_Retour_Acceuil();
    void Signal_Fenetre_Stats(QString nom, Historique* historique);
    void Signal_Fenetre_Jeu(QString nomS, QString nomJ,Historique* hist);

private:
    Ui::F_Session *ui;
    QString Nom_Session;
    Historique *_historique;
};

#endif // F_SESSION_H
