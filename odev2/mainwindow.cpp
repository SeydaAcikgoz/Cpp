#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    vurulanSayisi = 0;
    kacanSayisi = 0;
    QTimer *ordekUret = new QTimer(this);
    connect(ordekUret, SIGNAL(timeout()), this, SLOT(ordekuret()));
    ordekUret->start(500);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::vurulaniEkranaBas()
{
    ui->label_3->setText(QString::number(vurulanSayisi++));
}

void MainWindow::kacaniEkranaBas()
{
    ui->label_5->setText(QString::number(kacanSayisi++));
}

void MainWindow::ordekuret()
{
    ordek *ordekler = new ordek(this, ui->label);
}

