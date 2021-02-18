#include "createuser.h"
#include "ui_createuser.h"

CreateUser::CreateUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateUser)
{
    ui->setupUi(this);
    ui->dobEdit->setDate(QDate::currentDate());
}

CreateUser::~CreateUser()
{
    delete ui;
}

Patient CreateUser::CreatePatient()
{
    // create patient object and assign variables
    Patient p;
    p.set_fname(ui->firstNameEdit->text());
    p.set_lname(ui->secondNameEdit->text());
    p.set_dob(ui->dobEdit->date());
    return p;
}

Technician *CreateUser::CreateTechnician()
{
    // create technician object and assign variables
    Technician *t = new Technician();
    t->set_fname(ui->firstNameEdit->text());
    t->set_lname(ui->secondNameEdit->text());
    t->set_dob(ui->dobEdit->date());
    return t;
}

void CreateUser::on_createUserButton_clicked()
{
    QString patient = "Patient";
    QString technician = "Technician";
    // create patient user
    if(ui->userTypeCombo->currentText() == patient)
    { 
        // create patient object
        Patient p = CreatePatient();
        // create database object
        Database db;
        // insert patient into database
        db.InsertPatient(p);
        db.PrintAllPatients();
        QMessageBox::information(this,"Notification","Patient acccount created");
    }
    // create technician user
    if (ui->userTypeCombo->currentText() == technician)
    {
        // get password for technician account
        bool ok;
        QString password = QInputDialog::getText(this, tr("QInputDialog::getText()"), tr("Set a password: "), QLineEdit::Normal, QDir::home().dirName(), &ok);
        if (ok && !password.isEmpty())
        {
            // create technician object
            Technician *t = CreateTechnician();
            t->set_password(password);
            QMessageBox::information(this,"Notification","Technician acccount created");
        }
    }
}
