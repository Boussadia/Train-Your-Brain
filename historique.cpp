#include "historique.h"

#include <QString>
#include <QStringList>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QDebug>
#include <QList>
#include <QVector>

Historique::Historique(QString nom_session) : QFile()
{
    _nom_fichier_txt=nom_session + ".txt";
    this->setFileName(_nom_fichier_txt);
}


void Historique::Ecrire(QString msg)
{
    this->open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Append);
    QDateTime date_heure = QDateTime::currentDateTime();
    QString ligne_hist=date_heure.toString()+"/"+msg+"\n";
    this->write(ligne_hist.toLatin1(),ligne_hist.size());
    this->close();
}

QString Historique::get_Derniere_Connexion()
{

    if(this->size()!=0)
    {
        this->open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream flux(this);
        QDateTime derniere_connexion;

        while (!flux.atEnd())
        {
            QString ligne=flux.readLine();
            if (ligne.contains("Connexion"))
            {
               QStringList liste_ligne=ligne.split("/");
               derniere_connexion = QDateTime::fromString(liste_ligne.value(0));
            }
        }

        this->close();

        QString derniere_connexion_str = derniere_connexion.toString("dd/MM/yyyy");
        return "Dernière Connexion : " + derniere_connexion_str;
    }
    else
    {
        return "Première Connexion!";
    }
}

QStringList Historique::get_Infos(QString nomJeu)
//ramène le meilleur score et la liste des mois où l'utilisateur a joué au jeu
{
    QStringList Resultat;

    this->open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream flux(this);

    QDateTime date;
    QString mois;
    QString liste_mois="";
    int score;
    int meilleur_score=0;

    while (!flux.atEnd())
    {
        QString ligne=flux.readLine();
        if (ligne.contains(nomJeu))
        {
           QStringList liste_ligne=ligne.split("/");
           date=QDateTime::fromString(liste_ligne.value(0));
           mois=date.toString("MMMM yyyy");
           score=liste_ligne.value(2).toInt();
           if (score > meilleur_score)
               meilleur_score=score;
           if (!liste_mois.contains(mois))
           {
               if (liste_mois=="")
                   liste_mois=mois;
               else
                   liste_mois+="/"+mois;
           }
        }
    }

    this->close();
    Resultat.append(QString::number(meilleur_score)) ;
    Resultat.append(liste_mois);

    return Resultat;
}


QVector<double> Historique::get_Stats(QString nomJeu,QString mois)
{
    QVector<double> Resultat;

    this->open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream flux(this);

    QDateTime date;
    int num_jour;
    int score;
    QMap< int, QList<int> > donnees_score;

    //On commence par récupérer tous les scores de chaque jour afin de pouvoir faire des moyennes par journées
    while (!flux.atEnd())
    {
        QString ligne=flux.readLine();
        if (ligne.contains(nomJeu))
        {
           QStringList liste_ligne=ligne.split("/");
           date=QDateTime::fromString(liste_ligne.value(0));
           if (date.toString("MMMM yyyy")==mois)
           {
               num_jour=date.toString("d").toInt();
               score=liste_ligne.value(2).toInt();
               if (donnees_score.contains(num_jour))
                    donnees_score[num_jour].append(score);
                else
                {
                QList<int> nll_list;
                nll_list.append(score);
                donnees_score[num_jour]=nll_list;
                }
           }
        }
    }

    this->close();

    //on remplit ensuite la liste des moyennes en renseignant 0 lorsque l'on a pas de score pour la journée
    for (int i=1;i<=31;i++)
    {

        if (donnees_score.contains(i))
        {

            double n=donnees_score[i].size();
            double addition_score=0;
            foreach (int score,donnees_score[i])
                addition_score = addition_score + score;
            double moyenne=addition_score/n;
            Resultat.append(moyenne);
        }
        else

            Resultat.append(0);

    }
    return Resultat;


}

Historique::~Historique()
{
    this->remove();
}
