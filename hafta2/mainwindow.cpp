#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);//bu sınıf içinde ui yı çalıştır
    ui->label->setText("Ne yazsam");//form açılırken label içine bunu yazar
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ilkbuton_clicked()
{
    ui->label->setText("Merhaba Dünya");
}


void MainWindow::on_pushButton_clicked()
{
    ui->ilkbuton->setText(ui->label->text());
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->label_2->setText(QString::number(ui->sayi1->text().toInt()+ui->sayi2->text().toInt()));
    //QString::number->QString içindeki number metodu
}

