#ifndef CONTROLLEUR_QUICKSHAPE_H
#define CONTROLLEUR_QUICKSHAPE_H

#include <controlleur.h>
#include <regles.h>
#include <jeu_ui_quickshape.h>

class Controlleur_Quickshape : public Controlleur
{
    Q_OBJECT

public:
    Controlleur_Quickshape(Regles *regles, Jeu_Ui_Quickshape *jeu_ui);
    Jeu_Ui_Quickshape* get_jeu_ui();


public slots:
    void init_game(int time);
    void next_step();
    void end_game();
    void chronometreMinus();
    void transferer_reponse(QVector<QString> reponse);

private :
    Jeu_Ui_Quickshape *_jeu_ui;
    QTimer *_timerSeconds;
    QTimer *_timerTotal;
    QTime _chronometre;
};

#endif // CONTROLLEUR_QUICKSHAPE_H
