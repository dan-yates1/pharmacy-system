#include "patient.h"

Patient::Patient()
{

}

QString Patient::get_fname()
{
    return first_name_;
}

void Patient::set_fname(QString fname)
{
    first_name_ = fname;
}

QString Patient::get_lname(){
    return last_name_;
}

void Patient::set_lname(QString lname)
{
    last_name_ = lname;
}

int Patient::get_id()
{
    return patient_id_;
}

void Patient::set_id(int id)
{
    patient_id_ = id;
}

QDate Patient::get_dob()
{
    return dob_;
}

void Patient::set_dob(QDate dob)
{
    dob_ = dob;
}
