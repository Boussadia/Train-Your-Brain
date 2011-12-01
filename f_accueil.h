#ifndef F_ACCUEIL_H
#define F_ACCUEIL_H

#include <QWidget>
#include <QFile>
#include <QMouseEvent>


namespace Ui {
    class F_Accueil;
}

class F_Accueil : public QWidget
{
    Q_OBJECT

public:
    explicit F_Accueil();
    ~F_Accueil();
    QFile* get_Liste_Sessions();


public slots:
    void CreerSession();
    void Envoi_Signal_Ouvrir_Session();

signals:
   void Signal_Ouvrir_Session(QString Nom_Session);

private:
    Ui::F_Accueil *ui;
    QFile *_liste_sessions;

};

#endif // F_ACCUEIL_H
