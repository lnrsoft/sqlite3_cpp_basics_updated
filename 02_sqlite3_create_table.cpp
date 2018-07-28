#include <iostream>
#include <sqlite3.h>
#include <string>

static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    int i;
    for(i = 0; i < argc; i++) {
        std::cerr << azColName[i] << argv[i] << argv[i] << "NULL";
    }
    std::cout << std::endl;
    return 0;
}

int main()
{
    sqlite3 *db;
    char *zErrMsg = nullptr;
    const char *sql;
    auto rc = sqlite3_open("local_db.sqlite", &db);
    if(rc) {
        std::cerr << "Failed open database: " << sqlite3_errmsg(db)
                  << std::endl;
        return (0);
    }
    else {
        std::cerr << "Database successfully opened" << std::endl;
    }
    sql = "CREATE TABLE CANDIDATE("
          "ID INT PRIMARY KEY     NOT NULL,"
          "NAME           TEXT    NOT NULL,"
          "AGE            INT     NOT NULL,"
          "ROLE           TEXT    NOT NULL,"
          "SALARY         TEXT    NOT NULL);";
    rc = sqlite3_exec(db, sql, callback, nullptr, &zErrMsg);
    if(rc != SQLITE_OK) {
        std::cerr << "SQL error: " << zErrMsg << std::endl;
        sqlite3_free(&zErrMsg);
    }
    else {
        std::cerr << "Table successfully created" << std::endl;
    }
    sqlite3_close(db);
    return 0;
}
