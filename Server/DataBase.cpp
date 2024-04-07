#include <sqlite3.h>
#include <stdio.h>
#include <iostream>
#include <string>

class DB{
private:
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char *sql;
public:
    static int callback(void *NotUsed, int argc, char **argv, char **azColName)
    {
        int i;
        for(i=0; i<argc; i++)
        {
            std::cout <<azColName[i]<<" = " << (argv[i] ? argv[i] : "NULL")<<"\n";
        }
        std::cout<<"\n";
        return 0;
    }
    DB(){
        rc = sqlite3_open("SKW.db", &db);
        if( rc ) {
            fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        } else {
            fprintf(stderr, "Opened database successfully\n");
        }
    }
    bool query(const std::string& query) {
        char *errMsg = nullptr;
        int rc = sqlite3_exec(db, query.c_str(), nullptr, nullptr, &errMsg);
        if (rc != SQLITE_OK) {
            std::cerr << "SQL error: " << errMsg << std::endl;
            sqlite3_free(errMsg);
            return false;
        }
        return true;
    }
    std::vector<std::vector<std::string>> selectQuery(const std::string& query) {
        std::vector<std::vector<std::string>> result;

        char *errMsg = nullptr;
        int rc = sqlite3_exec(db, query.c_str(), callback, &result, &errMsg);
        if (rc != SQLITE_OK) {
            std::cerr << "SQL error: " << errMsg << std::endl;
            sqlite3_free(errMsg);
        }
        return result;
    }
    void close(){
        query("DROP TABLE IF EXIST main;");
        sqlite3_close(db);
    }




};
