#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QMessageBox>
#include <iostream>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->progress, &QProgressBar::valueChanged, [](const int &newVal) {
        std::cout << newVal << std::endl;
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionHullep_triggered()
{
    ui->btnSup->setText("geklikt ofwa");
}

void MainWindow::on_btnSup_clicked()
{
    qDebug() << "hekyes";
}


void MainWindow::on_slider_sliderMoved(int position)
{
    //ui->progress->setValue(position);
}

void MainWindow::on_pushButton_clicked()
{
    qDebug() << "nieuwe knop";
}
