#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase> //veritabanı için ekle
#include <QSqlQuery>    //sorgu yazılacak değişkenin tipi
#include <QSqlQueryModel>   //sorgu sonucu dönünce alınacak değişkenin veri tipi

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

    void on_aranacak_returnPressed();

    void on_aranacak_textChanged(const QString &arg1);

    void on_tableView_clicked(const QModelIndex &index);

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QSqlQuery *sorgu;
    QSqlQueryModel *model;
    void listele();
    QString veri;

};
#endif // MAINWINDOW_H
