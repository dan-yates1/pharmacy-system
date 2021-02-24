#include "mainscreen.h"
#include "ui_mainscreen.h"
#include "createprescription.h"
#include "createbloodwork.h"
#include "createuser.h"
#include "calendarview.h"
#include "viewbloodwork.h"
#include "viewprescription.h"
#include "viewusers.h"
#include "expiredview.h"

MainScreen::MainScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainScreen)
{
    //QList<Bloodwork> expired_bw = GetExpiredBw();
    ui->setupUi(this);
}

MainScreen::~MainScreen()
{
    delete ui;
}

QList<Bloodwork> MainScreen::GetExpiredBw()
{
    Database db;
    QList<Bloodwork> bw_list = db.GetBloodwork();
}

QList<Prescription> MainScreen::GetExpiredPres()
{
    Database db;
    QList<Prescription> pres_list = db.GetExpiredPrescription(today_date_);
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
    viewPrescription view_prescription;
    view_prescription.setWindowTitle("View Prescriptions");
    view_prescription.setWindowIcon(QIcon(":/icons/window-icon.svg"));
    view_prescription.setModal(true);
    view_prescription.exec();
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
    viewUsers view_user;
    view_user.setWindowTitle("View Users");
    view_user.setWindowIcon(QIcon(":/icons/window-icon.svg"));
    view_user.setModal(true);
    view_user.exec();
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

void MainScreen::on_viewBloodworkButton_clicked()
{
    viewBloodwork view_bloodwork;
    view_bloodwork.setWindowTitle("View Bloodwork");
    view_bloodwork.setWindowIcon(QIcon(":/icons/window-icon.svg"));
    view_bloodwork.setModal(true);
    view_bloodwork.exec();
}

void MainScreen::on_expiredButton_clicked()
{
    ExpiredView e;
    e.setWindowTitle("Expired Bloodwork/Prescriptions");
    e.setModal(true);
    e.exec();
}
