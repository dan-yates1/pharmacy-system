#include "createprescription.h"
#include "ui_createprescription.h"
#include "prescription.h"

CreatePrescription::CreatePrescription(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreatePrescription)
{
    ui->setupUi(this);
}

CreatePrescription::~CreatePrescription()
{
    delete ui;
}

void CreatePrescription::on_createPrescriptionButton_clicked()
{
    // get patient id from text label
    int patient_id = ui->patientIdEdit->text().toInt();
    // create prescription object
    Prescription *p = new Prescription();
}
