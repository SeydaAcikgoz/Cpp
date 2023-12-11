#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include "dugme.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //void mousePressEvent(QMouseEvent*event);//replemant metot->her nesne üzerinde bu metot yazılabilir(zaten bu metotlar hazır)
   // void mouseMoveEvent(QMouseEvent *event);//replemant metot(yapıcı metot,formun boyutunu büyütme ve update işlemlerinde çalışır)
    void paintEvent(QPaintEvent *event);
    void butonBagla();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QPoint ilkNokta, ikinciNokta;
    int kontrol;
    QLine cizgi;
    QVector<QLine> cizgiler;
    QVector<QPoint> noktalar;
   // void cizgiciz();
    QVector<dugme*> butonlar;
};
#endif // MAINWINDOW_H





