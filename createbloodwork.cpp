#include "createbloodwork.h"
#include "ui_createbloodwork.h"
#include "bloodwork.h"
#include "database.h"
#include "prescription.h"
#include <QFile>
#include <QTextStream>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDebug>
#include <QMessageBox>

CreateBloodwork::CreateBloodwork(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateBloodwork)
{
    ui->setupUi(this);
    UpdateReasons();
    Database db;
    UpdatePatients();
}

CreateBloodwork::~CreateBloodwork()
{

}

void CreateBloodwork::UpdateReasons()
{
    QFile file(":/csv/blood_test_reasons.csv");
    if(file.open(QIODevice::ReadOnly))
    {
        QTextStream in(&file);
        while(!in.atEnd())
        {
            QString line = in.readLine();
            QString reason = line.split(',').at(1);
            //int id = (line.split(',').at(0)).toInt();
            ui->bloodworkTypeComboBox->addItem(reason);
        }
        file.close();
    }
}

void CreateBloodwork::UpdatePatients()
{
    QSqlQuery query("SELECT * FROM patient");
    int fnameIndex = query.record().indexOf("first_name");
    int lnameIndex = query.record().indexOf("last_name");
    while (query.next())
    {
        QString fname = query.value(fnameIndex).toString();
        QString lname = query.value(lnameIndex).toString();
        QString name = fname + ' ' + lname;
        ui->patientComboBox->addItem(name);
    }
}

Bloodwork CreateBloodwork::PopulateBloodwork()
{
    Bloodwork b;
    b.set_patient_id(ui->patientComboBox->currentIndex()+1);
    b.set_reason(ui->bloodworkTypeComboBox->currentText());
    b.set_date(ui->bloodoworkDateEdit->date());
    b.set_valid_till(ui->bloodoworkDateEdit->date().addMonths(1));
    return b;
}


void CreateBloodwork::on_submitBloodworkButton_clicked()
{
    Database db;
    Bloodwork b = PopulateBloodwork();
    db.InsertBloodwork(b);
    QMessageBox::information(this,"Notification","Bloodwork created");
}
