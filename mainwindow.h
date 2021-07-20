#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_play_clicked();

    void on_reset_clicked();

    void on_amarelo_clicked();

    void on_verde_clicked();

    void on_vermelho_clicked();

    void on_azul_clicked();

    void on_amarelo_released();

    void on_amarelo_pressed();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
