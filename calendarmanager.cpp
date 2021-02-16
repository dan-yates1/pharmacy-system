#include "calendarmanager.h"
#include "calendarview.h"
#include "database.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QVariant>

CalendarManager::CalendarManager()
{
    CalendarView cv;
    cv.setWindowTitle(get_selected_date().toString("ddMMyyyy"));
    cv.setModal(true);
    cv.exec();
    cv.set_selected_date(get_selected_date());
}

void CalendarManager::set_selected_date(QDate date)
{
    selected_date_ = date;
}

QDate CalendarManager::get_selected_date()
{
    return selected_date_;
}

void CalendarManager::set_today_prescriptions()
{
    QDate today_date = QDate::currentDate();
    int patientId;
    QString fname;
    QString lname;
    QString medication;
    QString start_date;
    QString end_date;
    QString entry;

    Database db;

    QSqlQuery query("SELECT patient_id,medication,start_date,end_date FROM prescription");
    while (query.next())
    {
        patientId = query.value(0).toInt();
        medication = query.value(2).toString();
        start_date = query.value(3).toString();
        end_date = query.value(4).toString();
        entry = patientId + " " + medication + " " + start_date + " " + end_date;
        today_prescriptions_.append(entry);
    }
}

QStringList CalendarManager::get_today_prescriptions()
{
    return today_prescriptions_;
}
