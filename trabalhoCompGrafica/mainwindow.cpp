#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qmessagebox.h"
#include <QFileDialog>
#include <QImage>
#include <QBuffer>
#include <QPushButton>


QString arquivoAberto;
QString arquivoSalvo;
QImage imagem;
float escala;



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;

}




void MainWindow::on_botaoAbrir_clicked()
{

    arquivoAberto = QFileDialog::getOpenFileName(this,
        tr("Abrir Imagem"));

     imagem.load(arquivoAberto);

     imagem.scaled(100,100,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);

      ui->label->setPixmap((QPixmap::fromImage(imagem)).scaled(ui->label->geometry().width(),ui->label->geometry().height(),Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation));


}

void MainWindow::on_horizontalSlider_valueChanged(int value)

{
    escala = value/100.0;
    ui->label->setPixmap((QPixmap::fromImage(imagem)).scaled(ui->label->geometry().width()*escala,ui->label->geometry().height()*escala,Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation));

}




void MainWindow::on_botaoSalvar_clicked()
{
    arquivoSalvo = QFileDialog::getSaveFileName(this,
     tr("Salvar Imagem"),nullptr,"*.JPG",nullptr);
    QImage imagemTmp(imagem.scaled(ui->label->geometry().width()*escala,ui->label->geometry().height()*escala,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    imagemTmp.save(arquivoSalvo,nullptr,80);

}

