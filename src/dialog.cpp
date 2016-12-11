#include "dialog.h"
#include "ui_dialog.h"
#include <QPushButton>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
     QObject::connect(ui->dialog_ok, SIGNAL(clicked()), this,  SLOT(set_nbl())  );
}


void Dialog::set_mw(MainWindow *m){
    mw=m;
}

void Dialog::set_nbl(){
    bool b=ui->checkBox->isChecked() ;
    mw->nbl=ui->spinBox->value();

    mw->init(b);
    this->close();
}


Dialog::~Dialog()
{
    delete ui;
}
