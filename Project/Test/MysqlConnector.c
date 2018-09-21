#include<stdio.h>
#include "MysqlConnector.h"

MYSQL *mysqlConnector(const char *host, const char *user, const char *passwd, const char *db){
    MYSQL *con = mysql_init(NULL);

    if (con == NULL) 
    {
        fprintf(stderr, "%s\n", mysql_error(con));
        return NULL;
    }

    if (mysql_real_connect(con, host, user, passwd, db, 0, NULL, 0) == NULL) 
    {
        fprintf(stderr, "%s\n", mysql_error(con));
        mysql_close(con);
        return NULL;
    }

    return con;
}

MYSQL_RES *selectDate(MYSQL *con, const char *query){
    if (mysql_query(con, query)) 
    {
        fprintf(stderr, "%s\n", mysql_error(con));
        return NULL;
    }
    
    MYSQL_RES *result = mysql_store_result(con);
    if (result == NULL) 
    {
        fprintf(stderr, "%s\n", mysql_error(con));
        return NULL;
    }

    return result;
}


int insertDate(MYSQL *con, const char *query){
    if (mysql_query(con, query)) {
      fprintf(stderr, "%s\n", mysql_error(con));
      return 0;
    }
    
    return 1;
}


int removeDate(MYSQL *con, const char *query);


int updateDate(MYSQL *con, const char *query);



void closeConnector(MYSQL *con){
    mysql_close(con);
}