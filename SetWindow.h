#ifndef SETWINDOW_H
#define SETWINDOW_H

#include <QWidget>
#include <QFileDialog>
#include <QMessageBox>

namespace Ui {
class SetWindow;
}

class SetWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SetWindow(QWidget *parent = 0);
    ~SetWindow();

private slots:
    void on_pushButton_ok_clicked();

    void on_pushButton_locate_clicked();

signals:
    void set(int from, int to);

private:
    Ui::SetWindow *ui;
};

#endif // SETWINDOW_H
