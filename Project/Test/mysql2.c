#include "MysqlConnector.h"
#include<stdio.h>

int main(int argc, char **argv)
{
    char **matrixResult = NULL;
    int matrixRows = 0, matrixColumns = 0;
    MYSQL *con = mysqlConnector("localhost", "root", "", "twitter");

    if (con == NULL) 
    {
        exit(1);
    }

    matrixResult = selectDate(con, "SELECT * FROM user", &matrixRows, &matrixColumns);

    for(int i = 0; i < matrixRows; i++){
        printf("%s\n", matrixResult[i]);
    }

    for(int i = 0; i < matrixRows; i++){
        free(matrixResult[i]);
    }

    free(matrixResult);

    closeConnector(con);
}
