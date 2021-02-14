#ifndef CALENDARMANAGER_H
#define CALENDARMANAGER_H

#include "prescription.h"
#include "bloodwork.h"

class CalendarManager
{
public:
    CalendarManager();
    void set_selected_date(QDate date);
    QDate get_selected_date();

    void AddPrescription(Prescription p);
private:
    QDate selected_date_;
    QVector<Prescription> today_prescription_list_;
    QVector<Prescription> today_bloodwork_list_;
};

#endif // CALENDARMANAGER_H
