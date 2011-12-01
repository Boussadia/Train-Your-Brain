#ifndef JEU_UI_H
#define JEU_UI_H

#include <QWidget>

class Jeu_Ui : public QWidget
{
    Q_OBJECT

public:
    Jeu_Ui();

public slots:
    virtual void emettre_reponse() =0;

signals:
    void reponse(QVector<QString> reponse);

};

#endif // JEU_UI_H
