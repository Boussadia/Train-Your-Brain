#ifndef REGLES_CALCULATE_H
#define REGLES_CALCULATE_H

#include <regles.h>
#include <QVector>
#include <QString>


class Regles_Calculate : public Regles
{

public:
    Regles_Calculate();
    ~Regles_Calculate();

    void setINPUTS(int niveau) ;
    QVector<QString> getINPUTS() ;
    bool traiter_reponse(QVector<QString> reponse) ;

private:
    QVector<int> *_INPUT_1_ ;
    QVector<QString> *_OPERATOR_;
    QVector<int> *_INPUT_2_;

    int _currentINPUT_1_;
    int _currentINPUT_2_;
    int _currentOPERATOR_;
};

#endif // REGLES_CALCULATE_H
