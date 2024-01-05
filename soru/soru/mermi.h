#ifndef MERMI_H
#define MERMI_H

#include <QPushButton>

class MainWindow;

class mermi : public QPushButton
{
    Q_OBJECT
public:
    explicit mermi(MainWindow *frm, QWidget *parent = nullptr);

signals:

private:
    MainWindow *anafrm;
    int say;

private slots:
    void hareketlendir();

};

#endif // MERMI_H
