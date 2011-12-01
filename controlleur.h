#ifndef CONTROLLEUR_H
#define CONTROLLEUR_H

#include <QObject>
#include <QString>
#include <QTime>
#include <QTimer>

#include <regles.h>
#include <jeu_ui_calculate.h>

class Controlleur : public QObject
{
    Q_OBJECT

protected:
    QString _nom_jeu;
    Regles *_regles;
    int _score;
    int _niveau;

public:
    Controlleur(Regles *regles);
    QString get_nom_jeu ();
    ~Controlleur();

public slots:
    virtual void transferer_reponse(QVector<QString> reponse)=0;
    virtual void init_game(int time)=0;
    virtual void next_step()=0;
    virtual void end_game()=0;

signals:
    void changement_score(int score);
    void changement_timer(QTime chronometre);
    void changement_Niveau(int niveau);
    void changement_Essais(int);
    void Signal_Score_final(int score);
};

#endif // CONTROLLEUR_H
