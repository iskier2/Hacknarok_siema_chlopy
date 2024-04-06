cmake_minimum_required(VERSION 3.26)
project(RPicoWConnection)

set(CMAKE_CXX_STANDARD 17)

# Path to SQLite library directory
set(SQLITE_DIR "sqlite-amalgamation-3450200")

# Add SQLite library
include_directories(${SQLITE_DIR})
link_directories(${SQLITE_DIR})


add_executable(RPicoWConnection main.cpp
        Socket.cpp
        DataBase.cpp
)

# Link against SQLite library
target_link_libraries(RPicoWConnection sqlite3)