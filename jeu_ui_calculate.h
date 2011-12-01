#ifndef JEU_UI_CALCULATE_H
#define JEU_UI_CALCULATE_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>

#include <jeu_ui.h>

namespace Ui {
    class Jeu_Ui_Calculate;
}

class Jeu_Ui_Calculate : public Jeu_Ui
{
    Q_OBJECT

public:
    explicit Jeu_Ui_Calculate();
    ~Jeu_Ui_Calculate();

signals:
    void reponse(QVector<QString> reponse);

public slots:
    void setNumber1(int number);
    void setNumber2(int number);
    void setOperation(QString operation);
    void emettre_reponse();

private:
    Ui::Jeu_Ui_Calculate *ui;
    QLineEdit *m_answerField;
    QLabel *m_number1;
    QLabel *m_number2;
    QLabel *m_operation;
};

#endif // JEU_UI_CALCULATE_H
