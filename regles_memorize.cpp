#include "regles_memorize.h"
#include <ctime>

#include <QVector>
#include <QDebug>

Regles_Memorize::Regles_Memorize():Regles()
{
    _INPUT = new QVector<QString>;
    _CURRENT_INPUT = new QVector<QString>;
}

void Regles_Memorize::setINPUTS(int niveau)
{
    int nb_cases=niveau+2;

    int nb_colonnes=0;
    int nb_lignes=0;

    switch(niveau)
    {
    case 1:
        nb_colonnes=3;
        nb_lignes=3;
        break;
    case 2:
        nb_colonnes=3;
        nb_lignes=4;
        break;
    case 3:
        nb_colonnes=4;
        nb_lignes=4;
        break;
    case 4:
        nb_colonnes=5;
        nb_lignes=4;
        break;
    case 5:
        nb_colonnes=5;
        nb_lignes=5;
        break;
    case 6:
        nb_colonnes=6;
        nb_lignes=5;
        break;
    case 7:
        nb_colonnes=6;
        nb_lignes=6;
        break;
    case 8:
        nb_colonnes=7;
        nb_lignes=6;
        break;
    }

    //construction des couples str i:j possibles pour CURRENT_INPUT
    _INPUT->clear();
    for (int i=0;i<nb_lignes;i++)
    {
        for (int j=0;j<nb_colonnes;j++)
        {
            QString couple=QString::number(i)+":"+QString::number(j);
            _INPUT->push_back(couple);
        }
    }

    //On set l'INPUT :
    _CURRENT_INPUT->clear();
    for (int c=0;c<nb_cases;c++)
    {
        srand(time(NULL));
        int indice_tirage = rand()%_INPUT->size();
        _CURRENT_INPUT->push_back(_INPUT->value(indice_tirage));
        _INPUT->remove(indice_tirage);
    }
}

QVector<QString> Regles_Memorize::getINPUTS()
{
    return *_CURRENT_INPUT;
}

bool Regles_Memorize::traiter_reponse(QVector<QString> reponse)
{
    bool acceptance=true;
    int N=_CURRENT_INPUT->size();

    if (reponse.size()!=N)
        acceptance=false;
    else
    {
        for (int i=0;i<N;i++)
            if (!_CURRENT_INPUT->contains(reponse.value(i)))
                acceptance=false;
    }

    return acceptance;
}

Regles_Memorize::~Regles_Memorize()
{
    delete _INPUT;
    delete _CURRENT_INPUT;
}
