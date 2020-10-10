#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "basetotaldisplay.h"
#include "stocktotaldisplay.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void addDisplay(BaseTotalDisplay *display, QString displayName);

public slots:
    void getStockPopup();
    void changeTabDisplay(int index);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
