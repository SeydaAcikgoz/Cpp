#ifndef ETIKET_H
#define ETIKET_H

#include <QLabel>
#include <QMouseEvent>

class MainWindow;   //MAinWindow by classta tanıtılmış oldu

class etiket : public QLabel
{
    Q_OBJECT
public:
    explicit etiket(MainWindow *frm, QWidget *parent = nullptr);

private:
    void mousePressEvent(QMouseEvent*);
    QTimer *zaman;
    bool hareketKontrol;

private slots:
    void hareketlendir();

signals:

};

#endif // ETIKET_H
