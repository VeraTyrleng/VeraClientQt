#ifndef HAKWIDGET_H
#define HAKWIDGET_H

#include <QWidget>

class HakWidget : public QWidget
{
    Q_OBJECT
public:
    explicit HakWidget(QWidget *parent = nullptr);
    explicit HakWidget(QString name, QString data);

signals:

};

#endif // HAKWIDGET_H
