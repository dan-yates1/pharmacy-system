#include "createprescription.h"
#include "ui_createprescription.h"
#include "prescription.h"

CreatePrescription::CreatePrescription(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreatePrescription)
{
    ui->setupUi(this);
    // populate medications combo box via text file
    QFile file("C:\\Users\\Dan\\Test\\drugs.txt");
    if(file.open(QIODevice::ReadOnly))
    {
        QTextStream in(&file);
        while(!in.atEnd())
        {
            QString line = in.readLine();
            ui->medTypeComboBox->addItem(line);
        }
        file.close();
    }
}

CreatePrescription::~CreatePrescription()
{
    delete ui;
}

void CreatePrescription::on_createPrescriptionButton_clicked()
{
    int patient_id = ui->patientIdEdit->text().toInt();
    Prescription *p = new Prescription();
    p->set_prescription_type(ui->prescriptionTypeComboBox->currentText());
    p->set_start_date(ui->startDateEdit->date());
    //QString date = test.toString("dd.MM.yyyy");
    //qDebug() << date;
    p->set_end_date(ui->endDateEdit->date());
}
