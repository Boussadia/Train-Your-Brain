#include "controlleur_quickshape.h"
#include "controlleur.h"
#include "regles_quickshape.h"
#include "jeu_ui_quickshape.h"

#include <QDebug>

Controlleur_Quickshape::Controlleur_Quickshape(Regles *regles, Jeu_Ui_Quickshape *jeu_ui): Controlleur(regles)
{
    _nom_jeu="QuickShape!";
    _jeu_ui=jeu_ui;
}

void Controlleur_Quickshape::init_game(int time)
{
    //init Time
    _timerSeconds = new QTimer(this);
    _chronometre = QTime(0,0,0,0);
    _chronometre = _chronometre.addSecs(time);
    emit changement_timer(_chronometre);
    _timerTotal = new QTimer(this);
    QObject::connect(_timerSeconds,SIGNAL(timeout()),this,SLOT(chronometreMinus()));
    QObject::connect(_timerTotal,SIGNAL(timeout()),this, SLOT(end_game()));
    _timerSeconds->start(1000);
    _timerTotal->start(time*1000);

    //Init Score
    _score=0;

    //Init Rules
    QObject::connect(_jeu_ui,SIGNAL(reponse(QVector<QString>)),this,SLOT(transferer_reponse(QVector<QString>)));
    //La première image doit passer sans avoir à cliquer donc on lance le jeu ici :
    //On a initialisé les règles et le jeu_ui de la même manière..

    QTimer *Timer_init = new QTimer(this);
    Timer_init->setSingleShot(true);
    QObject::connect(Timer_init,SIGNAL(timeout()),this,SLOT(next_step()));
    Timer_init->start(1300);
}


void Controlleur_Quickshape::next_step()
{
    _regles->setINPUTS();
    _jeu_ui->setPict(_regles->getINPUTS().at(0));
}

void Controlleur_Quickshape::end_game()
{
    _timerSeconds->stop();
    _timerTotal->stop();
    emit Signal_Score_final(_score);
}

void Controlleur_Quickshape::chronometreMinus()
{
    _chronometre=_chronometre.addSecs(-1);
    emit changement_timer(_chronometre);
}

Jeu_Ui_Quickshape* Controlleur_Quickshape::get_jeu_ui()
{
    return _jeu_ui;
}

void Controlleur_Quickshape::transferer_reponse(QVector<QString> reponse)
{
    bool resultat=_regles->traiter_reponse(reponse);
    if (resultat)
    {
        _score++;
        emit changement_score(_score);
    }

    next_step();
}
