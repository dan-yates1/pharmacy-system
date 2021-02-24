#include "expiredview.h"
#include "ui_expiredview.h"
#include "database.h"
#include "prescription.h"
#include "prescriptiontablemodel.h"
#include "bloodwork.h"
#include "bloodworktablemodel.h"
#include <QDebug>

ExpiredView::ExpiredView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExpiredView)
{
    ui->setupUi(this);
    PopulatePrescriptions();
    PopulateBloodwork();
}

ExpiredView::~ExpiredView()
{
    delete ui;
}

void ExpiredView::PopulatePrescriptions()
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
        if (p.get_end_date() < QDate::currentDate())
        {
            QString id = db.GetPatient(p.get_patient_id());
            idList << id;
            QString med = p.get_drug();
            medList << med;
            QString sdate = p.get_start_date().toString("dd-MM-yyyy");
            startDateList << sdate;
            QString edate = p.get_end_date().toString("dd-MM-yyyy");
            endDateList << edate;
        }
        iter++;
    }

    prescriptionTableModel *PrescriptionModel = new prescriptionTableModel(this);
    PrescriptionModel->populateData(idList, medList, startDateList, endDateList);
    ui->pTableView->setModel(PrescriptionModel);
    ui->pTableView->horizontalHeader()->setDefaultSectionSize(150);
    ui->pTableView->horizontalHeader()->setVisible(true);
    ui->pTableView->show();
}

void ExpiredView::PopulateBloodwork()
{
    Database db;
    QList<Bloodwork> bloodworkList = db.GetBloodwork();
    QStringList reasonList;
    QStringList idList;
    QStringList dateList;

    QList<Bloodwork>::iterator iter = bloodworkList.begin();
    while(iter != bloodworkList.end()){
        Bloodwork& b = *iter;
        if (b.get_date() < QDate::currentDate())
        {
            QString id = db.GetPatient(b.get_patient_id());
            idList << id;
            QString reason = b.get_reason();
            reasonList << reason;
            QString date = b.get_date().toString("dd-MM-yyyy");
            dateList << date;
            qDebug() << date;
        }
        iter++;
    }

    bloodworkTableModel *BloodworkModel = new bloodworkTableModel(this);
    BloodworkModel->populateData(idList, reasonList, dateList);
    ui->bTableView->setModel(BloodworkModel);
    ui->bTableView->horizontalHeader()->setDefaultSectionSize(150);
    ui->bTableView->horizontalHeader()->setVisible(true);
    ui->bTableView->show();
}
