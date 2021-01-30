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
    int patient_id = ui->patientIdEdit->text().toInt();
    QString prescription_type = ui->prescriptionTypeComboBox->currentText();

    Prescription *p = new Prescription();
    p->set_prescription_type(prescription_type);
}
