#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "QLineEdit"
#include "QLabel"

#include <QMainWindow>

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

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QVector<QLabel*>etiketler;  //mainwindow.cpp de farklı fonksiyonlarda kullanmak istediğim için global tanımlamam lazım
    QVector<QLineEdit*>editler; //header dosyasında global değişkenler tanımlanır
};
#endif // MAINWINDOW_H
