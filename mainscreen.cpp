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
#include <QDesktopServices>
#include <QUrl>
#include <QFileDialog>

MainScreen::MainScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainScreen)
{
    ui->setupUi(this);
    QDate today = QDate::currentDate();
    QTextCharFormat format = ui->calendarWidget->weekdayTextFormat(Qt::Saturday);
    ui->calendarWidget->setDateTextFormat(today, format);
}

MainScreen::~MainScreen()
{
    delete ui;
}

QList<Prescription> MainScreen::GetExpiredPres()
{
}

void MainScreen::on_createPrescriptionButton_clicked()
{
    CreatePrescription create_prescription;
    create_prescription.setWindowTitle("Create Prescription");
    create_prescription.setWindowIcon(QIcon(":/icons/create-prescription.png"));
    create_prescription.setModal(true);
    create_prescription.exec();
}

void MainScreen::on_createUserButton_clicked()
{
    CreateUser create_user;
    create_user.setWindowTitle("Create User");
    create_user.setWindowIcon(QIcon(":/icons/create-user.png"));
    create_user.setModal(true);
    create_user.exec();
}

void MainScreen::on_viewPrescriptionButton_clicked()
{
    viewPrescription view_prescription;
    view_prescription.setWindowTitle("View Prescriptions");
    view_prescription.setWindowIcon(QIcon(":/icons/view-prescription.png"));
    view_prescription.setModal(true);
    view_prescription.exec();
}

void MainScreen::on_bookBloodworkButton_clicked()
{
    CreateBloodwork create_bloodwork;
    create_bloodwork.setWindowTitle("Book Bloodwork");
    create_bloodwork.setWindowIcon(QIcon(":/icons/blooddrop-icon.png"));
    create_bloodwork.setModal(true);
    create_bloodwork.exec();
}

void MainScreen::on_viewUsersButton_clicked()
{
    viewUsers view_user;
    view_user.setWindowTitle("View Users");
    view_user.setWindowIcon(QIcon(":/icons/view-patient.png"));
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
    view_bloodwork.setWindowIcon(QIcon(":/icons/blooddrop-icon.png"));
    view_bloodwork.setModal(true);
    view_bloodwork.exec();
}

void MainScreen::on_expiredButton_clicked()
{
    ExpiredView e;
    e.setWindowTitle("Expired Bloodwork/Prescriptions");
    e.setWindowIcon(QIcon(":/icons/bell-icon.png"));
    e.setModal(true);
    e.exec();
}

void MainScreen::on_expiredButton_2_clicked()
{
    QDir dir;
    QString path = dir.absolutePath();
    path.append("/help.pdf");
    QDesktopServices::openUrl(QUrl::fromLocalFile(path));
}

void MainScreen::on_expiredButton_3_clicked()
{
    // exit application
    this->~MainScreen();
}
