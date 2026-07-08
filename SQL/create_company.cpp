// create_company.cpp

// Compile step 1: gcc -c sqlite3.c -o sqlite3.o
// Once sqlite3.o is created then no need to compile sqlite3.c again unless you want to update it.
// You can directly compile the other source files with sqlite3.o.

// Compile step 2: g++ create_company.cpp sqlite3.o -o create_company.exe
// run: ./create_company.exe

#include <iostream>
#include <string>
#include "sqlite3.h"

int main()
{
    sqlite3 *DB;
    // 1. Open (or create) the database
    int exit = sqlite3_open("company.db", &DB);

    if (exit)
    {
        std::cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl;
        return (-1);
    }
    else
    {
        std::cout << "Opened Database Successfully!" << std::endl;
    }

    // 2. Define your SQL statement to create a table
    std::string sql = "CREATE TABLE IF NOT EXISTS EMPLOYEE("
                      "ID INT PRIMARY KEY NOT NULL, "
                      "NAME TEXT NOT NULL, "
                      "ROLE TEXT NOT NULL);";

    char *errorMessage;

    // 3. sqlite3_exec sends the SQL string to the database engine
    int rc = sqlite3_exec(DB, sql.c_str(), NULL, 0, &errorMessage);

    if (rc != SQLITE_OK)
    {
        std::cerr << "SQL Error: " << errorMessage << std::endl;
        sqlite3_free(errorMessage); // Free the error message memory allocated by SQLite
    }
    else
    {
        std::cout << "Table 'EMPLOYEE' created successfully!" << std::endl;
    }

    // 4. Close the database connection
    sqlite3_close(DB);

    return 0;
}