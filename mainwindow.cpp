#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "patient.h"
#include "createprescription.h"
#include <iostream>

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


void MainWindow::on_homeButton_clicked()
{
    CreatePrescription c;
    c.setModal(true);
    c.exec();
}
