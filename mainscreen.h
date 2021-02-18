#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include <QDialog>

namespace Ui {
class MainScreen;
}

class MainScreen : public QDialog
{
    Q_OBJECT

public:
    explicit MainScreen(QWidget *parent = nullptr);
    ~MainScreen();

    //bool CheckExpiredPrescription();

    //bool CheckExpire
private slots:
    void on_createPrescriptionButton_clicked();

    void on_createUserButton_clicked();

    void on_bookBloodworkButton_clicked();

    void on_viewPrescriptionButton_clicked();

    void on_viewUsersButton_clicked();

    void on_calendarWidget_clicked(const QDate &date);

    void on_viewBloodworkButton_clicked();

private:
    Ui::MainScreen *ui;
};

#endif // MAINSCREEN_H
