#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase> //veritabanı için ekle
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlQueryModel>


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

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
     QSqlDatabase db;
     QSqlQuery *sorgu;
     QSqlQueryModel *model;
     QSqlQuery *sorguliste;
     QSqlQueryModel *modelliste;
     QSqlQuery *genel;  //Bu soruguyu udate gibi durumlsrda kullanıca bzie değer döndürmediği için modele gerek yok.

};
#endif // MAINWINDOW_H
