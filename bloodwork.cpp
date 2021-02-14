#include "bloodwork.h"

Bloodwork::Bloodwork()
{

}

void Bloodwork::set_bloodwork_id(int id)
{
    bloodwork_id_ = id;
}

int Bloodwork::get_bloodwork_id()
{
    return bloodwork_id_;
}

void Bloodwork::set_patient_id(int id)
{
    patient_id_ = id;
}

int Bloodwork::get_patient_id()
{
    return patient_id_;
}

void Bloodwork::set_reason(QString reason)
{
    reason_ = reason;
}

QString Bloodwork::get_reason()
{
    return reason_;
}

void Bloodwork::set_date(QDate date)
{
    date_ = date;
}

QDate Bloodwork::get_date()
{
    return date_;
}

void Bloodwork::set_valid_till(QDate date)
{
    valid_till_ = date;
}

QDate Bloodwork::get_valid_till()
{
    return valid_till_;
}
