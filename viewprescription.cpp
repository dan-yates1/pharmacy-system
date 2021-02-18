#include "viewprescription.h"
#include "ui_viewprescription.h"
#include "database.h"
#include "prescriptiontablemodel.h"

viewPrescription::viewPrescription(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::viewPrescription)
{
    ui->setupUi(this);
    populateList();
}

viewPrescription::~viewPrescription()
{
    delete ui;
}

void viewPrescription::populateList()
{
    Database db;
    QList<Prescription> prescriptionList = db.GetPrescription();
    QStringList medList;
    QStringList idList;
    QStringList startDateList;
    QStringList endDateList;

    QList<Prescription>::iterator iter = prescriptionList.begin();
    while(iter != prescriptionList.end()){
        Prescription& p = *iter;
        QString id = db.GetPatient(p.get_patient_id());
        idList << id;
        QString med = p.get_drug();
        medList << med;
        QString sdate = p.get_start_date().toString("dd-MM-yyyy");
        startDateList << sdate;
        QString edate = p.get_end_date().toString("dd-MM-yyyy");
        endDateList << edate;
        iter++;
    }

    prescriptionTableModel *PrescriptionModel = new prescriptionTableModel(this);
    PrescriptionModel->populateData(idList, medList, startDateList, endDateList);
    ui->tableView->setModel(PrescriptionModel);
    ui->tableView->horizontalHeader()->setDefaultSectionSize(150);
    ui->tableView->horizontalHeader()->setVisible(true);
    ui->tableView->show();
}
