#ifndef PLAYERCANVAS_H
#define PLAYERCANVAS_H

#include <QObject>
#include <QWidget>

#define DELTA 15

class PlayerCanvas : public QWidget
{
    Q_OBJECT
public:
    explicit PlayerCanvas(QWidget *parent = nullptr);

    void resetPlayer();
    void toTheLeft();
    void toTheRight();
    void toUp();
    void toDown();

signals:
    void positionChanged(int x, int y);

protected:
    void paintEvent(QPaintEvent *event) override;

public slots:

private:
    int playerx, playery;

};

#endif // PLAYERCANVAS_H
