#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "patient.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_homeButton_clicked();

    void on_createPrescriptionButton_clicked();

    void on_createUserButton_clicked();

    void on_viewPrescriptionButton_clicked();

    void on_bookBloodworkButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
