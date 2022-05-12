#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "playercanvas.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent *event);

private slots:
    void on_pushButton_clicked();

private:
    void updatePositionLabels(int playerx, int playery);

    Ui::MainWindow *ui;
    PlayerCanvas* canvas;

};

#endif // MAINWINDOW_H
