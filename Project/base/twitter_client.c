/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "twitter.h"

#define fileHelpName "instructions.txt"




void
new_topic_interface(CLIENT *clnt, char *username, char *topicParam)
{
	int *result;
	data t;

	t.username = (char*) malloc(strlen(username) * sizeof(char));
	t.topic = (char*) malloc(strlen(topicParam) * sizeof(char));

	strcpy(t.username, username);
	strcpy(t.topic, topicParam);
	
	result = new_topic_1(&t, clnt);

	free(t.username);
	free(t.topic);

	if (result == NULL){
		printf ("Problemas ao chamar a função remota\n");
		exit (1);
	}
	else if(*result == 1){
		printf ("Tópico criado com sucesso!\n");
	}
	else 
	{
		printf ("Ocorreu um problema ao criar o tópico! Tente novamente!\n");
	}
}


void 
unfollow_interface(CLIENT *clnt, char *username, char *otherName)
{
	int *result;
	data f;

	f.username = (char*) malloc(strlen(username) * sizeof(char));
	f.otherName = (char*) malloc(strlen(otherName) * sizeof(char));

	strcpy(f.username, username);
	strcpy(f.otherName, otherName);

	result = unfollow_1(&f, clnt);

	free(f.username);
	free(f.otherName);

	if (result == NULL){
		printf ("Problemas ao chamar a função remota\n");
		exit (1);
	}
	else if(*result == 1){
		printf ("Unfollow realizado com sucesso!\n");
	}
	else 
	{
		printf ("Ocorreu um problema na solicitação de deixar de seguir usuário! Tente novamente!\n");
	}
}

void 
retrievetopic_interface(CLIENT *clnt, char *username, char *topicParam, char *timestamp)
{
	char **result;
	int i = 0;
	data r;

	r.username = (char*) malloc(strlen(username) * sizeof(char));
	r.topic = (char*) malloc(strlen(topicParam) * sizeof(char));
	r.timestamp = (char*) malloc(strlen(timestamp) * sizeof(char));

	strcpy(r.username, username);
	strcpy(r.topic, topicParam);
	strcpy(r.timestamp, timestamp);

	result = retrievetopic_1(&r, clnt);

	free(r.username);
	free(r.topic);
	free(r.timestamp);

	if (result == NULL){
		printf ("Problemas ao chamar a função remota\n");
		exit (1);
	}
	else
	{
		while(*(result+i) != NULL)
		{
			printf("%s\n", *(result+i));
			i++;
		}
	}

}

void 
twitte_interface(CLIENT *clnt, char *username, char *text)
{
	int *result;
	data t;

	t.username = (char*) malloc(strlen(username) * sizeof(char));
	t.text = (char*) malloc(strlen(text) * sizeof(char));

	strcpy(t.username, username);
	strcpy(t.text, text);

	result = twitte_1(&t, clnt);

	free(t.username);
	free(t.text);

	if (result == NULL){
		printf ("Problemas ao chamar a função remota\n");
		exit (1);
	}
	else if(*result == 1){
		printf ("Twitte criado com sucesso!\n");
	}
	else 
	{
		printf ("Ocorreu um problema ao criar o twitte! Tente novamente!\n");
	}	
}


void readAllFile(char *fileName){
	char    *buffer;
	long    numbytes;
	FILE *f = NULL;

	f = fopen(fileName, "r");
	if(f == NULL){
		printf("Error! opening file");
		exit(1);
	}

	fseek(f, 0L, SEEK_END);
	numbytes = ftell(f);
	
	fseek(f, 0L, SEEK_SET);	

	buffer = (char*)calloc(numbytes, sizeof(char));	
	
	if(buffer == NULL)
		exit(1);
	
	fread(buffer, sizeof(char), numbytes, f);
	
	printf("%s\n", buffer);
	
	free(buffer);
}


void verifyParams(int argc, char **argv){

	if(strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "-help") == 0){

		readAllFile(fileHelpName);

		exit (1);
	}

	if (argc < 3){
			fprintf (stderr,"Usage: %s hostname [function_name] [params1, ..., paramsn]\n",argv[0]);
			exit (1);
	}

}

void menu(int argc, char **argv){

	CLIENT *clnt;

   	clnt = clnt_create (argv[1], TWITTER_PROG, TWITTER_VERSION, "udp");

	if (clnt == (CLIENT *) NULL)
	{
		clnt_pcreateerror (argv[1]);
		exit(1);
	}

	printf("%s\n", argv[2]);
	if(strcmp(argv[2],"new_topic") == 0 && argc > 4)
	{
		new_topic_interface(clnt, argv[3], argv[4]);
	}
	else if(strcmp(argv[2],"unfollow") == 0 && argc > 4)
	{
		unfollow_interface(clnt, argv[3], argv[4]);
	}
	if(strcmp(argv[2],"retrievetopic") == 0 && argc > 5){
		retrievetopic_interface(clnt, argv[3], argv[4], argv[5]);
	}
	else if(strcmp(argv[2],"twitte") == 0 && argc > 4)
	{
		twitte_interface(clnt, argv[3], argv[4]);
	}
	else
	{
		printf("Função desconhecida ou parâmetros faltando! Digite -h para visualizar as informações permitidas.\n");
	}
}

int
main (int argc, char *argv[])
{

	verifyParams(argc, argv);
	printf("Passei Aqui\n");
	menu(argc, argv);

	return (0);
}
