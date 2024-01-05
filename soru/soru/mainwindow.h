#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "hedef.h"
#include "mermi.h"
#include <QMouseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void mousePressEvent(QMouseEvent *event);
    void kontrol(mermi *m);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QList<hedef*> hedefler;

};
#endif // MAINWINDOW_H
