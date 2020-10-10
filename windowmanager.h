#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include <QObject>
#include "basetotaldisplay.h"
#include "mainwindow.h"

class WindowManager : public QObject
{
    Q_OBJECT

public:
    explicit WindowManager(QObject *parent = nullptr);
    static WindowManager* getInstance();
    static void setMainWindow(MainWindow* mainWindow);
    void changeTabDisplay(QString displayName, QString displayType);

signals:

private:
    static MainWindow* mainWindow;
    static WindowManager* windowManagerInstance;
};

#endif // WINDOWMANAGER_H
