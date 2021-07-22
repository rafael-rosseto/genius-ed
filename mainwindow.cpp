#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>
/*
setStyleSheet("QPushButton" "{" "background-color : lightblue;" "}"
              "QPushButton::pressed" "{" "background-color : red;" "}"
             );*/

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

    ui->amarelo->setStyleSheet("QPushButton" "{" "background-color : rgb(240,240,0);" "}"
                               "QPushButton::pressed" "{" "background-color : rgb(255,255,150);" "}"
                              );
    ui->verde->setStyleSheet("QPushButton" "{" "background-color : green;" "}"
                             "QPushButton::pressed" "{" "background-color : rgb(150,255,150);" "}"
                            );
    ui->vermelho->setStyleSheet("QPushButton" "{" "background: red;" "}"
                                "QPushButton::pressed" "{" "background: rgb(255,150,150);" "}"
                               );
    ui->azul->setStyleSheet("QPushButton" "{" "background-color : blue;" "}"
                            "QPushButton::pressed" "{" "background-color : rgb(150,150,255);" "}"
                           );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_play_clicked()
{
    ui->play->clearFocus();

    delay(800);

    for(int i = 1; i <= level; i++)
    {
        srand(time(0));
        int aux = rand() % 4;
        if(aux == 0)
        {
            ui->amarelo->setStyleSheet("background: rgb(255,255,150)");
            delay(600);
            ui->amarelo->setStyleSheet("QPushButton" "{" "background-color : rgb(240,240,0);" "}"
                                       "QPushButton::pressed" "{" "background-color : rgb(255,255,150);" "}"
                                      );
        }
        else if(aux == 1)
        {
            ui->verde->setStyleSheet("background: rgb(150,255,150)");
            delay(600);
            ui->verde->setStyleSheet("QPushButton" "{" "background-color : green;" "}"
                                     "QPushButton::pressed" "{" "background-color : rgb(150,255,150);" "}"
                                    );
        }
        else if(aux == 2)
        {
            ui->vermelho->setStyleSheet("background: rgb(255,150,150)");
            delay(600);
            ui->vermelho->setStyleSheet("QPushButton" "{" "background: red;" "}"
                                        "QPushButton::pressed" "{" "background: rgb(255,100,100);" "}"
                                       );
        }
        else
        {
            ui->azul->setStyleSheet("background: rgb(150,150,255)");
            delay(600);
            ui->azul->setStyleSheet("QPushButton" "{" "background-color : blue;" "}"
                                    "QPushButton::pressed" "{" "background-color : rgb(150,150,255);" "}"
                                   );
        }
        delay(600);
    }
}


void MainWindow::on_reset_clicked()
{
    ui->reset->clearFocus();
}
