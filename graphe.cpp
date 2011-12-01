#include "graphe.h"

#include <QString>
#include <QVector>
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_valuelist.h>
#include <QDebug>
#include <QPen>

Graphe::Graphe(Historique *historique, QString nomJ, QString mois): QwtPlot()
{
    _nom_jeu=nomJ;
    _mois=mois;

    QwtPlotCurve *curve1 = new QwtPlotCurve("Curve 1");

    QVector<double> ordonnees=historique->get_Stats(nomJ,mois);
    QVector<double> abscisses;

    for (double i = 1; i <= 31;i++)
    {
        abscisses.append(i);
    }


    curve1->setData(abscisses,ordonnees);
    QPen pen;
    pen.setWidth(2);

    curve1->setPen(pen);

    curve1->attach(this);

    this->setAxisScale(QwtPlot::yLeft,0,50,9);
    this->setAxisScale(QwtPlot::xBottom,0,31,3);

    //Nom des axes :
    QwtText titre_Ax("Jour du Mois");
    QwtText titre_Ay("Score");
    titre_Ax.setFont(QFont("MS Shell Dlg 2", 11,50));
    titre_Ay.setFont(QFont("MS Shell Dlg 2", 14,75));

    this->setAxisTitle(QwtPlot::yLeft,titre_Ay);
    this->setAxisTitle(QwtPlot::xBottom,titre_Ax);

    this->replot();

}
