#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>      //uygulamada yer alan kütüphaneler bu şekilde eklenir
#include "dugme.h"      //kendi oluşturduğumuz kütüphaneler bu şekilde eklenir

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
