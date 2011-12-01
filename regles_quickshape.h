#ifndef REGLES_QUICKSHAPE_H
#define REGLES_QUICKSHAPE_H

#include <regles.h>
#include <QVector>
#include <QString>

class Regles_Quickshape : public Regles
{
public:
    Regles_Quickshape();
    ~Regles_Quickshape();

    void setINPUTS(int niveau) ;
    QVector<QString> getINPUTS() ;
    bool traiter_reponse(QVector<QString> reponse) ;

private:
    vector<string> *_OPERATOR_;
    QVector<QString> *_INPUT_PICT_;

    int _currentPICT_;
    int _previousPICT_;
};

#endif // REGLES_QUICKSHAPE_H
