#ifndef CALENDARVIEW_H
#define CALENDARVIEW_H

#include <QDialog>

namespace Ui {
class CalendarView;
}

class CalendarView : public QDialog
{
    Q_OBJECT

public:
    explicit CalendarView(QWidget *parent = nullptr);
    ~CalendarView();

private:
    Ui::CalendarView *ui;
};

#endif // CALENDARVIEW_H
