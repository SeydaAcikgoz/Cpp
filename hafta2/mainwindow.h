#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);  //yapıcı metot(parantez içi->nesne içinde nesne üretmek için)
    ~MainWindow(); //yıkıcı metot->en fazla bir tane olabilir(form uygulamalarında genelde yazılır)

private slots:
    void on_ilkbuton_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui; //Ui sınıfından MainWindow metodundan ui değişkeni
};
#endif // MAINWINDOW_H
