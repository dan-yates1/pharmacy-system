#include "technician.h"

Technician::Technician()
{

}

int Technician::get_id()
{
    return id_;
}

void Technician::set_id(int id)
{
    id_ = id;
}

QString Technician::get_fname()
{
    return first_name_;
}

void Technician::set_fname(QString fname)
{
    first_name_ = fname;
}

QString Technician::get_lname()
{
    return last_name_;
}

void Technician::set_lname(QString lname)
{
    last_name_ = lname;
}

QDate Technician::get_dob()
{
    return dob_;
}

void Technician::set_dob(QDate dob)
{
    dob_ = dob;
}

QString Technician::get_password()
{
    return password_;
}

void Technician::set_password(QString password)
{
    password_ = password;
}
