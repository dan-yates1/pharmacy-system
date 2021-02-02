#include "createprescription.h"
#include "ui_createprescription.h"
#include "prescription.h"

CreatePrescription::CreatePrescription(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreatePrescription)
{
    ui->setupUi(this);
    UpdateMedications();
}

CreatePrescription::~CreatePrescription()
{
    delete ui;
}

void CreatePrescription::UpdateMedications()
{
    // create medication object and populate combo box
    Medication *m = new Medication();
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
    // check if dates are valid
    if(ui->startDateEdit < ui->endDateEdit)
    {
        int patient_id = ui->patientIdEdit->text().toInt();
        // create prescription object
        Prescription *p = new Prescription();
        // get data from form into object
        p->set_prescription_type(ui->prescriptionTypeComboBox->currentText());
        p->set_start_date(ui->startDateEdit->date());
        // convert QDate object to string
        //QString date = test.toString("dd.MM.yyyy");
        p->set_end_date(ui->endDateEdit->date());
    } else QMessageBox::warning(this,"Invalid input","Make sure that the start date is before the end date");
}
