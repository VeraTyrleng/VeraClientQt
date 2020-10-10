#include "basetotaldisplay.h"

#include <QPushButton>

BaseMenuBar::BaseMenuBar(QWidget *parent) : QMenuBar(parent)
{
    addMenu("File");
    addMenu("Edit");
}

BaseButtonBar::BaseButtonBar(QWidget *parent) : QDialogButtonBox(parent)
{
    addButton(QDialogButtonBox::Apply);
    addButton(QDialogButtonBox::SaveAll);
}

BaseTotalDisplay::BaseTotalDisplay(QWidget *parent) : QWidget(parent)

{
    buttonBar = getButtonBar();
}

BaseMenuBar* BaseTotalDisplay::getMenuBar(QWidget* parent)
{
    return new BaseMenuBar(parent);
}

BaseButtonBar* BaseTotalDisplay::getButtonBar(QWidget *parent)
{
    buttonBar = new BaseButtonBar(this);
    return buttonBar;
}


