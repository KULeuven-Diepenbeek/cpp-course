
#include "playercanvas.h"

#include <QPainter>
#include <QDebug>

PlayerCanvas::PlayerCanvas(QWidget *parent) : QWidget(parent)
{
    resetPlayer();
}

void PlayerCanvas::toUp() {
    playery -= DELTA;
    repaint();
    emit positionChanged(playerx, playery);
}

void PlayerCanvas::toDown() {
    playery += DELTA;
    repaint();
    emit positionChanged(playerx, playery);
}

void PlayerCanvas::toTheLeft() {
    playerx -= DELTA;
    repaint();
    emit positionChanged(playerx, playery);
}

void PlayerCanvas::toTheRight() {
    playerx += DELTA;
    repaint();
    emit positionChanged(playerx, playery);
}

void PlayerCanvas::resetPlayer()  {
    playerx = 50; playery = 50;
    repaint();
    emit positionChanged(playerx, playery);
}

void PlayerCanvas::paintEvent(QPaintEvent *event)
{
    qDebug() << "repaint player";

    QColor color(0xCC6666);
    QPainter painter(this);

    painter.setPen(QPen(color.light(), 5, Qt::DashLine, Qt::RoundCap));
    painter.drawRect(playerx, playery, 50, 50);
}
