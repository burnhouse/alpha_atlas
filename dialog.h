#ifndef DIALOG_H
#define DIALOG_H
#include "mainwindow.h"
#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    void set_mw(MainWindow *m);
    ~Dialog();
public slots:
    void set_nbl();
private:
    MainWindow *mw;
    Ui::Dialog *ui;
};

#endif // DIALOG_H
