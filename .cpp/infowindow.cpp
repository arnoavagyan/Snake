#include "infowindow.h"
#include "ui_infowindow.h"

InfoWindow::InfoWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::InfoWindow)
{
    setWindowTitle("INTRO");
    ui->setupUi(this);
}

InfoWindow::~InfoWindow()
{
    delete ui;
}
