#include "controlleur_memorize.h"

#include <QWidget>
#include <QTimer>
#include <QDebug>
#include <jeu_ui_memorize.h>

Controlleur_Memorize::Controlleur_Memorize(Regles *regles, Jeu_Ui_Memorize *jeu_ui) : Controlleur(regles)
{
    _nom_jeu="Memorize!";
    _jeu_ui=jeu_ui;
}


Jeu_Ui_Memorize* Controlleur_Memorize::get_jeu_ui()
{
    return _jeu_ui;
}

void Controlleur_Memorize::init_game(int time)
{
    //init variables:
    _niveau=1;
    _score=0;
    _essais=10;

    emit changement_score(_score);
    emit changement_Niveau(_niveau);
    emit changement_Essais(_essais);

    //init rules
    QObject::connect(_jeu_ui,SIGNAL(reponse(QVector<QString>)),this,SLOT(transferer_reponse(QVector<QString>)));
    next_step();
}

void Controlleur_Memorize::next_step()
{
    _regles->setINPUTS(_niveau);

    _jeu_ui->setCaracteristiques(_niveau,_regles->getINPUTS());

    QTimer *Timer_Memoire = new QTimer(this);
    Timer_Memoire->setSingleShot(true);
    QObject::connect(Timer_Memoire,SIGNAL(timeout()),this,SLOT(Afficher_Matrice_Reponse()));

    //On afficher tout d'abord la matrice à mémoriser pendant 1,5s
    _jeu_ui->afficher_matrice(true);
    Timer_Memoire->start(1500);
}

void Controlleur_Memorize::end_game()
{
    emit Signal_Score_final(_score);
}

Controlleur_Memorize::~Controlleur_Memorize()
{
}

void Controlleur_Memorize::transferer_reponse(QVector<QString> reponse)
{
    bool resultat=_regles->traiter_reponse(reponse);
    if (resultat)
    {
        _score=_score+_niveau;
        emit changement_score(_score);
        if (_niveau!=8)
        {
            _niveau++;
            emit changement_Niveau(_niveau);
        }
    }
    else
    {
        if (_niveau!=1)
        {
            _niveau--;
            emit changement_Niveau(_niveau);
        }
    }

    _essais--;
    emit changement_Essais(_essais);

    if (_essais != 0)
        next_step();
    else
        end_game();
}

void Controlleur_Memorize::Afficher_Matrice_Reponse()
{
    _jeu_ui->afficher_matrice(false);
}
