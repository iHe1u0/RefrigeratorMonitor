#include "mainwindow.h"
#include "ui_mainwindow.h"

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
  const char *sql =
      "CREATE TABLE IF NOT EXISTS Person ( \
    ID INTEGER PRIMARY KEY, \
    Name TEXT, \
    Age INTEGER \
    );";
  g_DbManager.openDatabase();
  g_DbManager.createTable(sql);
}
