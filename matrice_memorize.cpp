#include "matrice_memorize.h"
#include "case_matrice.h"

#include <QVector>
#include <QTableWidget>
#include <QPushButton>
#include <QHeaderView>
#include <QBrush>
#include <QDebug>


Matrice_Memorize::Matrice_Memorize(int niveau, QVector<QString> INPUT, bool a_memoriser):QTableWidget()
{        
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

    setColumnCount(nb_colonnes);
    setRowCount(nb_lignes);

    for(int i=0;i<nb_lignes;i++)
    {
        setRowHeight(i,40);
        for(int j=0;j<nb_colonnes;j++)
        {
            setColumnWidth(j,40);
            Case_Matrice *case_matrice = new Case_Matrice(i,j);
            setCellWidget(i,j,case_matrice);

            if (a_memoriser)
            {
                QString couple=QString::number(i)+":"+QString::number(j);
                if (INPUT.contains(couple))
                    this->cellWidget(i,j)->setStyleSheet("background-color: black;");
            }
            else
                QObject::connect(case_matrice,SIGNAL(Signal_Coordonnees(int,int)),this,SLOT(Noircir_Cellule(int,int)));
        }
    }

    setFixedSize(40.7*nb_colonnes,40.7*nb_lignes);
    verticalHeader()->setVisible(false);
    horizontalHeader()->setVisible(false);
}

void Matrice_Memorize::Noircir_Cellule(int i, int j)
{
    this->cellWidget(i,j)->setStyleSheet("background-color: black;");
    QString couple = QString::number(i)+":"+QString::number(j);
    _reponse.push_back(couple);
}

QVector<QString> Matrice_Memorize::Get_Reponse()
{
    return _reponse;
}

