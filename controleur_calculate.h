#ifndef CONTROLEUR_CALCULATE_H
#define CONTROLEUR_CALCULATE_H

#include <controlleur.h>
#include <regles.h>
#include <jeu_ui_calculate.h>

class Controleur_Calculate : public Controlleur
{
    Q_OBJECT

public:
    Controleur_Calculate(Regles *regles, Jeu_Ui_Calculate *jeu_ui);
    Jeu_Ui_Calculate* get_jeu_ui();


public slots:
    void init_game(int time);
    void next_step();
    void end_game();
    void chronometreMinus();
    void transferer_reponse(QVector<QString> reponse);

private :
    Jeu_Ui_Calculate *_jeu_ui;
    QTimer *_timerSeconds;
    QTimer *_timerTotal;
    QTime _chronometre;
};

#endif // CONTROLEUR_CALCULATE_H
