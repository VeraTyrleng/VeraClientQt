#include "stocktotaldisplay.h"

#include <QStandardItemModel>
#include <QStandardItem>
#include <QHeaderView>
#include <QPushButton>
#include <QSizePolicy>

#include <QJsonObject>
#include <QJsonDocument>

#include <QDebug>

StockMenuBar::StockMenuBar(QWidget *parent) : BaseMenuBar(parent)
{
   addMenu(new QMenu(QString("Foo 1")));
   addMenu(new QMenu(QString("Foo 2")));
}

StockButtonBar::StockButtonBar(QWidget *parent): BaseButtonBar(parent)
{
    addButton(QDialogButtonBox::Help);
    addButton(QDialogButtonBox::NoToAll);
}

StockTotalDisplay::StockTotalDisplay( QString stockCode, QWidget *parent) : BaseTotalDisplay(parent),
    restClient(new RestClient())
//    tableView(new QTableView(this)),
//    model(new QStandardItemModel())
{
    model = new QStandardItemModel(1,4,this);
    gridLayout = new QGraphicsGridLayout();
    rootWidget = new QGraphicsWidget();
    scene = new QGraphicsScene();
    view = new QGraphicsView();
    buttonBar = new StockButtonBar(this);
    layout = new QVBoxLayout(this);

    layout->addChildWidget(buttonBar);
    layout->addChildWidget(rootWidget);

    getStock(stockCode);

    setUpChildren();
    setUpMapping();

//    tableView->setModel(model);
//    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//    QSizePolicy tableViewPolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
//    tableView->setSizePolicy(tableViewPolicy);

    rootWidget->setLayout(gridLayout);
    scene->addItem(rootWidget);
//    scene->setSceneRect(0, -50, 800, 480);
    view->setScene(scene);
    view->setParent(this);

    QPalette pal;
    pal.setColor(QPalette::Background, Qt::darkRed);
    scene->setPalette(pal);
}

StockTotalDisplay::StockTotalDisplay(QString stockCode) : StockTotalDisplay(stockCode, nullptr)
{
}

void StockTotalDisplay::setUpChildren()
{
    namePane = new InfoPane("Stock Name", Qt::cyan);
    stockCodePane = new InfoPane("Stock Code", Qt::yellow);
    currentPricePane = new InfoPane("Current Price", Qt::magenta);
    industryPane = new InfoPane("Industry", Qt::gray);

    gridLayout->addItem(namePane, 0, 0);
    gridLayout->addItem(stockCodePane, 0, 1);
    gridLayout->addItem(currentPricePane, 0 ,2);
    gridLayout->addItem(industryPane, 0, 3);
}

void StockTotalDisplay::setUpMapping()
{
    mapper = new QDataWidgetMapper(this);
    mapper->setModel(model);
    stockCodePane->acceptMapping(mapper,0);
    namePane->acceptMapping(mapper, 1);
    currentPricePane->acceptMapping(mapper,2);
    industryPane->acceptMapping(mapper,3);
    mapper->toFirst();
}

BaseMenuBar* StockTotalDisplay::getMenuBar(QWidget *parent)
{
    return new StockMenuBar(parent);
}

BaseButtonBar* StockTotalDisplay::getButtonBar(QWidget *parent)
{
    return new StockButtonBar(parent);
}

void StockTotalDisplay::getStock(QString stockCode)
{
    reply = restClient.getStock(stockCode);
    connect(reply, &QNetworkReply::finished, this, &StockTotalDisplay::receiveStock);
}

void StockTotalDisplay::receiveStock()
{
    QByteArray jsonRaw = reply->readAll();
    QJsonDocument jsonDocument = QJsonDocument::fromJson(jsonRaw);
    QJsonObject stockJsonObj = jsonDocument.object();

    QString stockCodeValue = stockJsonObj["stockCode"].toString();
    model->setItem(0,0, new QStandardItem(stockCodeValue));

    QString stockNameValue = stockJsonObj["stockName"].toString();
    model->setItem(0, 1, new QStandardItem(stockNameValue));

    QString currentPriceValue = stockJsonObj["currentStockPrice"].toString();
    model->setItem(0, 2, new QStandardItem(currentPriceValue));

    QString industryValue = stockJsonObj["industry"].toString();
    model->setItem(0,3,new QStandardItem(industryValue));

//    model->insertRow(0,{new QStandardItem("Stock Code"), new QStandardItem(stockCodeValue)});
//    model->insertRow(1, {new QStandardItem("Stock Name"), new QStandardItem(stockNameValue)});
//    model->insertRow(2,{new QStandardItem("Current Stock Price"), new QStandardItem(currentPriceValue)});
//    model->insertRow(3, {new QStandardItem("Industry"), new QStandardItem(industryValue)});


}
