#ifndef STOCKTOTALDISPLAY_H
#define STOCKTOTALDISPLAY_H

#include "basetotaldisplay.h"
#include "restclient.h"

#include <QTableView>
#include <QWidget>
#include <QVBoxLayout>

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsWidget>
#include <QGraphicsGridLayout>

#include "infopane.h"
#include <QDataWidgetMapper>
#include <QStandardItemModel>
#include <QMenuBar>

class StockMenuBar : public BaseMenuBar
{
public:
    StockMenuBar(QWidget *parent = nullptr);
};

class StockButtonBar : public BaseButtonBar
{
public:
    StockButtonBar(QWidget *parent = nullptr);
};

class StockTotalDisplay : public BaseTotalDisplay
{

public:

    StockTotalDisplay(QString stockCode, QWidget *parent = nullptr);
    StockTotalDisplay(QString stockCode);

    BaseMenuBar* getMenuBar(QWidget *parent) override;
    BaseButtonBar* getButtonBar(QWidget *parent) override;

private:
    void setUpChildren();
    void setUpMapping();
    void getStock (QString stockCode);
    void getStockCodes();
    void getShareTransaction (QString stockCode, qint32 transactionId);

    RestClient restClient;
    QNetworkReply* reply;

    QStandardItemModel* model;
    QDataWidgetMapper* mapper;
    QVBoxLayout* layout;

    QTableView* tableView;

    QGraphicsWidget* rootWidget;
    QGraphicsScene* scene;
    QGraphicsView* view;
    QGraphicsGridLayout* gridLayout;

    InfoPane* namePane;
    InfoPane* stockCodePane;
    InfoPane* currentPricePane;
    InfoPane* industryPane;

private slots:
    void receiveStock();
};

#endif // STOCKTOTALDISPLAY_H
