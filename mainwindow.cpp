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

}

MainWindow::~MainWindow()
{
    delete ui;
}
