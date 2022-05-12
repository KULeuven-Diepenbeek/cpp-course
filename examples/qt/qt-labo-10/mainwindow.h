#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "actions.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionAfsluiten_triggered();
    void on_actionActies_triggered();

private:
    Ui::MainWindow *ui;
    Actions* actionsWindow;

    bool inputValid();
    void showInvalidInput();

    // WHY no slots? zelf gebind met connect() tussen de schermen.
    void on_pushButton_clicked();
    void on_multiplyButton_clicked();
};

#endif // MAINWINDOW_H
