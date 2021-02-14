#include "calendarmanager.h"

CalendarManager::CalendarManager()
{

}

void CalendarManager::set_selected_date(QDate date)
{
    selected_date_ = date;
}

QDate CalendarManager::get_selected_date()
{
    return selected_date_;
}
