#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPalette painel = ui->painel->palette();
    QPalette amarelo = ui->amarelo->palette();
    QPalette verde = ui->verde->palette();
    QPalette vermelho = ui->vermelho->palette();
    QPalette azul = ui->azul->palette();

    // set black background on panel
    painel.setColor(QPalette::Background, Qt::black);
    ui->painel->setAutoFillBackground(true);
    ui->painel->setPalette(painel);
    ui->painel->show();

    // set colored background on buttons
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

