#pragma once

#include <QWidget>
#include <QVector>
#include <QPoint>
#include <QKeyEvent>
#include <QDialog>
#include <QRandomGenerator64>
#include <QPalette>
#include "gameoverwindow.h"
#include "ui_gameoverwindow.h"

class Game : public QWidget
{
private:
    bool game_over;
    const int HEIGHT = 25;
    const int WIDTH = 25;
    int DELAY=100;
    QVector<QPoint> snake;
    QVector<QPoint> walls;
    QPoint apple;
    enum DIR {STOP, LEFT, RIGHT, UP, DOWN};
    DIR mov_dir;
    int timerId;
    Game();
    static Game* shared_instance;
public:
    bool mode_flag;
    void Setup();
    void draw();
    void move();
    void check_field();
    void check_apple();
    void gameOver();
    void init_walls();
    void draw_walls();
    void draw_snake();
    static Game* get_instance();
    void setDELAY(int newDELAY);

protected:
    void timerEvent(QTimerEvent*) override;
    void keyPressEvent(QKeyEvent *) override;
    void paintEvent(QPaintEvent *) override;
};
