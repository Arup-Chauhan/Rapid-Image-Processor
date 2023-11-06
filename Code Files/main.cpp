#include "mainapplication.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainApplication mainWindow;
    mainWindow.show();
    return app.exec();
}
