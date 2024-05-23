#include "kt_utility.h"
#include <iostream>

DBManager &DBManager::getInstance()
{
  static DBManager instance("test.db");
  return instance;
}

DBManager::DBManager(const std::string &db_name) : db_name_(db_name), _mdb(nullptr)
{
  openDatabase();
}

DBManager::~DBManager()
{
  if (_mdb != nullptr)
  {
    sqlite3_close(_mdb);
  }
}

bool DBManager::openDatabase()
{
  int rc = sqlite3_open(db_name_.c_str(), &_mdb);
  if (rc != SQLITE_OK)
  {
    std::cerr << "无法打开数据库: " << sqlite3_errmsg(_mdb) << std::endl;
    return false;
  }
  else
  {
    std::cout << "成功打开数据库" << std::endl;
    return true;
  }
}

bool DBManager::createTable(const std::string &sql_create_table)
{
  char *err_msg = nullptr;
  int   rc = sqlite3_exec(_mdb, sql_create_table.c_str(), nullptr, nullptr, &err_msg);
  if (rc != SQLITE_OK)
  {
    std::cerr << "创建表格失败: " << err_msg << std::endl;
    sqlite3_free(err_msg);
    return false;
  }
  else
  {
    std::cout << "成功创建表格" << std::endl;
    return true;
  }
}

bool DBManager::executeQuery(const std::string &sql_query)
{
  char *err_msg = nullptr;
  int   rc = sqlite3_exec(_mdb, sql_query.c_str(), callback, nullptr, &err_msg);
  if (rc != SQLITE_OK)
  {
    std::cerr << "执行查询失败: " << err_msg << std::endl;
    sqlite3_free(err_msg);
    return false;
  }
  else
  {
    std::cout << "成功执行查询" << std::endl;
    return true;
  }
}

int DBManager::callback(void *NotUsed, int argc, char **argv, char **azColName)
{
  for (int i = 0; i < argc; i++)
  {
    std::cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << std::endl;
  }
  std::cout << std::endl;
  return 0;
}
