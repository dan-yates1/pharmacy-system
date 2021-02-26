#include "createprescription.h"
#include "ui_createprescription.h"
#include "prescription.h"
#include "database.h"
#include "createbloodwork.h"
#include "medication.h"
#include <QSqlQuery>
#include <QSqlRecord>

CreatePrescription::CreatePrescription(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreatePrescription)
{
    ui->setupUi(this);
    // update list of medications upon class initialization
    UpdateMedications();
    UpdatePatients();
    ui->startDateEdit->setDate(QDate::currentDate());
    ui->endDateEdit->setDate(QDate::currentDate().addMonths(1));
}

CreatePrescription::~CreatePrescription()
{
    delete ui;
}

void CreatePrescription::UpdateMedications()
{
    // create medication object and get list of medication names
    Medication *m = new Medication();
    // loop through vector and populate combo box
    QVector<QString> medication_list = m->get_names();
    for(int i =0; i < medication_list.size(); i++)
    {
        ui->medTypeComboBox->addItem(medication_list[i]);
    }
    delete m;
}

void CreatePrescription::UpdatePatients()
{
    Database db;

    QSqlQuery query("SELECT * FROM patient");
    int fnameIndex = query.record().indexOf("first_name");
    int lnameIndex = query.record().indexOf("last_name");
    while (query.next())
    {
        QString fname = query.value(fnameIndex).toString();
        QString lname = query.value(lnameIndex).toString();
        QString name = fname + ' ' + lname;
        ui->comboBox->addItem(name);
    }
}

Prescription CreatePrescription::PopulatePrescription()
{
    Prescription p;
    // insert data from form into prescription object
    p.set_patient_id(ui->comboBox->currentIndex()+1);
    p.set_prescription_type(ui->prescriptionTypeComboBox->currentText());
    p.set_start_date(ui->startDateEdit->date());
    p.set_end_date(ui->endDateEdit->date());
    // get drug id
    Medication m;
    p.set_drug_id(m.get_id(ui->medTypeComboBox->currentText()));
    p.set_drug(ui->medTypeComboBox->currentText());
    return p;
}

void CreatePrescription::on_createPrescriptionButton_clicked()
{
    // TODO: add yes/no dialog box to see if the prescription information is correct
    // TODO: perform validation on inputs and check for missing entries

    // create prescription object
    Prescription p = PopulatePrescription();
    // check if medication requires bloodwork
    Medication m;
    if(m.get_access(p.get_drug_id()) >= 3)
    {
        QMessageBox::information(this,"Notification","Additional bloodwork requried for following medication");
        CreateBloodwork create_bloodwork;
        create_bloodwork.setWindowTitle("Book Bloodwork");
        create_bloodwork.setWindowIcon(QIcon(":/icons/blooddrop-icon.png"));
        create_bloodwork.setModal(true);
        create_bloodwork.exec();
        create_bloodwork.set_patient(p.get_patient_id());
    }

    Database db;
    db.InsertPrescription(p);

    QMessageBox::information(this,"Notification",QString("Prescription for %1 created").arg(ui->medTypeComboBox->currentText()));
}
