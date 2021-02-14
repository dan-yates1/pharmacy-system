#include "mainwindow.h"
#include "patient.h"
#include "medication.h"
#include "loginwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.setWindowTitle("Pharmacy App");
    //w.setWindowIcon(QIcon(":/icons/window-icon.svg"));
    //w.setFixedSize(w.size());
    //w.show();
    LoginWindow l;
    l.show();
    return a.exec();  
}
