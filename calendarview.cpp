#include "calendarview.h"
#include "calendarmanager.h"
#include "ui_calendarview.h"
#include "database.h"
#include <QSqlQueryModel>
#include <QSqlQuery>

CalendarView::CalendarView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CalendarView)
{
    ui->setupUi(this);
    PopulateListView();
    ui->dateLabel->setText(get_selected_date().toString("dd-MM-yyyy"));
}

CalendarView::~CalendarView()
{
    delete ui;
}

void CalendarView::set_selected_date(QDate date)
{
    selected_date_ = date;
}

QDate CalendarView::get_selected_date()
{
    return selected_date_;
}

void CalendarView::PopulateListView()
{
    Database db;
    QSqlQueryModel *modal = new QSqlQueryModel;
    QSqlQuery *query = new QSqlQuery;
    query->prepare("SELECT patient_id,medication,start_date,end_date FROM prescription WHERE start_date = :start_date");
    query->bindValue(":start_date", todays_date_.toString("dd-MM-yyyy"));
    query->exec();
    modal->setQuery(*query);
    ui->tableView->setModel(modal);
}
