#include "regles_quickshape.h"
#include <cstdlib>
#include <ctime>
#include <QtGui>
#include <vector>
#include <string>


Regles_Quickshape::Regles_Quickshape()
{
    _INPUT_PICT_ = new QVector<QString>; // Vector des string des adresses des images sources
    _INPUT_PICT_->push_back("images_quickshape/Croix.png");  // Vector de taille 3 avec au choix 3 images
    _INPUT_PICT_->push_back("images_quickshape/Rond_creux.png");
    _INPUT_PICT_->push_back("images_quickshape/Rond_creux_plein.png");
    _INPUT_PICT_->push_back("images_quickshape/Rond_plein.png");
    _INPUT_PICT_->push_back("images_quickshape/Roue.png");

    _currentPICT_=0;
}

Regles_Quickshape::~Regles_Quickshape()
{
    delete _INPUT_PICT_; // Destruction
}

QVector<QString> Regles_Quickshape::getINPUTS()
{
    QVector<QString> rulesInputs(1);

    rulesInputs[0] = QString(_INPUT_PICT_->at(_currentPICT_));
    return rulesInputs;
}

void Regles_Quickshape::setINPUTS(int niveau)
{
    srand(time(NULL)); // ne surtout pas initialiser _currentPICT_ sinon on efface le résultat précédent
    _previousPICT_=_currentPICT_; // affectation de previous pour stockage

    int rep = rand()%3; //on choisit al�atoirement si la r�ponse sera vraie (rep=0) ou non (le reste) ce qui laisse une chance sur 3
    if (rep!=0)
        _currentPICT_=rand()%(_INPUT_PICT_->size());
}


bool Regles_Quickshape::traiter_reponse(QVector<QString> reponse)
{
    bool output;
    bool acceptance; // reponse "YES" ou "NO"

    if(_previousPICT_==_currentPICT_)
    {
        output = true; // il faudra changer ici car l'int n'est plus approprié 1=YES
    }
    else if(_previousPICT_!=_currentPICT_)
    {
        output = false;  // il faudra changer ici car l'int n'est plus approprié 1=NO ca marche
    }


    if((reponse[0] == "YES") && (output == true))
    {
        acceptance = true; // bonne réponse
    }
    else if((reponse[0] == "NO") && (output == false))
    {
        acceptance = true;  // bonne réponse
    }
    else
    {
        acceptance = false;  // mauvaise réponse
    }

    return acceptance;
}
