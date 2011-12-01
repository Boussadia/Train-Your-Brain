#ifndef GRAPHE_H
#define GRAPHE_H

#include <QString>
#include <qwt_plot.h>

#include <historique.h>

class Graphe: public QwtPlot
{
public:
    Graphe(Historique *historique, QString nomJ, QString mois);

private:
    QString _nom_jeu;
    QString _mois;
};

#endif // GRAPHE_H
