#ifndef JEU_UI_MEMORIZE_H
#define JEU_UI_MEMORIZE_H

#include <QWidget>
#include <QVector>
#include <QString>

#include "matrice_memorize.h"
#include <jeu_ui.h>

class Jeu_Ui_Memorize : public Jeu_Ui
{
    Q_OBJECT

public:
    Jeu_Ui_Memorize();
    ~Jeu_Ui_Memorize();
    void afficher_matrice(bool a_memoriser);
    void setCaracteristiques(int niveau, QVector<QString> INPUT);

public slots:
    void emettre_reponse();
    void effacer_grille();

signals:
    void reponse(QVector<QString> reponse);

private:
    Matrice_Memorize *_matrice;
    int _niveau;
    QVector<QString> _Input;
};

#endif // JEU_UI_MEMORIZE_H
