#ifndef CALENDARMANAGER_H
#define CALENDARMANAGER_H

#include "prescription.h"
#include "bloodwork.h"
#include <QStringList>

class CalendarManager
{
public:
    CalendarManager();
    void set_selected_date(QDate date);
    QDate get_selected_date();
    void set_today_prescriptions();
    QStringList get_today_prescriptions();
private:
    QDate selected_date_;
    QStringList today_prescriptions_;
    QVector<QString> today_bloodwork_;
};

#endif // CALENDARMANAGER_H
