#include "f_accueil.h"
#include "MainWindow.h"
#include "jeu_ui_memorize.h"

#include <QApplication>
#include <QtGui>



int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    F_Accueil *accueil = new F_Accueil;
    MainWindow fenetre_generale(accueil);
    fenetre_generale.show();

    return app.exec();
}

