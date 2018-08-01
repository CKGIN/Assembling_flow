#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if(Amotnet_init())  return;

    if(ring_init())     return;

    if(Xshift_init())   return;

    if(Yshift_init())   return;

    if(Zshift_init())   return;

    if(Xtilt_init())    return;

    if(Ytilt_init())    return;

    if(Rotate_init())   return;

    if(Xglue_init())    return;

    if(Yglue_init())    return;

    if(m_RingNo)    return;
}
