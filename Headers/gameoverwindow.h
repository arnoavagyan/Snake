#ifndef GAMEOVERWINDOW_H
#define GAMEOVERWINDOW_H
#include "game.h"
#include <QMainWindow>


namespace Ui {
class gameoverwindow;
}

class gameoverwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit gameoverwindow(QWidget *parent = nullptr);
    void set_score(int);
    ~gameoverwindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::gameoverwindow *ui;

};

#endif // GAMEOVERWINDOW_H
