#include "mainscreen.h"
#include "ui_mainscreen.h"
#include "createprescription.h"
#include "createbloodwork.h"
#include "createuser.h"
#include "calendarmanager.h"

MainScreen::MainScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainScreen)
{
    ui->setupUi(this);
}

MainScreen::~MainScreen()
{
    delete ui;
}

void MainScreen::on_createPrescriptionButton_clicked()
{
    CreatePrescription create_prescription;
    create_prescription.setWindowTitle("Pharmacy App - Create Prescription");
    create_prescription.setModal(true);
    create_prescription.exec();
}

void MainScreen::on_createUserButton_clicked()
{
    CreateUser create_user;
    create_user.setWindowTitle("Pharmacy App - Create User");
    create_user.setModal(true);
    create_user.exec();
}

void MainScreen::on_viewPrescriptionButton_clicked()
{
    // TODO:
}

void MainScreen::on_bookBloodworkButton_clicked()
{
    CreateBloodwork create_bloodwork;
    create_bloodwork.setWindowTitle("Pharmacy App - Book Bloodwork");
    create_bloodwork.setModal(true);
    create_bloodwork.exec();
}

void MainScreen::on_viewUsersButton_clicked()
{

}

void MainScreen::on_calendarWidget_clicked(const QDate &date)
{
    CalendarManager cm;
    cm.set_selected_date(date);
}
