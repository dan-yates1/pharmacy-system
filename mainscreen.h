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

private slots:
    void on_createPrescriptionButton_clicked();

    void on_createUserButton_clicked();

    void on_bookBloodworkButton_clicked();

    void on_viewPrescriptionButton_clicked();

    void on_viewUsersButton_clicked();

private:
    Ui::MainScreen *ui;
};

#endif // MAINSCREEN_H
