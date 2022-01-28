#include "gameoverwindow.h"
#include "ui_gameoverwindow.h"
#include "modeswindow.h"
#include "ui_modeswindow.h"
#include "homewindow.h"
#include"ui_homewindow.h"


gameoverwindow::gameoverwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gameoverwindow)
{
    ui->setupUi(this);
    QPixmap pix2("C:/Qt/snake_from_console/Picture/snake_with_three_and_apple.jpg");
    ui->label_12->setPixmap(pix2);
}

void gameoverwindow::set_score(int score)
{
    ui->label_3->setText(QString("Your Score Is: %1").arg(score));
}

gameoverwindow::~gameoverwindow()
{
    delete ui;
}

void gameoverwindow::on_pushButton_clicked()
{
    hide();
    ModesWindow* wind=new ModesWindow();
    wind->setWindowTitle("Modes");
    wind->show();
}


void gameoverwindow::on_pushButton_2_clicked()
{
    hide();
}


void gameoverwindow::on_pushButton_3_clicked()
{
    hide();
    HomeWindow *wind=new HomeWindow();
    wind->setWindowTitle("HOME PAGE");
    wind->show();
}

