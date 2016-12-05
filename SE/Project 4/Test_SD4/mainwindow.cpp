#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "openreq.h"
#include "github.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pbRequirments_clicked()
{
    openReq* openreq = new openReq;
    openreq->setLabel("Requirments");
    openreq->setAttribute(Qt::WA_DeleteOnClose);
    openreq->show();
}

void MainWindow::on_pbHLD_clicked()
{
    openReq* openreq = new openReq;
    openreq->setLabel("High-Level Design");
    openreq->setAttribute(Qt::WA_DeleteOnClose);
    openreq->show();
}

void MainWindow::on_pbLLD_clicked()
{
    openReq* openreq = new openReq;
    openreq->setLabel("Low-Level Design");
    openreq->setAttribute(Qt::WA_DeleteOnClose);
    openreq->show();
}

void MainWindow::on_pbImplementation_clicked()
{
    github* git = new github;
    git->setAttribute(Qt::WA_DeleteOnClose);
    git->show();
}

void MainWindow::on_pbUnitTest_clicked()
{
    openReq* openreq = new openReq;
    openreq->setLabel("Unit Test");
    openreq->setAttribute(Qt::WA_DeleteOnClose);
    openreq->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    openReq* openreq = new openReq;
    openreq->setLabel("System Test");
    openreq->setAttribute(Qt::WA_DeleteOnClose);
    openreq->show();
}

void MainWindow::on_pushButton_clicked()
{
    openReq* openreq = new openReq;
    openreq->setLabel("Validation Test");
    openreq->setAttribute(Qt::WA_DeleteOnClose);
    openreq->show();
}
