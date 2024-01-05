#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ordek.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int vurulanSayisi, kacanSayisi;
    void vurulaniEkranaBas();
    void kacaniEkranaBas();

private slots:
     void ordekuret();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
