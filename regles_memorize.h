#ifndef REGLES_MEMORIZE_H
#define REGLES_MEMORIZE_H

#include "regles.h"

#include <QVector>
#include <QList>

class Regles_Memorize : public Regles
{

public:
    Regles_Memorize();
    ~Regles_Memorize();

    void setINPUTS(int niveau) ;
    QVector<QString> getINPUTS() ;
    bool traiter_reponse(QVector<QString> reponse) ;

private:
    QVector<QString> *_INPUT;

    QVector<QString> *_CURRENT_INPUT;

};

#endif // REGLES_MEMORIZE_H
