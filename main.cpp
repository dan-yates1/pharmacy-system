#include "mainwindow.h"
#include "patient.h"
#include "medication.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Pharmacy App");
    w.setWindowIcon(QIcon(":/icons/window-icon.svg"));
    w.show();
    return a.exec();  
}
