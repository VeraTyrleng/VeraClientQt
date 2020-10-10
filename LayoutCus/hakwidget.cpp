#include "hakwidget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>

HakWidget::HakWidget(QWidget *parent) : QWidget(parent)
{

}

HakWidget::HakWidget(QString name, QString data)
{
//    QVBoxLayout *nameCol = new QVBoxLayout();
//    QVBoxLayout *dataCol = new QVBoxLayout();
//    QLabel *nameLabel = new QLabel(name);
//    QLabel *dataLabel = new QLabel(data);
//    nameCol->addWidget(nameLabel, 0, Qt::AlignVCenter);
//    dataCol->addWidget(dataLabel, 0, Qt::)
    QHBoxLayout *nameRow = new QHBoxLayout();
    QHBoxLayout *dataRow = new QHBoxLayout();
    QLabel *nameLabel = new QLabel(name);
    QLabel *dataLabel = new QLabel(data);
    nameRow->addWidget(nameLabel, Qt::AlignLeft);
    nameRow->addSpacerItem(new QSpacerItem(80,20));
    dataRow->addSpacerItem(new QSpacerItem(80,20));
    dataRow->addWidget(dataLabel, Qt::AlignRight);
    QVBoxLayout *masterLayout = new QVBoxLayout();
    masterLayout->addLayout(nameRow);
    masterLayout->addLayout(dataRow);
    setLayout(masterLayout);
}
