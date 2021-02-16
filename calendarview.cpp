#include "calendarview.h"
#include "ui_calendarview.h"
#include "database.h"
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QDebug>

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

void CalendarView::set_selected_date(QDate date)
{
    selected_date_ = date;
}

QDate CalendarView::get_selected_date()
{
    return selected_date_;
}

void CalendarView::PopulateListView(QDate date)
{
    Database db;
    QSqlQueryModel *modal = new QSqlQueryModel;
    QSqlQuery *query = new QSqlQuery;
    query->prepare("SELECT patient_id,medication,start_date,end_date FROM prescription WHERE start_date = :selected_date OR end_date = :selected_date");
    query->bindValue(":selected_date", date.toString("dd-MM-yyyy"));
    query->exec();
    modal->setQuery(*query);
    ui->tableView->setModel(modal);
}

void CalendarView::set_label(QString text)
{
    ui->dateLabel->setText(text);
}
