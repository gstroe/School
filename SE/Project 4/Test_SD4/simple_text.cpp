#include "simple_text.h"
#include "ui_simple_text.h"

simple_text::simple_text(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::simple_text)
{
    ui->setupUi(this);
}

simple_text::~simple_text()
{
    delete ui;
}
