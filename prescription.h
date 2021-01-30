#ifndef PRESCRIPTION_H
#define PRESCRIPTION_H

#include "patient.h"
#include "bloodwork.h"
#include <QString>

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
    QString get_prescription_type();
    void set_prescription_type(QString type);
private:
    int prescription_id_;
    Patient patient_;
    int drug_id_;
    QString prescription_type_;
    //QDate start_date_;
    //QDate end_date_;
};

#endif // PRESCRIPTION_H
