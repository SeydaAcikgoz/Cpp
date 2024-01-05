#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase> //veritabanı için ekle
#include <QSqlTableModel>

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

    void on_tableView_2_clicked(const QModelIndex &index);

    void on_Notlarikaydet_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QSqlTableModel *tablemodel;
    QSqlQuery *ogrenciler;
    QSqlQuery *notlari;
    QSqlQueryModel *ogrmodel;
    QSqlQueryModel *notlarmodel;
    QString numara;
    void notListele();

};
#endif // MAINWINDOW_H
