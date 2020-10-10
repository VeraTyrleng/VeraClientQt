#include "mainwindow.h"
#include "windowmanager.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow* w = new MainWindow();
    WindowManager::setMainWindow(w);
    StockTotalDisplay *dummyDisplay = new StockTotalDisplay (QString("D05"), w);
    w->addDisplay(dummyDisplay, QString("D05"));
    w->show();
    return a.exec();
}
