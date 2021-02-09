#include "createbloodwork.h"
#include "ui_createbloodwork.h"
#include "bloodwork.h"

CreateBloodwork::CreateBloodwork(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateBloodwork)
{
    ui->setupUi(this);
    UpdateReasons();
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

}

void CreateBloodwork::on_bookBloodworkButton_clicked()
{

}
