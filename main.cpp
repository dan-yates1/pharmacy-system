#include "mainwindow.h"
#include "patient.h"
#include "medication.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();  
}
