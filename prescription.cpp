#include "prescription.h"

Prescription::Prescription()
{

}

int Prescription::get_prescription_id()
{
    return prescription_id_;
}

void Prescription::set_prescription_id(int id)
{
    prescription_id_ = id;
}

QString Prescription::get_prescription_type()
{
    return prescription_type_;
}

void Prescription::set_prescription_type(QString type)
{
    prescription_type_ = type;
}

QDate Prescription::get_start_date()
{
    return start_date_;
}

void Prescription::set_start_date(QDate date)
{
    start_date_ = date;
}

QDate Prescription::get_end_date()
{
    return end_date_;
}

void Prescription::set_end_date(QDate date)
{
    end_date_ = date;
}
