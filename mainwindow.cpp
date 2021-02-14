#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "patient.h"
#include "createprescription.h"
#include "createuser.h"
#include "createbloodwork.h"
#include <iostream>

// TODO: add functionality to menu bar

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
    CreatePrescription create_prescription;
    create_prescription.setModal(true);
    create_prescription.exec();
}

void MainWindow::on_createUserButton_clicked()
{
    CreateUser create_user;
    create_user.setModal(true);
    create_user.exec();
}

void MainWindow::on_viewPrescriptionButton_clicked()
{
    // TODO:
}

void MainWindow::on_bookBloodworkButton_clicked()
{
    CreateBloodwork create_bloodwork;
    create_bloodwork.setModal(true);
    create_bloodwork.exec();
}
