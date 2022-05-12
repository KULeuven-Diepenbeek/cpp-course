#ifndef ACTIONS_H
#define ACTIONS_H

#include <QDialog>

namespace Ui {
class Actions;
}

class Actions : public QDialog
{
    Q_OBJECT

public:
    explicit Actions(QWidget *parent = nullptr);
    ~Actions();

    QPushButton* plusButton();
    QPushButton* multiplyButton();

private slots:

private:
    Ui::Actions *ui;
};

#endif // ACTIONS_H
