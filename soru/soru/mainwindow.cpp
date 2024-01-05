#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRandomGenerator>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{

    mermi *mer = new mermi(this, this);
    mer->setGeometry(event->pos().x(), event->pos().y(), 10,20);
    mer->show();
}


void MainWindow::on_pushButton_clicked()
{
    for (int i = 0; i < ui->lineEdit->text().toInt(); ++i) {
        hedef *hed = new hedef(this);
        hed->setGeometry(QRandomGenerator::global()->bounded(100,this->width() - 40), QRandomGenerator::global()->bounded(5,round(height() / 3)), 40, 40);
        hed->show();
        hedefler.push_back(hed);
    }
}

void MainWindow::kontrol(mermi *m)
{
    for (int i = 0; i < hedefler.size(); ++i) {
        if (hedefler[i] != nullptr) {
            if (((m->x() > hedefler[i]->x()) && (m->x() < hedefler[i]->x() + hedefler[i]->width())) ||
                    ((m->x() + m->width() > hedefler[i]->x()) && (m->x() + m->width() < hedefler[i]->x() + hedefler[i]->width()))) {
                if (m->y() < hedefler[i]->y() + hedefler[i]->height()) {
                    delete hedefler[i];
                    hedefler[i] = nullptr;
                }
            }
        }
    }
}
