
#include "controleur_calculate.h"
#include "controlleur.h"
#include "regles_calculate.h"
#include "jeu_ui_calculate.h"

Controleur_Calculate::Controleur_Calculate(Regles *regles, Jeu_Ui_Calculate *jeu_ui): Controlleur(regles)
{
    _nom_jeu="Calculate!";
    _jeu_ui=jeu_ui;
}

void Controleur_Calculate::init_game(int time)
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
    next_step();
}

void Controleur_Calculate::next_step()
{
    _regles->setINPUTS();
    _jeu_ui->setNumber1(_regles->getINPUTS().at(0).toInt());
    _jeu_ui->setNumber2(_regles->getINPUTS().at(2).toInt());
    _jeu_ui->setOperation(_regles->getINPUTS().at(1));
}

void Controleur_Calculate::end_game()
{
    _timerSeconds->stop();
    _timerTotal->stop();
    emit Signal_Score_final(_score);
}

void Controleur_Calculate::chronometreMinus()
{
    _chronometre=_chronometre.addSecs(-1);
    emit changement_timer(_chronometre);
}

Jeu_Ui_Calculate* Controleur_Calculate::get_jeu_ui()
{
    return _jeu_ui;
}

void Controleur_Calculate::transferer_reponse(QVector<QString> reponse)
{
    bool resultat=_regles->traiter_reponse(reponse);
    if (resultat)
    {
        _score++;
        emit changement_score(_score);
    }

    next_step();
}
