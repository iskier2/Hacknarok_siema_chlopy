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
    void init(){
        rc = sqlite3_open("SKW.db", &db);
        /* Create SQL statement */
        sql = "CREATE TABLE IF NOT EXISTS main("  \
      "ID INT PRIMARY KEY   NOT NULL AUTO_INCREMENT," \
      "lightness    FLOAT   NOT NULL," \
      "people_count INT   NOT NULL," \
      "lift_speed   FLOAT   NOT NULL);";
        /* Execute SQL statement */
        rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
        if( rc!=SQLITE_OK )
        {
            std::cout<<"SQL error: "<<sqlite3_errmsg(db)<<"\n";
            sqlite3_free(zErrMsg);
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
