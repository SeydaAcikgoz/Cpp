#ifndef ETIKET_H
#define ETIKET_H

#include <QWidget>
#include <QLabel>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMouseEvent>


class etiket : public QLabel
{
    Q_OBJECT
public:
    explicit etiket(QWidget *parent = nullptr);

private:
    void dragEnterEvent(QDragEnterEvent *event);//sürükleme olayı
    void dropEvent(QDropEvent *event);//bırakma olayı
    void mouseMoveEvent(QMouseEvent *event);


signals:

};

#endif // ETIKET_H
