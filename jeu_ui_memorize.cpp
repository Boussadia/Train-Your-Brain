#include "jeu_ui_memorize.h"

#include <QVector>
#include <QPushButton>
#include <QDebug>
#include <matrice_memorize.h>

Jeu_Ui_Memorize::Jeu_Ui_Memorize() : Jeu_Ui()
{
    //on initialise une matrice de départ
    _niveau=1;
    _Input = QVector<QString>(1,"0:0");
    _matrice = new Matrice_Memorize(_niveau,_Input,true);

    setFixedSize(440,280);

    //bouton valider pour envoyer la réponse
    QPushButton *Bouton_Valider = new QPushButton("Valider");
    Bouton_Valider->setParent(this);
    Bouton_Valider->setFont(QFont("MS Shell Dlg 2", 14,75));
    Bouton_Valider->setCursor(Qt::PointingHandCursor);
    Bouton_Valider->move(365, 247);
    Bouton_Valider->show();

    QObject::connect(Bouton_Valider,SIGNAL(clicked()),this,SLOT(emettre_reponse()));

    //bouton effacer :
    QPushButton *Bouton_Effacer = new QPushButton("Effacer");
    Bouton_Effacer->setParent(this);
    Bouton_Effacer->setFont(QFont("MS Shell Dlg 2", 10,50));
    Bouton_Effacer->setCursor(Qt::PointingHandCursor);
    Bouton_Effacer->move(365, 220);
    Bouton_Effacer->show();

    QObject::connect(Bouton_Effacer,SIGNAL(clicked()),this,SLOT(effacer_grille()));
}

void Jeu_Ui_Memorize::setCaracteristiques(int niveau, QVector<QString> INPUT)
{
    _niveau=niveau;
    _Input=INPUT;
}

void Jeu_Ui_Memorize::afficher_matrice(bool a_memoriser)
{
    delete _matrice;
    _matrice = new Matrice_Memorize(_niveau,_Input,a_memoriser);
    _matrice->setParent(this);

    //centrage de la grille dans la fenêtre...
    int dim_vert=_matrice->height();
    int dim_hori=_matrice->width();
    _matrice->move((440-dim_hori)/2,(280-dim_vert)/2);
    _matrice->show();
}

void Jeu_Ui_Memorize::emettre_reponse()
{
    emit reponse(_matrice->Get_Reponse());
}

void Jeu_Ui_Memorize::effacer_grille()
{
    afficher_matrice(false);
}

Jeu_Ui_Memorize::~Jeu_Ui_Memorize()
{
    delete _matrice;
}
