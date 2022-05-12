#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>
#include <QDebug>
#include <QVBoxLayout>
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    canvas(new PlayerCanvas())
{
    ui->setupUi(this);
    auto vbox = new QVBoxLayout();
    vbox->addWidget(canvas);
    ui->ventjeGroup->setLayout(vbox);

    connect(canvas, &PlayerCanvas::positionChanged, this, &MainWindow::updatePositionLabels);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    qDebug() << event->key();

    if(event->key() == Qt::Key_Left) {
        canvas->toTheLeft();
    } else if(event->key() == Qt::Key_Right) {
        canvas->toTheRight();
    } else if(event->key() == Qt::Key_Up) {
        canvas->toUp();
    } else if(event->key() == Qt::Key_Down) {
        canvas->toDown();
    }
}

void MainWindow::updatePositionLabels(int playerx, int playery)
{
    qDebug() << "update labels";
    qDebug() << playerx;

    ui->lblx->setText("playerx: " + QString::number(playerx) + " --");
    ui->lbly->setText("playery: " + QString::number(playery) + " --");
    ui->lblx->repaint();
    ui->lbly->repaint();
}

void MainWindow::on_pushButton_clicked()
{
    canvas->resetPlayer();
}
