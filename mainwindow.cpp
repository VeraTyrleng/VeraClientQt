#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "stockgetdialog.h"

#include <QHeaderView>
#include <QAction>
#include <QDebug>
#include <QLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    connect(ui->getStockAction, &QAction::triggered, this, &MainWindow::getStockPopup);
    connect(ui->tabWidget, &QTabWidget::tabBarClicked, this, &MainWindow::changeTabDisplay);
    connect(ui->tabWidget, &QTabWidget::tabBarDoubleClicked, this, &MainWindow::changeTabDisplay);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addDisplay(BaseTotalDisplay *display, QString displayName)
{
    ui->tabWidget->addTab(display, displayName);
}

void MainWindow::changeTabDisplay(int index)
{
    BaseTotalDisplay* display = (BaseTotalDisplay*) ui->tabWidget->widget(index);
    BaseMenuBar *menuBar = display->getMenuBar();
    setMenuBar(menuBar);
}

void MainWindow::getStockPopup()
{
    qDebug() << "Hi Hi";
    StockGetDialog popUp;
//    popUp.setWindowModality(Qt::ApplicationModal);
    popUp.exec();
    qDebug() << "Bye Bye";
}
