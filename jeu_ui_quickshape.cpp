#include "jeu_ui_quickshape.h"
#include "ui_jeu_ui_quickshape.h"

#include <QTimer>

Jeu_Ui_Quickshape::Jeu_Ui_Quickshape() :
    Jeu_Ui(),
    ui(new Ui::Jeu_Ui_Quickshape)
{
    ui->setupUi(this);

    // Initialisation des attributs de la classe
    m_answerYes = ui->YES;
    m_answerNo = ui->NO;
    label_img  = ui->PICTURE;

    //on initialise la premiere image pour la voir apparaitre dès la création de la fenetre
    QImage image("images_quickshape/Croix.png");
    label_img->setPixmap(QPixmap::fromImage(image.scaled(200,200)));

    //Connections
    QObject::connect(m_answerYes,SIGNAL(clicked()),this,SLOT(getPlayerAnswerYes()));
    QObject::connect(m_answerNo,SIGNAL(clicked()),this,SLOT(getPlayerAnswerNo()));

    //Gestion des Layout faite par Qt Designer
}

Jeu_Ui_Quickshape::~Jeu_Ui_Quickshape()
{
    delete ui;
}


void Jeu_Ui_Quickshape::setPict(QString directory)
{
    QImage image(directory);
    label_img->setPixmap(QPixmap::fromImage(image.scaled(200,200)));
    label_img->hide();

    //On lance un Timer pour avoir un tps ou rien n'est afficher.
    QTimer *Timer_between = new QTimer(this);
    Timer_between->setSingleShot(true);
    QObject::connect(Timer_between,SIGNAL(timeout()),label_img,SLOT(show()));
    Timer_between->start(300);
}


void Jeu_Ui_Quickshape::emettre_reponse()
{
}

void Jeu_Ui_Quickshape::getPlayerAnswerYes()
{
    QVector<QString> vect_reponse(1);
    vect_reponse[0]="YES";
    emit reponse(vect_reponse);
}

void Jeu_Ui_Quickshape::getPlayerAnswerNo()
{
    QVector<QString> vect_reponse(1);
    vect_reponse[0]="NO";
    emit reponse(vect_reponse);
}
