#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
  ui->setupUi(this);
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::on_pushButton_clicked()
{
  QString qStrSql=QString("");
  const char *sql =
      "CREATE TABLE IF NOT EXISTS Person ( \
    ID BIGINT PRIMARY KEY, \
    Name TEXT, \
    Age INTEGER \
    );";
  g_DbManager.createTable(sql);
}
