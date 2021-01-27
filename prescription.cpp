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
