#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <QPainter>
#include <QPixmap>
#include <QMouseEvent>
#include <QTime>
#include "SetWindow.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *);
    void paintEvent(QPaintEvent *event);

private slots:
    void on_pushButton_login_clicked();
    void on_pushButton_minimize_clicked();
    void on_pushButton_close_clicked();
    void set(int from, int to);
    void on_pushButton_set_clicked();

private:
    Ui::MainWindow *ui;
    bool m_drag;QPoint m_windowPosition;
    //参数配置窗口
    SetWindow *m_setWindow;
    int m_from,m_to;
};

#endif // MAINWINDOW_H
