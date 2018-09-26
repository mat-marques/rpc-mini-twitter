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

char *userName = NULL;

int * 
create_user_interface(CLIENT *clnt, char *username){
	int *result;

	result = create_user_1(&username, clnt);

	if(*result == 1){
		*result = 1;
	}else{
		*result = 0;
	}

	return result;
}


void 
list_users_interface(CLIENT *clnt){
	int *result;
	char **users;
	data *dt;
	
	users = list_users_1(dt, clnt);

	if(users == NULL){
		printf("Nenhum usuário cadastrado.");
	}else{
		printf("Usuários:\n%s", *users);
	}
	free(*users);
}

void
follow_interface(CLIENT *clnt, char *username, char *otherName)
{
	int *result;
	data *dt = malloc(sizeof(data));
	dt->username = malloc(sizeof(char)*(strlen(username)+1));
	dt->otherName = mem_alloc(sizeof(char)*(strlen(otherName)+1));
	strcpy(dt->username, username);
	strcpy(dt->otherName, otherName);

	result = follow_1(dt, clnt);

	if(*result == 1){
		printf("Seguindo %s", otherName);
	}else{
		printf("Erro ao seguir %s", otherName);
	}

}

void post_topic_interface(CLIENT *clnt, char *username, char *topic, char *text){
	int *result;
	data *d = malloc(sizeof(data));
	d->username = malloc(sizeof(char)*(strlen(username) + 1));
	d->topic = malloc(sizeof(char)*(strlen(topic) + 1));
	d->text = malloc(sizeof(char)*(strlen(text) + 1));
	strcpy(d->username, username);
	strcpy(d->topic, topic);
	strcpy(d->text, text);

	result = post_topic_1(d, clnt);

	if(*result == 1){
		printf("Post criado com sucesso,\n");
	}else{
		printf("Erro ao criar topico.\n");
	}
}

void
hashtags_interface(CLIENT *clnt)
{
	char **result;
	data *h = NULL;
	int i = 0;
	result = hashtags_1(h, clnt);

	if (result == NULL){
		printf ("Problemas ao chamar a função remota\n");
		exit (1);
	}
	else 
	{
		printf("Listagem de Tópicos:%s\n", *result);
	}
}

void
new_topic_interface(CLIENT *clnt, char *username, char *topicParam)
{
	int *result;
	data *t = malloc(sizeof(data));

	t->username = malloc((strlen(username) + 1) * sizeof(char));
	t->topic = malloc((strlen(topicParam) + 1) * sizeof(char));

	strcpy(t->username, username);
	strcpy(t->topic, topicParam);
	result = new_topic_1(t, clnt);

	free(t->username);
	free(t->topic);
	free(t);
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
	data *f = (data*) malloc(sizeof(data));

	f->username = (char*) malloc((strlen(username) + 1) * sizeof(char));
	f->otherName = (char*) malloc((strlen(otherName) + 1) * sizeof(char));

	strcpy(f->username, username);
	strcpy(f->otherName, otherName);

	result = unfollow_1(f, clnt);

	free(f->username);
	free(f->otherName);
	free(f);
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
	data *r = (data*) malloc(sizeof(data));

	r->username = (char*) malloc((strlen(username) + 1) * sizeof(char));
	r->topic = (char*) malloc((strlen(topicParam) + 1) * sizeof(char));
	r->timestamp = (char*) malloc((strlen(timestamp) + 1) * sizeof(char));

	strcpy(r->username, username);
	strcpy(r->topic, topicParam);
	strcpy(r->timestamp, timestamp);

	result = retrievetopic_1(r, clnt);

	free(r->username);
	free(r->topic);
	free(r->timestamp);
	free(r);
	if (result == NULL){
		printf ("Problemas ao chamar a função remota\n");
		exit (1);
	}
	else
	{
		printf("Listagem de Postagem:\n%s", *result);
	}

}

void 
twitte_interface(CLIENT *clnt, char *username, char *text)
{
	int *result;
	data *t = (data*) malloc(sizeof(data));

	t->username = (char*) malloc((strlen(username) + 1) * sizeof(char));
	t->text = (char*) malloc((strlen(text) + 1) * sizeof(char));

	strcpy(t->username, username);
	strcpy(t->text, text);

	result = twitte_1(t, clnt);

	free(t->username);
	free(t->text);
	free(t);
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


/*
  Funcao que retorna uma token especifica da string passada
  a funcao percorre a string procurando por espacos ou fim da string, salvando o que e liso no processo
  a funcao faz isso um numero n de vezes, retornando a ultima token encontrada
*/
char *returnToken(char *s, int n)
{
	int i = 0, j, k;
	char *aux = NULL;

	for(k=0; k<n && i < strlen(s); k++){

		if(aux != NULL){
			free(aux);
			aux = NULL;
		}
		for(j = 0; s[i]!=' ' && s[i]!='\0'; j++){
			aux = (char *)realloc(aux, sizeof(char)*(j+2));
			aux[j] = s[i];
			aux[j+1] = '\0';
			i++;
		}
    if(s[i] == '\0' && k<n-1){return NULL;}
		i++;
	}
	return aux;
}


void
printErr(int i){
	switch(i){

		case 2:
			printf("Parametros faltando.");
			break;
		case 3:
			printf("Formato suportado: \"@username\"");
			break;
		default:
			printf("Erro desconhecido.\n");
			break;
	};
}


void 
readAllFile(char *fileName){
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


void 
verifyParams(int argc, char **argv){

	if(strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "-help") == 0){

		readAllFile(fileHelpName);

		exit (1);
	}

	if (argc < 3){
			fprintf (stderr,"Usage: %s hostname [function_name] [params1, ..., paramsn]\n",argv[0]);
			exit (1);
	}

}

void 
menu(int argc, char **argv){

	CLIENT *clnt;
	int *intResponse;
	char *function = NULL;
	char *params = NULL;
	char *line = NULL;
	userName = malloc(sizeof(char)*256);
	line = malloc(sizeof(char)*256);

	clnt = clnt_create(argv[1], TWITTER_PROG, TWITTER_VERSION, "udp");
	if (clnt == NULL)
	{
		clnt_pcreateerror (argv[1]);
		printf("Erro de conexão.\nTente novamente mais tarde.\n");
		exit(1);
	}



	while(1){
		printf("Crie um usuário: ");
		fgets(userName, 256, stdin);
		if(userName[0] == '@' && strlen(userName)>1){
			intResponse = create_user_interface(clnt, userName);
			if(*intResponse == 1){
				printf("Usuário criado com sucesso.\n");
				break;
			}else{
				printf("Erro ao criar usuário\n");
			}
			
		}
	}	
	

	

	

	while(1){
		printf("\n\n-----------------------\n\n");
		printf("\"help\" : ajuda/comandos\n\"exit\" : sair\n\n");
		fgets(line, 256, stdin);
		line[strlen(line)-1] = '\0';
		function = returnToken(line, 1);
		
		

		if(function == NULL){
			printf("Função desconhecida! Digite help para visualizar as informações permitidas.\n");
		}
		else if(strcmp(function, "help") == 0)
		{
			readAllFile(fileHelpName);
		}
		else if(strcmp(function,"exit") == 0)
		{
			exit(1);
		}
		else if(strcmp(function,"hashtag") == 0)
		{
			hashtags_interface(clnt);
		}
		else if(strcmp(function,"new_topic") == 0)
		{
			char *aux1 = returnToken(line, 2);
			if(aux1 == NULL){printErr(2); continue;}
			printf("%s %s\n", userName, aux1);
			new_topic_interface(clnt, userName, aux1);
			free(aux1);
		}
		else if(strcmp(function,"unfollow") == 0)
		{
			char *aux1 = returnToken(line, 2);
			if(aux1 == NULL){printErr(2); continue;}

			unfollow_interface(clnt, userName, aux1);
			free(aux1);
		}
		if(strcmp(function,"retrievetopic") == 0){
			char *aux1 = returnToken(line, 2);
			char *aux2 = returnToken(line, 3);

			if(aux1 == NULL){printErr(2); continue;}
			if(aux2 == NULL){printErr(2); continue;}
			retrievetopic_interface(clnt, userName, aux1, aux2);

			free(aux1);
			free(aux2);
		}
		else if(strcmp(function,"twitte") == 0)
		{
			char *aux1 = returnToken(line, 2);
			if(aux1 == NULL){printErr(2); continue;}

			twitte_interface(clnt, userName, aux1);
			free(aux1);
		}
		else if(strcmp(function, "create_user") == 0){
			char *aux1 = returnToken(line, 2);
			if(aux1 == NULL){printErr(2); continue;}
			if(aux1[0] != '@'){printErr(3); continue;}

			intResponse = create_user_interface(clnt, aux1);
			system("clear");

			if(*intResponse == 1){
				printf("Usuário criado com sucesso.\n");
			}else{
				printf("Erro ao criar usuário.\n");
			}
		}
		else if(strcmp(function, "list_users") == 0)
		{
			list_users_interface(clnt);
		}
		else
		{
			printf("Função desconhecida ou parâmetros faltando! Digite help para visualizar as informações permitidas.\n");
		}

	}

}

int
main (int argc, char *argv[])
{

	if (argc < 2){
		fprintf (stderr,"Usage: %s hostname create_user @username\n",argv[0]);
		exit (1);
	}

	menu(argc, argv);

	return (0);
}
