// manage_company.cpp
// Compile: g++ manage_company.cpp sqlite3.o -o manage_company.exe
// run: ./manage_company.exe

#include <iostream>
#include <string>
#include "sqlite3.h"

// The callback function is executed for every row returned by a SELECT query
int callback(void *data, int argc, char **argv, char **azColName)
{
    for (int i = 0; i < argc; i++)
    {
        std::cout << azColName[i] << ": " << (argv[i] ? argv[i] : "NULL") << "\t";
    }
    std::cout << std::endl;
    return 0;
}

int main()
{
    sqlite3 *DB;

    // 1. Open (or create) the database
    if (sqlite3_open("company.db", &DB) != SQLITE_OK)
    {
        std::cerr << "Failed to open database." << std::endl;
        return -1;
    }

    // 2. Insert records into the EMPLOYEE table
    std::string insertSQL =
        "INSERT INTO EMPLOYEE (ID, NAME, ROLE) VALUES (3, 'Alice Smith', 'Database Engineer');"
        "INSERT INTO EMPLOYEE (ID, NAME, ROLE) VALUES (5, 'Bob Jones', 'Data Analyst');";

    char *errMsg = nullptr;
    int rc = sqlite3_exec(DB, insertSQL.c_str(), NULL, 0, &errMsg);

    if (rc != SQLITE_OK)
    {
        std::cerr << "Insert Error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
    else
    {
        std::cout << "Records inserted successfully!" << std::endl;
    }

    std::cout << "\n--- Fetching Employee Records ---" << std::endl;

    // 3. SELECT and Display Records - Query data using the callback function
    std::string selectSQL = "SELECT * FROM EMPLOYEE;";
    rc = sqlite3_exec(DB, selectSQL.c_str(), callback, NULL, &errMsg);

    if (rc != SQLITE_OK)
    {
        std::cerr << "Select Error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }

    sqlite3_close(DB);
    return 0;
}