#ifndef GAMEOVERALERT_H
#define GAMEOVERALERT_H

#include <QDialog>

namespace Ui {
class GameOverAlert;
}

class GameOverAlert : public QDialog
{
    Q_OBJECT

public:
    explicit GameOverAlert(QWidget *parent = nullptr);
    ~GameOverAlert();

private slots:
    void on_botaoOk_clicked();

private:
    Ui::GameOverAlert *ui;
};

#endif // GAMEOVERALERT_H
