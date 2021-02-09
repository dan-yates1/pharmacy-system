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

}

void CreateBloodwork::UpdatePatients()
{

}

void CreateBloodwork::on_bookBloodworkButton_clicked()
{

}
