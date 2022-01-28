#include "homewindow.h"
#include "ui_homewindow.h"
#include "modeswindow.h"
#include "ui_modeswindow.h"
#include "infowindow.h"
#include "ui_infowindow.h"

HomeWindow::HomeWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HomeWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Qt/snake_from_console/Picture/snake_left.jpg");
    ui->label_3->setPixmap(pix);
    QPixmap pix2("C:/Qt/snake_from_console/Picture/snake_right.jpg");
    ui->label_2->setPixmap(pix2);

}

HomeWindow::~HomeWindow()
{
    delete ui;
}
void HomeWindow::on_pushButton_clicked()
{
    hide();
    ModesWindow* wind=new ModesWindow();
    wind->setWindowTitle("Modes");
    wind->show();
}

void HomeWindow::on_pushButton_2_clicked()
{
    InfoWindow* wind=new InfoWindow();
    wind->setWindowTitle("INFO");
    wind->show();
}

void HomeWindow::on_pushButton_3_clicked()
{
   QMessageBox::information(this,tr("About Us"),tr("This game is made by Arno, Sevada and Ruben. You can leave your feedback here: avagyan_arno@student.rau.am"));


}

