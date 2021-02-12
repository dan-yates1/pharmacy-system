#include "createbloodwork.h"
#include "ui_createbloodwork.h"
#include "bloodwork.h"
#include "database.h"
#include <QFile>
#include <QTextStream>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDebug>

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
    delete ui;
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
            int id = (line.split(',').at(0)).toInt();
            ui->bloodworkTypeComboBox->addItem(reason);
        }
        file.close();
    }
}

void CreateBloodwork::UpdatePatients()
{
    QSqlQuery query("SELECT * FROM patient");
    int fnameIndex = query.record().indexOf("first_name");
    int lnameIndex = query.record().indexOf("first_name");
    while (query.next())
    {
        QString fname = query.value(fnameIndex).toString();
        QString lname = query.value(lnameIndex).toString();
        QString name = fname + ' ' + lname;
        ui->patientComboBox->addItem(name);
    }
}


void CreateBloodwork::on_submitBloodworkButton_clicked()
{

}
