#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>

int level = 3;

void delay(int miliseconds)
{
    QTime dieTime= QTime::currentTime().addMSecs(miliseconds);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->play->clearFocus();

    ui->amarelo->setStyleSheet("background: yellow");
    ui->verde->setStyleSheet("background: green");
    ui->vermelho->setStyleSheet("background: red");
    ui->azul->setStyleSheet("background: blue");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_play_clicked()
{
    ui->play->clearFocus();

    ui->amarelo->setStyleSheet("background: palette(window)");
    ui->verde->setStyleSheet("background: palette(window)");
    ui->vermelho->setStyleSheet("background: palette(window)");
    ui->azul->setStyleSheet("background: palette(window)");

    delay(800);

    for(int i = 1; i <= level; i++)
    {
        //for(int j = 1; j <= i; j++)
        //{
            srand(time(0));
            int aux = rand() % 4;
            if(aux == 0)
            {
                ui->amarelo->setStyleSheet("background: yellow");
                delay(600);
                ui->amarelo->setStyleSheet("background: palette(window)");
            }
            else if(aux == 1)
            {
                ui->verde->setStyleSheet("background: green");
                delay(600);
                ui->verde->setStyleSheet("background: palette(window)");
            }
            else if(aux == 2)
            {
                ui->vermelho->setStyleSheet("background: red");
                delay(600);
                ui->vermelho->setStyleSheet("background: palette(window)");
            }
            else
            {
                ui->azul->setStyleSheet("background: blue");
                delay(600);
                ui->azul->setStyleSheet("background: palette(window)");
            }
            delay(600);
        //}
    }
}


void MainWindow::on_reset_clicked()
{
    ui->reset->clearFocus();
    ui->amarelo->setStyleSheet("background: yellow");
    ui->verde->setStyleSheet("background: green");
    ui->vermelho->setStyleSheet("background: red");
    ui->azul->setStyleSheet("background: blue");
}


void MainWindow::on_amarelo_pressed()
{
    ui->amarelo->setStyleSheet("background: yellow");
}


void MainWindow::on_amarelo_released()
{
    ui->amarelo->setStyleSheet("background: palette(window)");
}

