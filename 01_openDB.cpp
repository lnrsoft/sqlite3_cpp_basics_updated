#include <iostream>
#include <sqlite3.h>
#include <string>

int main() {
    sqlite3* db;
    auto op = sqlite3_open("local_db.sqlite", &db);
    auto cl = sqlite3_close(db);
    if(op) {
    std::cerr << "SQLite ERROR: " << sqlite3_errmsg(db) << std::endl;
    return (0);
    } else {
    std::cout << "SQLite local db has been opened successfully."
              << std::endl;
    }
    if(cl) {
    std::cerr << "SQLite ERROR: " << sqlite3_errmsg(db) << std::endl;
    return (0);
    } else {
    std::cout << "SQLite local db has been closed successfully."
              << std::endl;
    }
}
