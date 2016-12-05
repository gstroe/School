#include "openreq.h"
#include "ui_openreq.h"

openReq::openReq(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::openReq)
{
    ui->setupUi(this);
    ui->textEdit->setVisible(false);
}

openReq::~openReq()
{
    delete ui;
}

//Edit button
void openReq::on_pushButton_clicked()
{
    ui->textBrowser->setVisible(false);
    ui->textEdit->setVisible(true);
}

//refresh button
void openReq::on_pushButton_2_clicked()
{
    ui->textEdit->setVisible(false);
    ui->textBrowser->setVisible(true);
}

void openReq::setLabel(QString label)
{
    ui->label->setText(label);
}

//new button
void openReq::on_pushButton_3_clicked()
{
    if(ui->comboBox->findText(ui->lineEdit->text()) == -1)
    {
        ui->comboBox->addItem(ui->lineEdit->text());
    }
}
