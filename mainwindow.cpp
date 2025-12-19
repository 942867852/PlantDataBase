#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPushButton>
#include <QFont>
#include <QObject>
#include <QString>
#include <QWidget>
#include <QTimer>
#include <QTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTimer* timer = new QTimer(this);

    connect(ui->switch1, &QPushButton::clicked, ui->TimeLable, [=](){
        QTime time = QTime::currentTime();
        QString strtm = time.toString("hh:mm:ss:zzz");
        ui->TimeLable->setText(strtm);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
