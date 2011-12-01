#include "case_matrice.h"

#include <QPushButton>

Case_Matrice::Case_Matrice(int i,int j):QPushButton()
{
    _coordonnee_i=i;
    _coordonnee_j=j;
    setCursor(Qt::PointingHandCursor);

    QObject::connect(this,SIGNAL(clicked()),this,SLOT(Envoi_Signal_Coordonnees()));
}


void Case_Matrice::Envoi_Signal_Coordonnees()
{
    emit Signal_Coordonnees(_coordonnee_i,_coordonnee_j);
}
