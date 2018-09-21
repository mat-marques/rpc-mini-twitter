#include "MysqlConnector.h"
#include<stdio.h>

int main(int argc, char **argv)
{

    MYSQL *con = mysqlConnector("localhost", "root", "", "twitter");

    if (con == NULL) 
    {
        fprintf(stderr, "%s\n", mysql_error(con));
        exit(1);
    }

    MYSQL_RES *result = selectDate(con, "SELECT * FROM user");

    if (result == NULL) 
    {
        fprintf(stderr, "%s\n", mysql_error(con));
        exit(1);
    }

    int num_fields = mysql_num_fields(result);

    MYSQL_ROW row;
    
    while ((row = mysql_fetch_row(result))) 
    { 
        for(int i = 0; i < num_fields; i++) 
        { 
            printf("%s ", row[i] ? row[i] : "NULL"); 
        } 
            printf("\n"); 
    }

    mysql_free_result(result);

    closeConnector(con);
}
