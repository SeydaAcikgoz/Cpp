#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "etiket.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void kontrol(etiket *);

private:
    Ui::MainWindow *ui;
    QList<int> sirala(QList<int>, QList<int>);
    etiket *ilk;
    int sayac;
};

#endif // MAINWINDOW_H
