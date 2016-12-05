#include "github.h"
#include "ui_github.h"

github::github(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::github)
{
    ui->setupUi(this);
}

github::~github()
{
    delete ui;
}
