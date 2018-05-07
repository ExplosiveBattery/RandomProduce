#include "MainWindow.h"
#include "ui_MainWindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QDialog(parent),ui(new Ui::MainWindow),m_setWindow(new SetWindow),
    m_drag(false),m_from(0),m_to(300)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);setAttribute(Qt::WA_TranslucentBackground);
    connect(m_setWindow, SIGNAL(set(int,int)), this, SLOT(set(int,int)));
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *) {
    QRectF target(0,0,390,390);
    QPixmap pic("picture.jpg");
    QPainter painter(this);
    painter.drawPixmap(target, pic, pic.rect());
}


//下面三个鼠标响应事件是为了能够对窗口进行拖动
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
         m_drag = true;
         m_windowPosition = event->globalPos() - this->pos();
         event->accept();
     }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (m_drag && event->buttons() & Qt::LeftButton) {
        move(event->globalPos() - m_windowPosition);
        event->accept();
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *)
{
    m_drag = false;
}

void MainWindow::set(int from, int to) {
    m_from =from;
    m_to =to;
}


void MainWindow::on_pushButton_close_clicked()
{
    exit(0);
}

void MainWindow::on_pushButton_minimize_clicked()
{
    showMinimized();
}


void MainWindow::on_pushButton_login_clicked()
{
    int result =qrand()%(m_to-m_from)+m_from;
    ui->label_result->setText(QString::number(result));
}


void MainWindow::on_pushButton_set_clicked()
{
    m_setWindow->show();
}
