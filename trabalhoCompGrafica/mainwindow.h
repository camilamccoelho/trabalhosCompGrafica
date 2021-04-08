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
    void on_actionAbrir_triggered();

    void on_actionSair_triggered();

    void on_actionSobre_triggered();

    void on_pushButton_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_actionSalvar_triggered();

    void on_horizontalSlider_R_valueChanged(int value);

    void on_botaoAbrir_clicked();

    void on_botaoSalvar_clicked();

    void on_botaoAbrir_2_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
