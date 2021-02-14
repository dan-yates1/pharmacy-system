#include "patient.h"
#include "medication.h"
#include "loginwindow.h"
#include <QIcon>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginWindow l;
    l.setFixedSize(l.size());
    l.setWindowTitle("Pharmacy App - Login");
    l.setWindowIcon(QIcon(":/icons/window-icon.svg"));
    l.show();
    return a.exec();  
}
