#ifndef MATRICE_MEMORIZE_H
#define MATRICE_MEMORIZE_H

#include "QTableWidget"

class Matrice_Memorize: public QTableWidget
{
    Q_OBJECT

public:
    Matrice_Memorize(int niveau, QVector<QString> INPUT, bool a_memoriser);
    QVector<QString> Get_Reponse();

public slots:
    void Noircir_Cellule(int i, int j);

private:
    QVector<QString> _reponse;
};

#endif // MATRICE_MEMORIZE_H
