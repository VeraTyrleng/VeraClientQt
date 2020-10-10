#include "restclient.h"

RestClient::RestClient(QObject *parent) : QObject(parent)
{

}

QNetworkReply* RestClient::getStock(QString stockCode)
{
    QString url("http://localhost:8080/stock/%1");
    url = url.arg(stockCode);
    return manager.get(QNetworkRequest(QUrl(url)));
}

QNetworkReply* RestClient::getStockCodes()
{
    QString url("http://localhost:8080/stock");
    return manager.get(QNetworkRequest(QUrl(url)));
}
