CFLAGS  = `mysql_config --cflags --libs`

main: mysql2.o MysqlConnector.o
	gcc -o main mysql2.o MysqlConnector.o $(CFLAGS)


mysql2.o: mysql2.c MysqlConnector.h
	gcc -o mysql2.o -c mysql2.c $(CFLAGS)

	
MysqlConnector.o: MysqlConnector.c
	gcc -o MysqlConnector.o -c MysqlConnector.c $(CFLAGS)


.PHONY : clean

clean:
	rm edit *.o