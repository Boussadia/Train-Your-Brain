#include "jeu_ui_calculate.h"
#include "ui_jeu_ui_calculate.h"

Jeu_Ui_Calculate::Jeu_Ui_Calculate() :
    Jeu_Ui(),
    ui(new Ui::Jeu_Ui_Calculate)
{
    ui->setupUi(this);

    // Initialisation des attributs de la classe
    m_answerField = ui->AswerField;
    QObject::connect(m_answerField,SIGNAL(editingFinished()),this,SLOT(emettre_reponse()));

    m_number1 = ui->Number1;
    m_number2 = ui->Number2;
    m_operation = ui->Operation;

}

Jeu_Ui_Calculate::~Jeu_Ui_Calculate()
{
    delete ui;
}


void Jeu_Ui_Calculate::setNumber1(int number){
m_number1->setText( QString::number(number) );
}

void Jeu_Ui_Calculate::setNumber2(int number){
m_number2->setText( QString::number(number) );
}

void Jeu_Ui_Calculate::setOperation(QString operation){
m_operation->setText( operation );
}


void Jeu_Ui_Calculate::emettre_reponse()
{
    QVector<QString> vect_reponse;
    vect_reponse.append(this->m_answerField->text());
    emit reponse(vect_reponse);
    m_answerField->clear();
}
