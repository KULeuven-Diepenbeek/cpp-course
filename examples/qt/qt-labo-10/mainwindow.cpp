#include "breuk.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "actions.h"
#include "qpushbutton.h"
#include "qmessagebox.h"

#include <vector>
#include <string>
#include <sstream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    menuBar()->setNativeMenuBar(false);

    actionsWindow = new Actions(this);
    connect(actionsWindow->plusButton(), &QPushButton::clicked, [=]() {
        this->on_pushButton_clicked();
    });
    connect(actionsWindow->multiplyButton(), &QPushButton::clicked, [=]() {
        this->on_multiplyButton_clicked();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAfsluiten_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionActies_triggered()
{
    actionsWindow->show();
}

void MainWindow::showInvalidInput() {
    QMessageBox box;
    box.setText("Ongeldige breuk input");
    box.setIcon(QMessageBox::Critical);
    box.exec();
}

bool MainWindow::inputValid() {
    std::vector<QString> input = {
        ui->tellerA->text(), ui->tellerB->text(),
        ui->noemerA->text(), ui->noemerB->text()
    };

    return std::all_of(input.begin(), input.end(), [](QString raw) {
        bool ok;
        raw.toInt(&ok);
        return ok;
    });
}

void MainWindow::on_pushButton_clicked()
{
    if(!inputValid()) showInvalidInput();
    Breuk breuk1(ui->tellerA->text().toInt(), ui->noemerA->text().toInt());
    Breuk breuk2(ui->tellerB->text().toInt(), ui->noemerB->text().toInt());

    auto som = breuk1 + breuk2;
    std::ostringstream stream;
    stream << som;

    ui->output->appendHtml(stream.str().c_str());
}

void MainWindow::on_multiplyButton_clicked()
{
ui->output->appendHtml("*");
}
