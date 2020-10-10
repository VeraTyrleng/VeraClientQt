#ifndef RESTCLIENT_H
#define RESTCLIENT_H

#include <QObject>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>

class RestClient : public QObject
{
    Q_OBJECT
public:
    explicit RestClient(QObject *parent = nullptr);
    QNetworkReply* getStock(QString stockCode);
    QNetworkReply* getShareTransaction (QString stockCode, QString transactionId);
    QNetworkReply* getStockCodes();

signals:

private:
    QNetworkAccessManager manager;

private slots:

};

#endif // RESTCLIENT_H
