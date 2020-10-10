#ifndef STOCKGETPOPUP_H
#define STOCKGETPOPUP_H

#include <QWidget>

namespace Ui {
class StockGetPopup;
}

class StockGetPopup : public QWidget
{
    Q_OBJECT

public:
    explicit StockGetPopup(QWidget *parent = nullptr);
    ~StockGetPopup();

private:
    Ui::StockGetPopup *ui;
};

#endif // STOCKGETPOPUP_H
