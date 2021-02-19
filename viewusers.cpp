#include "viewusers.h"
#include "ui_viewusers.h"
#include "database.h"
#include "usertablemodel.h"

viewUsers::viewUsers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::viewUsers)
{
    ui->setupUi(this);
    populateList();
}

viewUsers::~viewUsers()
{
    delete ui;
}

void viewUsers::populateList()
{
    Database db;
    QList<Patient> patientList = db.GetPatients();
    QStringList fNameList;
    QStringList lNameList;
    QStringList dobList;

    QList<Patient>::iterator iter = patientList.begin();
    while(iter != patientList.end()){
        Patient& p = *iter;
        QString fName = p.get_fname();
        fNameList << fName;
        QString lName = p.get_lname();
        lNameList << lName;
        QString dob = p.get_dob().toString("dd-MM-yyyy");
        dobList << dob;
        iter++;
    }

    userTableModel *PatientModel = new userTableModel(this);
    PatientModel->populateData(fNameList, lNameList, dobList);
    ui->tableView->setModel(PatientModel);
    ui->tableView->horizontalHeader()->setDefaultSectionSize(150);
    ui->tableView->horizontalHeader()->setVisible(true);
    ui->tableView->show();
}
