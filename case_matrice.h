#ifndef CASE_MATRICE_H
#define CASE_MATRICE_H

#include <QPushButton>

class Case_Matrice : public QPushButton
{
    Q_OBJECT

public:
    Case_Matrice(int i, int j);

public slots:
    void Envoi_Signal_Coordonnees();

signals:
    void Signal_Coordonnees(int i,int j);

private:
    int _coordonnee_i;
    int _coordonnee_j;
};

#endif // CASE_MATRICE_H
