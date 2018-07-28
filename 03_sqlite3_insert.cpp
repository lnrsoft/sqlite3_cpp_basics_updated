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
    int rc;
    const char *sql;
    rc = sqlite3_open("local_db.sqlite", &db);
    if(rc) {
        std::cerr << "Failed open database: " << sqlite3_errmsg(db)
                  << std::endl;
        return (0);
    }
    else {
        std::cerr << "Database successfully opened" << std::endl;
    }
    sql = "INSERT INTO CANDIDATE (ID,NAME,AGE,ROLE,SALARY) "
          "VALUES (1, 'Daniel', 29, 'CCO', 130000 ); "
          "INSERT INTO CANDIDATE (ID,NAME,AGE,ROLE,SALARY) "
          "VALUES (2, 'Roland', 35, 'CTO', 175000 ); "
          "INSERT INTO CANDIDATE (ID,NAME,AGE,ROLE,SALARY)"
          "VALUES (3, 'Leslie', 33, 'CEO', 200000 );";
    rc = sqlite3_exec(db, sql, callback, nullptr, &zErrMsg);
    if(rc != SQLITE_OK) {
        std::cerr << "SQL error: " << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
    }
    else {
        std::cerr << "Records created successfully" << std::endl;
    }
    sqlite3_close(db);
    return 0;
}
