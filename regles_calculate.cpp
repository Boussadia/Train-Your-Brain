#include "regles_calculate.h"
#include <cstdlib>
#include <ctime>

Regles_Calculate::Regles_Calculate() : Regles(), _currentINPUT_1_(0), _currentINPUT_2_(0), _currentOPERATOR_ (0)
{
    _INPUT_1_ = new QVector<int>;
    _INPUT_2_ = new QVector<int>;
    _OPERATOR_ = new QVector<QString>;

    for(int i=1; i<10; i++)
    {
        _INPUT_1_->push_back(i);
        _INPUT_2_->push_back(i);
    }

    _OPERATOR_->push_back("+");
    _OPERATOR_->push_back("*");
    _OPERATOR_->push_back("-");
}

Regles_Calculate::~Regles_Calculate(){
    delete _INPUT_1_;
    delete _INPUT_2_;
    delete _OPERATOR_;
}

QVector<QString> Regles_Calculate::getINPUTS()
{
    QVector<QString> rulesInputs(3);

    //converting int to QString
    QString number1 (QString::number(_INPUT_1_->at(_currentINPUT_1_)));
    QString number2 (QString::number(_INPUT_2_->at(_currentINPUT_2_)));

    rulesInputs[0] = number1;
    rulesInputs[1] = QString(_OPERATOR_->at(_currentOPERATOR_));
    rulesInputs[2] = number2;


    return rulesInputs;
}

void Regles_Calculate::setINPUTS(int niveau)
{
    _currentINPUT_1_ = 0;
    _currentINPUT_2_ = 0;
    _currentOPERATOR_ = 0;
    srand(time(NULL));
    _currentINPUT_1_ = rand()%_INPUT_1_->size();
    _currentINPUT_2_ = rand()%_INPUT_2_->size();
    _currentOPERATOR_ = rand()%_OPERATOR_->size();

}

bool Regles_Calculate::traiter_reponse(QVector<QString> reponse)
{
    int output(1);
    bool acceptance;

    int number1 = _INPUT_1_->at(_currentINPUT_1_);
    int number2 = _INPUT_2_->at(_currentINPUT_2_);

    QString ruleOperator = _OPERATOR_->at(_currentOPERATOR_);

    if(ruleOperator == "+"){
        output = number1 + number2;
    }
    else if(ruleOperator == "-")
    {
        output = number1 - number2;
    }
    else if(ruleOperator == "*")
    {
        output = number1 * number2;
    }

    if (reponse.value(0) == QString::number(output))
        acceptance=true;
    else
        acceptance=false;

    return acceptance;
}
