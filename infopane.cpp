#include "infopane.h"

#include <QLabel>
#include <QGraphicsAnchorLayout>
#include <QPalette>

InfoPane::InfoPane()
{

}

InfoPane::InfoPane(QString title, QString data, Qt::GlobalColor color) : QGraphicsWidget()
{

}

InfoPane::InfoPane(QString title, Qt::GlobalColor color)
{
    this->title = new QGraphicsProxyWidget;
    this->data = new QGraphicsProxyWidget;

    QLabel *titleLabel = new QLabel(title);
     dataLabel = new QLabel();

    this->title->setWidget(titleLabel);
    this->data->setWidget(dataLabel);

    QGraphicsAnchorLayout *l = new QGraphicsAnchorLayout;
     l->setSpacing(0);

     setLayout(l);

     l->addCornerAnchors(this->title, Qt::TopLeftCorner, l, Qt::TopLeftCorner);
     l->addCornerAnchors(this->data, Qt::BottomRightCorner, l, Qt::BottomRightCorner);

     setPreferredSize(100,100);
     setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

     QPalette pal;
     pal.setColor(QPalette::Background, color);
     setPalette(pal);
     setAutoFillBackground(true);
}

void InfoPane::acceptMapping(QDataWidgetMapper *mapper, int column)
{
    mapper->addMapping(dataLabel, column, QString("text").toUtf8());
}
