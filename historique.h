#ifndef HISTORIQUE_H
#define HISTORIQUE_H

#include <QFile>
#include <QString>
#include <QStringList>

class Historique : public QFile
{
public:
    Historique(QString nom_session);
    void Ecrire(QString msg);
    QString get_Derniere_Connexion();
    QStringList get_Infos(QString nomJeu);
    QVector<double> get_Stats(QString nomJeu, QString mois);

    ~Historique();

private:
    QString _nom_fichier_txt;
};

#endif // HISTORIQUE_H
