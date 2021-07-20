#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>

int level = 1;

void delay(int seconds)
{
    QTime dieTime= QTime::currentTime().addSecs(seconds);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->play->clearFocus();

    QPalette amarelo = ui->amarelo->palette();
    QPalette verde = ui->verde->palette();
    QPalette vermelho = ui->vermelho->palette();
    QPalette azul = ui->azul->palette();
    amarelo.setColor(QPalette::Button, Qt::yellow);
    ui->amarelo->setAutoFillBackground(true);
    ui->amarelo->setPalette(amarelo);
    ui->amarelo->show();
    verde.setColor(QPalette::Button, Qt::green);
    ui->verde->setAutoFillBackground(true);
    ui->verde->setPalette(verde);
    ui->verde->show();
    vermelho.setColor(QPalette::Button, Qt::red);
    ui->vermelho->setAutoFillBackground(true);
    ui->vermelho->setPalette(vermelho);
    ui->vermelho->show();
    azul.setColor(QPalette::Button, Qt::blue);
    ui->azul->setAutoFillBackground(true);
    ui->azul->setPalette(azul);
    ui->azul->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_play_clicked()
{
    ui->play->clearFocus();
}


void MainWindow::on_reset_clicked()
{
    ui->reset->clearFocus();
}


void MainWindow::on_amarelo_clicked()
{
    ui->amarelo->clearFocus();
}


void MainWindow::on_verde_clicked()
{
    ui->verde->clearFocus();
}


void MainWindow::on_vermelho_clicked()
{
    ui->vermelho->clearFocus();
}


void MainWindow::on_azul_clicked()
{
    ui->azul->clearFocus();
}

