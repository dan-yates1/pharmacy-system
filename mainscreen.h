#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include <QDialog>
#include <QDate>
#include "prescription.h"
#include "bloodwork.h"

namespace Ui {
class MainScreen;
}

class MainScreen : public QDialog
{
    Q_OBJECT

public:
    explicit MainScreen(QWidget *parent = nullptr);
    ~MainScreen();

    QList<Bloodwork> GetExpiredBw();
    QList<Prescription> GetExpiredPres();

private slots:
    void on_createPrescriptionButton_clicked();

    void on_createUserButton_clicked();

    void on_bookBloodworkButton_clicked();

    void on_viewPrescriptionButton_clicked();

    void on_viewUsersButton_clicked();

    void on_calendarWidget_clicked(const QDate &date);

    void on_viewBloodworkButton_clicked();

    void on_expiredButton_clicked();

    void on_expiredButton_2_clicked();

    void on_expiredButton_3_clicked();

private:
    Ui::MainScreen *ui;
    QDate today_date_ = QDate::currentDate();
    QList<Prescription> ex_pres;
    QList<Bloodwork> ex_bw;
};

#endif // MAINSCREEN_H
