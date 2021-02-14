#ifndef PRESCRIPTION_H
#define PRESCRIPTION_H

#include "patient.h"
#include "bloodwork.h"
#include <QString>
#include <QDate>

class Prescription
{
public:
    Prescription();
    int get_prescription_id();
    void set_prescription_id(int id);
    int get_patient_id();
    void set_patient_id(int id);
    int get_drug_id();
    void set_drug_id(int id);
    void set_drug(QString drug);
    QString get_drug();
    QString get_prescription_type();
    void set_prescription_type(QString type);
    QDate get_start_date();
    void set_start_date(QDate date);
    QDate get_end_date();
    void set_end_date(QDate date);
private:
    int prescription_id_;
    int patient_id_;
    int drug_id_;
    QString drug_;
    QString prescription_type_;
    QDate start_date_;
    QDate end_date_;
};

#endif // PRESCRIPTION_H
