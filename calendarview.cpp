#include "calendarview.h"
#include "ui_calendarview.h"

CalendarView::CalendarView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CalendarView)
{
    ui->setupUi(this);
}

CalendarView::~CalendarView()
{
    delete ui;
}
