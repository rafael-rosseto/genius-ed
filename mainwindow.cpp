#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "estruturas.h"
#include <QTime>


FILA *output = (FILA*) malloc(sizeof(FILA));
FILA *input =  (FILA*) malloc(sizeof(FILA));
NO_FILA *aux = (NO_FILA*) malloc(sizeof(NO_FILA));

void delay(int miliseconds)
{
    QTime dieTime = QTime::currentTime().addMSecs(miliseconds);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand(time(NULL));
    ui->play->clearFocus();

    // DefoutputInir cores dos botões
    ui->amarelo->setStyleSheet("QPushButton"
                               "{"
                               "background-color : rgb(240,240,0);"
                               "}"
                               "QPushButton::pressed"
                               "{"
                               "background-color : rgb(255,255,150);"
                               "}");
    ui->verde->setStyleSheet("QPushButton"
                             "{"
                             "background-color : green;"
                             "}"
                             "QPushButton::pressed"
                             "{"
                             "background-color : rgb(150,255,150);"
                             "}");
    ui->vermelho->setStyleSheet("QPushButton"
                                "{"
                                "background: red;"
                                "}"
                                "QPushButton::pressed"
                                "{"
                                "background: rgb(255,150,150);"
                                "}");
    ui->azul->setStyleSheet("QPushButton"
                            "{"
                            "background-color : blue;"
                            "}"
                            "QPushButton::pressed"
                            "{"
                            "background-color : rgb(150,150,255);"
                            "}");
    iniciaFila(output);
    iniciaFila(input);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_play_clicked()
{
    ui->play->clearFocus();

    pushFila(randLuz(), output);

    delay(800);

    aux = output->head;

    for (int i = 1; i <= level; i++)
    {
        if (aux->color == 0)
        {
            ui->amarelo->setStyleSheet("background: rgb(255,255,150)");
            delay(600);
            ui->amarelo->setStyleSheet("QPushButton"
                                       "{"
                                       "background-color : rgb(240,240,0);"
                                       "}"
                                       "QPushButton::pressed"
                                       "{"
                                       "background-color : rgb(255,255,150);"
                                       "}");
        }
        else if (aux->color == 1)
        {
            ui->verde->setStyleSheet("background: rgb(150,255,150)");
            delay(600);
            ui->verde->setStyleSheet("QPushButton"
                                     "{"
                                     "background-color : green;"
                                     "}"
                                     "QPushButton::pressed"
                                     "{"
                                     "background-color : rgb(150,255,150);"
                                     "}");
        }
        else if (aux->color == 2)
        {
            ui->vermelho->setStyleSheet("background: rgb(255,150,150)");
            delay(600);
            ui->vermelho->setStyleSheet("QPushButton"
                                        "{"
                                        "background: red;"
                                        "}"
                                        "QPushButton::pressed"
                                        "{"
                                        "background: rgb(255,150,150);"
                                        "}");
        }
        else
        {
            ui->azul->setStyleSheet("background: rgb(150,150,255)");
            delay(600);
            ui->azul->setStyleSheet("QPushButton"
                                    "{"
                                    "background-color : blue;"
                                    "}"
                                    "QPushButton::pressed"
                                    "{"
                                    "background-color : rgb(150,150,255);"
                                    "}");
        }
        delay(600);
        aux= aux->next;
    }
}

void MainWindow::on_reset_clicked()
{
    ui->reset->clearFocus();
    resetFila(input);
    resetFila(output);
    level = 1;
}

void MainWindow::on_amarelo_clicked()
{
    pushFila(0, input);
    printFila(input);
    cont_glob++;
    if(cont_glob == level)
    {
        if(verificaFila(input, output))
        {
            cont_glob = 0;
            ui->play->animateClick();
            qInfo("verificou");
            level++;
            resetFila(input);
        }
        else
        {
            exit(-1);
        }
    }
}


void MainWindow::on_verde_clicked()
{
    pushFila(1, input);
    printFila(input);
    cont_glob++;
    if(cont_glob == level)
    {
        if(verificaFila(input, output))
        {
            cont_glob = 0;
            ui->play->animateClick();
            qInfo("verificou");
            level++;
            resetFila(input);
        }
        else
        {
            exit(-1);
        }
    }
}


void MainWindow::on_vermelho_clicked()
{
    pushFila(2, input);
    printFila(input);
    cont_glob++;
    if(cont_glob == level)
    {
        if(verificaFila(input, output))
        {
            cont_glob = 0;
            ui->play->animateClick();
            qInfo("verificou");
            level++;
            resetFila(input);
        }
        else
        {
            exit(-1);
        }
    }
}


void MainWindow::on_azul_clicked()
{
    pushFila(3, input);
    printFila(input);
    cont_glob++;
    if(cont_glob == level)
    {
        if(verificaFila(input, output))
        {
            cont_glob = 0;
            ui->play->animateClick();
            qInfo("verificou");
            level++;
            resetFila(input);
        }
        else
        {
            exit(-1);
        }
    }
}

