#ifndef MODESWINDOW_H
#define MODESWINDOW_H

#include <QMainWindow>
//int sp;

namespace Ui {
class ModesWindow;
}

class ModesWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ModesWindow(QWidget *parent = nullptr);
    ~ModesWindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();

    void on_start_button_clicked();

private:
    Ui::ModesWindow *ui;
};

#endif // MODESWINDOW_H
