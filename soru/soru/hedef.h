#ifndef HEDEF_H
#define HEDEF_H

#include <QPushButton>
#include <QMouseEvent>

class hedef : public QPushButton
{
    Q_OBJECT
public:
    explicit hedef(QWidget *parent = nullptr);

signals:

private:
    QWidget *frm;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    QPoint ilkKonum;

};

#endif // HEDEF_H
