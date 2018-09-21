#ifndef _MYSQLCONNECTOR
#define _MYSQLCONNECTOR

#include <my_global.h>
#include <mysql.h>


MYSQL *mysqlConnector(const char *host, const char *user, const char *passwd, const char *db);


MYSQL_RES *selectDate(MYSQL *con, const char *query);


int insertDate(MYSQL *con, const char *query);


int removeDate(MYSQL *con, const char *query);


int updateDate(MYSQL *con, const char *query);


void closeConnector(MYSQL *con);


#endif