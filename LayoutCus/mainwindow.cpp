#include "mainwindow.h"
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    HakWidget *widget1 = new HakWidget("Stock Price", "22.15");
    HakWidget *widget2 = new HakWidget("Bought Price", "13.45");
    QHBoxLayout *layout = new QHBoxLayout();
    layout->addWidget(widget1);
    layout->addWidget(widget2);
    setLayout(layout);
}

MainWindow::~MainWindow()
{
}

