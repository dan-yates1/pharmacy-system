#ifndef CALENDARVIEW_H
#define CALENDARVIEW_H

#include <QDialog>
#include <QDate>

namespace Ui {
class CalendarView;
}

class CalendarView : public QDialog
{
    Q_OBJECT

public:
    explicit CalendarView(QWidget *parent = nullptr);
    ~CalendarView();
    void set_selected_date(QDate date);
    QDate get_selected_date();

    void PopulateListView();

private:
    Ui::CalendarView *ui;
    QDate todays_date_ = QDate::currentDate();
    QDate selected_date_;
};

#endif // CALENDARVIEW_H
