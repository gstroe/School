#ifndef OPENREQ_H
#define OPENREQ_H

#include <QWidget>

namespace Ui {
class openReq;
}

class openReq : public QWidget
{
    Q_OBJECT

public:
    explicit openReq(QWidget *parent = 0);
    ~openReq();
    void setLabel(QString label);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::openReq *ui;
};

#endif // OPENREQ_H
