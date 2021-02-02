#include "createprescription.h"
#include "ui_createprescription.h"
#include "prescription.h"

CreatePrescription::CreatePrescription(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreatePrescription)
{
    ui->setupUi(this);
    // update list of medications upon class initialization
    UpdateMedications();
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
}

void CreatePrescription::UpdatePatients()
{
    // TODO: populate patients combo box via database/csv file
}

void CreatePrescription::on_createPrescriptionButton_clicked()
{
    // TODO: add yes/no dialog box to see if the prescription information is correct
    int patient_id = ui->patientIdEdit->text().toInt();
    // create prescription object
    Prescription *p = new Prescription();
    // insert data from form into prescription object
    p->set_prescription_type(ui->prescriptionTypeComboBox->currentText());
    p->set_start_date(ui->startDateEdit->date());
    p->set_end_date(ui->endDateEdit->date());
    // get drug id
    Medication *m = new Medication();
    p->set_drug_id(m->get_id(ui->medTypeComboBox->currentText()));
    QMessageBox::information(this,"Notification",QString("Prescription for %1 created").arg(ui->medTypeComboBox->currentText()));

    // TODO: add prescription to database
}
