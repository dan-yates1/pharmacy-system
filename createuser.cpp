#include "createuser.h"
#include "ui_createuser.h"

CreateUser::CreateUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateUser)
{
    ui->setupUi(this);
}

CreateUser::~CreateUser()
{
    delete ui;
}


void CreateUser::on_createUserButton_clicked()
{
    QString user_type = "Patient";
    if(ui->userTypeCombo->currentText() == user_type)
    {
        // create patient object and assign variables
        Patient *p = new Patient();
        p->set_id(ui->patientIdEdit->text().toInt());
        p->set_fname(ui->firstNameEdit->text());
        p->set_lname(ui->secondNameEdit->text());
        p->set_dob(ui->dobEdit->date());
        QMessageBox::information(this,"Notification","Patient created");
    }
}
