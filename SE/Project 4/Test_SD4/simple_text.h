#ifndef SIMPLE_TEXT_H
#define SIMPLE_TEXT_H

#include <QWidget>

namespace Ui {
class simple_text;
}

class simple_text : public QWidget
{
    Q_OBJECT

public:
    explicit simple_text(QWidget *parent = 0);
    ~simple_text();

private:
    Ui::simple_text *ui;
};

#endif // SIMPLE_TEXT_H
