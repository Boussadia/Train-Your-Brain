#ifndef CONTROLLEUR_MEMORIZE_H
#define CONTROLLEUR_MEMORIZE_H

#include <controlleur.h>
#include "jeu_ui_memorize.h"

class Controlleur_Memorize : public Controlleur
{
    Q_OBJECT

public:
    Controlleur_Memorize(Regles *regles, Jeu_Ui_Memorize *jeu_ui);
    Jeu_Ui_Memorize* get_jeu_ui();
    ~Controlleur_Memorize();

public slots:
    void init_game(int time=0);
    void next_step();
    void end_game();
    void transferer_reponse(QVector<QString> reponse);
    void Afficher_Matrice_Reponse();

private:
    Jeu_Ui_Memorize *_jeu_ui;
    int _essais;
};

#endif // CONTROLLEUR_MEMORIZE_H
