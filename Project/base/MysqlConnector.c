#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

char **selectDate(MYSQL *con, const char *query, int *matrixRows, int *matrixColumns){
    
    char **matrixResults = NULL;
    int stringSize;
    int count = 0;

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

    int num_fields = mysql_num_fields(result);

    MYSQL_ROW row;
    
    *matrixRows = mysql_num_rows(result) * num_fields;
    *matrixColumns = num_fields;

    matrixResults = (char **) malloc(*matrixRows * sizeof(char*));
    
    if(matrixResults == NULL){
        printf("ERROR TO ALLOCATE MATRIX");
        return NULL;
    }

    while ((row = mysql_fetch_row(result))) 
    { 
        for(int i = 0; i < num_fields; i++) 
        {   
            stringSize = strlen(row[i]);

            matrixResults[count] = NULL;

            if(stringSize > 0){
                matrixResults[count] = (char *) malloc(stringSize * sizeof(char));
                if(matrixResults[count] != NULL){
                    strcpy(matrixResults[count], row[i]);
                }
            }
            else
            {
                matrixResults[count] = (char *) malloc(5 * sizeof(char));
                if(matrixResults[count] != NULL){
                    strcpy(matrixResults[count], "NULL");
                }
            }

            count++;
        }
    }

    mysql_free_result(result);

    return matrixResults;
}


int insertDate(MYSQL *con, const char *query){
    if (mysql_query(con, query)) {
      fprintf(stderr, "%s\n", mysql_error(con));
      return 0;
    }
    
    return 1;
}


int removeDate(MYSQL *con, const char *query){
    if (mysql_query(con, query)) {
      fprintf(stderr, "%s\n", mysql_error(con));
      return 0;
    }
    
    return 1;
}


int updateDate(MYSQL *con, const char *query){
    if (mysql_query(con, query)) {
      fprintf(stderr, "%s\n", mysql_error(con));
      return 0;
    }
    
    return 1;
}


void closeConnector(MYSQL *con){
    mysql_close(con);
}