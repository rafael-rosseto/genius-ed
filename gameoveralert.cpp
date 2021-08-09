#include "gameoveralert.h"
#include "ui_gameoveralert.h"

GameOverAlert::GameOverAlert(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameOverAlert)
{
    ui->setupUi(this);
}

GameOverAlert::~GameOverAlert()
{
    delete ui;
}

void GameOverAlert::on_botaoOk_clicked()
{
    this->close();
}

