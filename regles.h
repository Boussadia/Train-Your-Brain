#ifndef REGLES_H
#define REGLES_H

#include <QVector>
#include <QObject>
#include <QString>

using namespace std;

class Regles
{

public:
    Regles();

    virtual void setINPUTS(int niveau=0) =0;
    virtual QVector<QString> getINPUTS() =0;
    virtual bool traiter_reponse(QVector<QString> reponse) =0;
};

#endif // REGLES_H
