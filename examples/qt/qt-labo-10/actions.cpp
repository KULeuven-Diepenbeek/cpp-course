#include "actions.h"
#include "ui_actions.h"

Actions::Actions(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Actions)
{
    ui->setupUi(this);
}

QPushButton* Actions::plusButton() {
    return ui->plusButton;
}

QPushButton* Actions::multiplyButton() {
    return ui->multiplyButton;
}

Actions::~Actions()
{
    delete ui;
}

