#pragma once

#ifdef __cplusplus
extern "C"
{
#endif
#include "sqlite3/sqlite3.h"
#ifdef __cplusplus
}
#endif

#include <string>

typedef std::string String;

// database manager

class DBManager
{
 public:
  static DBManager& getInstance();

  DBManager(DBManager const&) = delete;
  void operator=(DBManager const&) = delete;


  bool createTable(const std::string& sql_create_table);

  bool executeQuery(const std::string& sql_query);

 private:
  DBManager(const std::string& db_name);
  virtual ~DBManager();

  bool openDatabase();
  static int callback(void* NotUsed, int argc, char** argv, char** azColName);

private:
  std::string db_name_;
  sqlite3*    _mdb;
};

#define g_DbManager DBManager::getInstance()
