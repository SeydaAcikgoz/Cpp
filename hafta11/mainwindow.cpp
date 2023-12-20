#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    int X=50;
    int Y=50;

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            etiket *et=new etiket(this);
            et->setGeometry(X,Y,100,100);
            et->show();
            X+=130;
        }
        X=50;
        Y+=130;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

