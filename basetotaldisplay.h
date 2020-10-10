#ifndef BASETOTALDISPLAY_H
#define BASETOTALDISPLAY_H

#include <QObject>
#include <QWidget>
#include <QMenuBar>
#include <QMenu>
#include <QDialogButtonBox>
#include <QAbstractItemView>

class BaseMenuBar : public QMenuBar
{
public:
    explicit BaseMenuBar(QWidget *parent = nullptr);

};

class BaseButtonBar : public QDialogButtonBox
{
public:
    explicit BaseButtonBar(QWidget *parent = nullptr);
};

class BaseTotalDisplay : public QWidget
{
    Q_OBJECT
public:
    explicit BaseTotalDisplay(QWidget *parent = nullptr);

    virtual BaseMenuBar* getMenuBar(QWidget *parent = nullptr);
    virtual BaseButtonBar* getButtonBar(QWidget *parent = nullptr);
protected:
    BaseButtonBar* buttonBar;

private:
    QString Id;
};

#endif // BASETOTALDISPLAY_H
