#ifndef HELPVIEW_H
#define HELPVIEW_H

#include <QDialog>

namespace Ui {
class HelpView;
}

class HelpView : public QDialog
{
    Q_OBJECT

public:
    explicit HelpView(QWidget *parent = nullptr);
    ~HelpView();

private:
    Ui::HelpView *ui;
};

#endif // HELPVIEW_H
