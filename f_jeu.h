#ifndef F_JEU_H
#define F_JEU_H

#include <QWidget>
#include <QTime>
#include <QTimer>
#include <controlleur.h>
#include <historique.h>

namespace Ui {
    class F_Jeu;
}

class F_Jeu : public QWidget
{
    Q_OBJECT

public:
    explicit F_Jeu(QString nomS, Controlleur *controlleur, Historique *hist, Jeu_Ui *jeu_ui);
    ~F_Jeu();

public slots:
    void Envoi_Signal_Retour_Session();
    void AfficherTimer(QTime timeRemaining);
    void AfficherScore(int score);
    void AfficherNiveau(int niveau);
    void AfficherEssais(int essai);
    void Fin_Jeu(int score);

signals:
    void Signal_Retour_Session();

private:
    Ui::F_Jeu *ui;
    Controlleur *_controlleur;
    QString _Nom_Session;
    QString _Nom_Jeu;
    QString _Descriptif_regles;
    Historique *_historique;
    QTimer *_duree_pouce;
    Jeu_Ui *_jeu_ui;

};

#endif // F_JEU_H
