#include "stockgetdialog.h"
#include "ui_stockgetdialog.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>

StockGetDialog::StockGetDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StockGetDialog)
{
    ui->setupUi(this);
    windowManager = WindowManager::getInstance();
    getStockCodes();
    connect(ui->getButton, &QPushButton::clicked, this, &StockGetDialog::getStockDisplay);
}

void StockGetDialog::getStockCodes()
{
    reply = restClient.getStockCodes();
    connect(reply, &QNetworkReply::finished, this, &StockGetDialog::receiveStockCodes);
}

void StockGetDialog::receiveStockCodes()
{
    QByteArray jsonRaw = reply->readAll();
//    QFile jsonFile("/home/yihreng/Desktop/stockCodes.json");
//    jsonFile.open(QFile::WriteOnly);
//    jsonFile.write(jsonRaw);
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonRaw);
    QJsonObject jsonObject = jsonDoc.object();
    QJsonObject interim = jsonObject["_embedded"].toObject();
    QJsonArray stockCodeList = interim["stringList"].toArray();
    QJsonArray::const_iterator i;
   for (i = stockCodeList.begin(); i != stockCodeList.end(); ++i) {
       QJsonValue stockCode = *i;
        ui->stockComboBox->addItem(stockCode.toString());
   }
}

void StockGetDialog::getStockDisplay()
{
    QString selectedStockCode = ui->stockComboBox->currentText();
    windowManager->changeTabDisplay(selectedStockCode, QString("Stock"));
}

StockGetDialog::~StockGetDialog()
{
    delete ui;
}
