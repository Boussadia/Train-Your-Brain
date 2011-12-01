#include "controlleur.h"
#include "regles.h"
#include "jeu_ui_calculate.h"

Controlleur::Controlleur(Regles *regles): QObject()
{
    _regles=regles;
}

QString Controlleur::get_nom_jeu ()
{
    return _nom_jeu;
}

Controlleur::~Controlleur()
{
}
