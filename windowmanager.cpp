#include "windowmanager.h"

#include "stocktotaldisplay.h"

WindowManager::WindowManager(QObject *parent) : QObject(parent)
{

}

WindowManager* WindowManager::windowManagerInstance = nullptr;
MainWindow* WindowManager::mainWindow = nullptr;

WindowManager* WindowManager::getInstance()
{
    if (windowManagerInstance != nullptr) {
        return windowManagerInstance;
    }
    windowManagerInstance = new WindowManager();
    return windowManagerInstance;
}

void WindowManager::setMainWindow(MainWindow* mainWindow)
{
    WindowManager::mainWindow = mainWindow;
}

void WindowManager::changeTabDisplay(QString windowId, QString displayType)
{
    QString stock ("Stock");
    if(stock.compare(displayType, Qt::CaseInsensitive) == 0) {
        StockTotalDisplay *display = new StockTotalDisplay(windowId, mainWindow);
        mainWindow->addDisplay(display, windowId);
    }
}
