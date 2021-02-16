#include "mainscreen.h"
#include "ui_mainscreen.h"
#include "createprescription.h"
#include "createbloodwork.h"
#include "createuser.h"
#include "calendarview.h"

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
    create_prescription.setWindowTitle("Create Prescription");
    create_prescription.setWindowIcon(QIcon(":/icons/window-icon.svg"));
    create_prescription.setModal(true);
    create_prescription.exec();
}

void MainScreen::on_createUserButton_clicked()
{
    CreateUser create_user;
    create_user.setWindowTitle("Create User");
    create_user.setWindowIcon(QIcon(":/icons/window-icon.svg"));
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
    create_bloodwork.setWindowTitle("Book Bloodwork");
    create_bloodwork.setWindowIcon(QIcon(":/icons/window-icon.svg"));
    create_bloodwork.setModal(true);
    create_bloodwork.exec();
}

void MainScreen::on_viewUsersButton_clicked()
{
    // TODO:
}

void MainScreen::on_calendarWidget_clicked(const QDate &date)
{
    CalendarView cv;
    cv.set_selected_date(date);
    cv.setWindowTitle("Calendar");
    cv.setWindowIcon(QIcon(":/icons/calendar-icon.png"));
    cv.PopulateListView(date);
    cv.set_label(date.toString("dd-MM-yyyy"));
    cv.setModal(true);
    cv.exec();
}

void MainScreen::on_exitButton_clicked()
{
    this->close();
}
