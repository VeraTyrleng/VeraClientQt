#ifndef STOCKGETDIALOG_H
#define STOCKGETDIALOG_H

#include <QDialog>

#include "restclient.h"
#include "windowmanager.h"

namespace Ui {
class StockGetDialog;
}


class StockGetDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StockGetDialog(QWidget *parent = nullptr);
    ~StockGetDialog();

private:
    void getStockCodes();

    Ui::StockGetDialog *ui;

    RestClient restClient;
    QNetworkReply* reply;
    WindowManager* windowManager;

private slots:
    void receiveStockCodes();
    void getStockDisplay();
};

#endif // STOCKGETDIALOG_H
