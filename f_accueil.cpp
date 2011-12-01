#include "f_accueil.h"
#include "ui_f_accueil.h"

#include <QString>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QMessageBox>

F_Accueil::F_Accueil() :
    QWidget(),
    ui(new Ui::F_Accueil)
{    
    ui->setupUi(this);

    _liste_sessions = new QFile("liste_sessions.txt");
    QTextStream flux(_liste_sessions);
    QString Nom_Session;

    _liste_sessions->open(QIODevice::ReadOnly | QIODevice::Text);

    while (!flux.atEnd())
    {
        Nom_Session = flux.readLine();
        QPushButton * Session = new QPushButton(Nom_Session);
        Session->setFont(QFont("MS Shell Dlg 2", 14,75));
        Session->setCursor(Qt::PointingHandCursor);
        Session->setFixedSize(250,50);

        QObject::connect(Session, SIGNAL(clicked()), this, SLOT(Envoi_Signal_Ouvrir_Session()));

        QListWidgetItem *item = new QListWidgetItem();
        ui->liste_session->insertItem(0,item);
        ui->liste_session->setItemWidget(item,Session);
    }

    _liste_sessions->close();


    //lorqu'on clique sur nouvelle session, on on crée une nouvelle session :
    QObject::connect(ui->Creer_Button, SIGNAL(clicked()), this, SLOT(CreerSession()));
    //lorsqu'on appuie sur le bouton entrée, on crée une nouvelle session :
    QObject::connect(ui->Saisie, SIGNAL(returnPressed()), this, SLOT(CreerSession()));

}

F_Accueil::~F_Accueil()
{
    delete ui;
}

void F_Accueil::CreerSession(void)
{
    QString Nom_Session=ui->Saisie->text() ;

    _liste_sessions->open(QIODevice::ReadWrite | QIODevice::Text);

    QString contenu=_liste_sessions->readAll();

    if ((Nom_Session != "") && (!contenu.contains(Nom_Session)))
    {
        //on créé tout de même le bouton qu'on insère dans la liste déroulante
        QPushButton * Session = new QPushButton(Nom_Session);
        Session->setFont(QFont("MS Shell Dlg 2", 14,75));
        Session->setCursor(Qt::PointingHandCursor);
        Session->setFixedSize(250,50);

        QObject::connect(Session, SIGNAL(clicked()), this, SLOT(Envoi_Signal_Ouvrir_Session()));

        QListWidgetItem *item = new QListWidgetItem();
        ui->liste_session->insertItem(0,item);
        ui->liste_session->setItemWidget(item,Session);

        ui->Saisie->setText("Entrer votre nom d'Utilisateur...");

        emit Signal_Ouvrir_Session(Nom_Session);

        Nom_Session += "\n";
        _liste_sessions->write(Nom_Session.toLatin1(),Nom_Session.size());
    }

    else if (contenu.contains(Nom_Session))
    {
        QMessageBox::warning(this,"EUuuuuu... Problème","Cette session existe déjà");
    }
    else
    {
        QMessageBox::warning(this,"EUuuuuu... Problème","Veuillez entrer un Nom d'Utilisateur");
    }

    _liste_sessions->close();
}

void F_Accueil::Envoi_Signal_Ouvrir_Session()
{
    QPushButton *bouton = (QPushButton *)sender();
    emit Signal_Ouvrir_Session(bouton->text());
}

QFile* F_Accueil::get_Liste_Sessions()
{
    return _liste_sessions;
}

