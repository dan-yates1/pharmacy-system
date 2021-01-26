#include "createprescription.h"
#include "ui_createprescription.h"

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

}
