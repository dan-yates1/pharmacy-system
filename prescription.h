#ifndef PRESCRIPTION_H
#define PRESCRIPTION_H

#include "patient.h"
#include "bloodwork.h"

class Prescription
{
public:
    Prescription();
    int get_prescription_id();
    void set_prescription_id(int id);
    Patient get_patient();
    void set_patient(Patient patient);
    int get_drug_id();
    void set_drug_id(int id);
private:
    int prescription_id_;
    Patient patient_;
    int drug_id_;
    //QDate start_date_;
    //QDate end_date_;
};

#endif // PRESCRIPTION_H
