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

}

void Prescription::set_prescription_type(QString type)
{
    prescription_type_ = type;
}
