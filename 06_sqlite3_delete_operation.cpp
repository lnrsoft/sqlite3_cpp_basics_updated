#include <iostream>
#include <sqlite3.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>

static int callback(void *data, int argc, char **argv, char **azColName)
{
    fprintf(stderr, "\nCallback function call: ", &data);
    for(auto i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    return 0;
}

int main()
{
    sqlite3 *db;
    char *zErrMsg = nullptr;
    int rc;
    const char *sql;
    const char *data = "Callback function call";
    rc = sqlite3_open("local_db.sqlite", &db);
    if(rc) {
        std::cerr << "Failed open database: " << sqlite3_errmsg(db)
                  << std::endl;
        return (0);
    }
    else {
        std::cerr << "Database successfully opened" << std::endl;
    }
    sql = "DELETE from CANDIDATE where ID=2; "
          "SELECT * from CANDIDATE";
    rc = sqlite3_exec(db, sql, callback, &data, &zErrMsg);
    if(rc != SQLITE_OK) {
        std::cerr << "SQL error: " << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
    }
    else {
        std::cout << "\nExecution completed successfully" << std::endl;
    }
    sqlite3_close(db);
    return 0;
}
