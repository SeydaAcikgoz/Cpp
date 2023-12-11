#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDragEnterEvent>
#include <QDropEvent>
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

    void on_actionYeni_triggered();

    void on_actionAc_triggered();

    void on_actionKaydet_triggered();

    void on_actionFarkl_Kaydet_triggered();

private:
    Ui::MainWindow *ui;
    void dosyaAc();
    void dosyaKaydet();
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);
    QString yol;
};
#endif // MAINWINDOW_H
