#include "modeswindow.h"
#include "ui_modeswindow.h"
#include "game.h"


ModesWindow::ModesWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ModesWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Qt/snake_from_console/Picture/happy_snake.jpg");
    ui->label_pic->setPixmap(pix);
}

ModesWindow::~ModesWindow()
{
    delete ui;
}


void ModesWindow::on_pushButton_clicked()
{

      Game::get_instance()->mode_flag=false;
      ui->pushButton->setStyleSheet("background-color: rgb(170, 0, 0);");
      ui->pushButton_2->setStyleSheet("background-color: rgb(0, 85, 0);");
}


void ModesWindow::on_pushButton_2_clicked()
{
     Game::get_instance()->mode_flag=true;
      ui->pushButton_2->setStyleSheet("background-color: rgb(170, 0, 0);");
      ui->pushButton->setStyleSheet("background-color: rgb(0, 85, 0);");

}

void ModesWindow::on_pushButton_3_clicked()
{
    Game::get_instance()->setDELAY(150);
    ui->pushButton_3->setStyleSheet("background-color: rgb(170, 0, 0);");
    ui->pushButton_4->setStyleSheet("background-color: rgb(0, 85, 0);");
    ui->pushButton_5->setStyleSheet("background-color: rgb(0, 85, 0);");
}


void ModesWindow::on_pushButton_4_clicked()
{
    Game::get_instance()->setDELAY(100);
    ui->pushButton_4->setStyleSheet("background-color: rgb(170, 0, 0);");
    ui->pushButton_3->setStyleSheet("background-color: rgb(0, 85, 0);");
    ui->pushButton_5->setStyleSheet("background-color: rgb(0, 85, 0);");
}


void ModesWindow::on_pushButton_5_clicked()
{
    Game::get_instance()->setDELAY(50);
    ui->pushButton_5->setStyleSheet("background-color: rgb(170, 0, 0);");
    ui->pushButton_3->setStyleSheet("background-color: rgb(0, 85, 0);");
    ui->pushButton_4->setStyleSheet("background-color: rgb(0, 85, 0);");
}



void ModesWindow::on_start_button_clicked()
{
    hide();
    Game::get_instance()->Setup();
    Game::get_instance()->show();
}

