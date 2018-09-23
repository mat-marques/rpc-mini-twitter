#ifndef _MYSQLCONNECTOR
#define _MYSQLCONNECTOR

#include <my_global.h>
#include <mysql.h>


MYSQL *mysqlConnector(const char *host, const char *user, const char *passwd, const char *db);

/*
    A função retorna uma matriz de caracteres, no qual cada linha é uma coluna da consulta
    retornada pelo banco de dados. Ou seja, por exemplo, seja n o números de linhas e m o
    número de colunas da consulta retornada, logo o número de linhas da matriz retornada
    pela função será n*m.
    
    matrixRows = n*m;
    matrixColumns = n;
*/
char **selectDate(MYSQL *con, const char *query, int *matrixRows, int *matrixColumns);


int insertDate(MYSQL *con, const char *query);


int removeDate(MYSQL *con, const char *query);


int updateDate(MYSQL *con, const char *query);


void closeConnector(MYSQL *con);


#endif