#ifndef JEU_UI_QUICKSHAPE_H
#define JEU_UI_QUICKSHAPE_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QString>
#include <QPushButton>

#include <jeu_ui.h>

namespace Ui {
    class Jeu_Ui_Quickshape;
}

class Jeu_Ui_Quickshape : public Jeu_Ui
{
    Q_OBJECT

public:
    explicit Jeu_Ui_Quickshape();
    ~Jeu_Ui_Quickshape();

signals:
    void reponse(QVector<QString> reponse);

public slots:
    void setPict(QString directory);
    void getPlayerAnswerYes();
    void getPlayerAnswerNo();
    void emettre_reponse();

private:
    Ui::Jeu_Ui_Quickshape *ui;
    QPushButton *m_answerYes;
    QPushButton *m_answerNo;
    QLabel *label_img;
};

#endif // JEU_UI_QUICKSHAPE_H
