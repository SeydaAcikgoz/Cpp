#ifndef DUGME_H
#define DUGME_H

#include <QPushButton>
#include <QMouseEvent>

class MainWindow;
class dugme : public QPushButton
{
    Q_OBJECT
public:
    explicit dugme(MainWindow *frm, QWidget *parent = nullptr);

private:
    void mouseMoveEvent(QMouseEvent*event);
    void mousePressEvent(QMouseEvent * event);
    QPoint ilkNokta;
    MainWindow *anafrm;

signals:

};

#endif // DUGME_H
