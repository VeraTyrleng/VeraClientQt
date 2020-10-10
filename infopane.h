#ifndef INFOPANE_H
#define INFOPANE_H

#include <QGraphicsWidget>
#include<QGraphicsProxyWidget>
#include <QDataWidgetMapper>
#include <QLabel>


class InfoPane : public QGraphicsWidget
{
public:
    InfoPane();
    explicit InfoPane(QString title, QString data, Qt::GlobalColor color);
    explicit InfoPane(QString title, Qt::GlobalColor color);
    void acceptMapping (QDataWidgetMapper *mapper, int column);

private:
    QGraphicsProxyWidget *title;
    QGraphicsProxyWidget *data;
    QLabel *dataLabel;
//    void setUp();
};

#endif // INFOPANE_H
