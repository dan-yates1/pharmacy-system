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
}

void MainWindow::on_createPrescriptionButton_clicked()
{
    CreatePrescription createPrescription;
    createPrescription.setModal(true);
    createPrescription.exec();
}
