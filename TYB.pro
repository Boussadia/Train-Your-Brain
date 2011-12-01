SOURCES += \
    main.cpp \
    f_accueil.cpp \
    MainWindow.cpp \
    f_session.cpp \
    f_stats.cpp \
    f_jeu.cpp \
    controlleur.cpp \
    controleur_calculate.cpp \
    regles.cpp \
    regles_calculate.cpp \
    jeu_ui_calculate.cpp \
    historique.cpp \
    graphe.cpp \
    controlleur_memorize.cpp \
    regles_memorize.cpp \
    jeu_ui_memorize.cpp \
    matrice_memorize.cpp \
    jeu_ui.cpp \
    case_matrice.cpp \
    regles_quickshape.cpp \
    jeu_ui_quickshape.cpp \
    controlleur_quickshape.cpp

HEADERS += \
    f_accueil.h \
    MainWindow.h \
    f_session.h \
    f_stats.h \
    f_jeu.h \
    controlleur.h \
    controleur_calculate.h \
    regles.h \
    regles_calculate.h \
    jeu_ui_calculate.h \
    historique.h \
    graphe.h \
    controlleur_memorize.h \
    regles_memorize.h \
    jeu_ui_memorize.h \
    matrice_memorize.h \
    jeu_ui.h \
    case_matrice.h \
    regles_quickshape.h \
    jeu_ui_quickshape.h \
    controlleur_quickshape.h

FORMS += f_accueil.ui \
    f_session.ui \
    f_stats.ui \
    f_jeu.ui \
    jeu_ui_calculate.ui \
    jeu_ui_quickshape.ui

INCLUDEPATH += $$quote(c:/qwt-5.2.1/src)

LIBS += $$quote(c:/qwt-5.2.1/lib/libqwt5.a)

DEFINES += QWT_DLL

OTHER_FILES +=


































































































