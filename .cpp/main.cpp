#include <QApplication>
#include "homewindow.h"
#include "game.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    HomeWindow wind;
    wind.setWindowTitle("HOME PAGE");
    wind.show();
    return app.exec();
}

