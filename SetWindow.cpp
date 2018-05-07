#include "SetWindow.h"
#include "ui_SetWindow.h"

SetWindow::SetWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SetWindow)
{
    ui->setupUi(this);
    ui->lineEdit_from->setText("0");
    ui->lineEdit_to->setText("300");
    setWindowOpacity(0.75);

}

SetWindow::~SetWindow()
{
    delete ui;
}

void SetWindow::on_pushButton_ok_clicked()
{
    close();
    int from =ui->lineEdit_from->text().toInt(),to=ui->lineEdit_to->text().toInt();
    if(0<=from && from<to)
        emit set(from, to);
    else
        QMessageBox::critical(this, "Error", "Number Error.\r\n"
                                             "0 <= from < to",QMessageBox::NoButton);
}


void SetWindow::on_pushButton_locate_clicked()
{

}
