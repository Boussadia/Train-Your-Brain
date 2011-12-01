#ifndef F_STATS_H
#define F_STATS_H

#include <QWidget>
#include <historique.h>
#include <graphe.h>

namespace Ui {
    class F_Stats;
}

class F_Stats : public QWidget
{
    Q_OBJECT

public:
    explicit F_Stats(QString nom, Historique *historique);
    ~F_Stats();
    Historique Get_Historique();
    void Afficher_stats();

public slots:
    void Envoi_Signal_Retour_Session();
    void Rafraichir_graphe(QString mois);
    void Afficher_Stats_Suiv();
    void Afficher_Stats_Prec();

signals:
    void Signal_Retour_Session();

private:
    Ui::F_Stats *ui;
    QString _Nom_Session;
    Graphe* _graphe;
    Historique *_historique;
    QStringList _liste_nom_jeu;
    int _index_jeu;
};

#endif // F_STATS_H
