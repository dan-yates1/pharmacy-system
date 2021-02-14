#ifndef BLOODWORK_H
#define BLOODWORK_H

#include "patient.h"
#include <QDate>

class Bloodwork
{
public:
    Bloodwork();

    void set_bloodwork_id(int id);
    int get_bloodwork_id();
    void set_patient_id(int id);
    int get_patient_id();
    void set_reason(QString reason);
    QString get_reason();
    void set_date(QDate date);
    QDate get_date();
    void set_valid_till(QDate date);
    QDate get_valid_till();
private:
    int bloodwork_id_;
    int patient_id_;
    QString reason_;
    QDate date_;
    QDate valid_till_;
};

#endif // BLOODWORK_H
