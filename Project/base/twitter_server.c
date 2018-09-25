/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "twitter.h"

typedef void* List;
typedef void* Item;
typedef void* Posic;
typedef void (*eraseItemL)(Item);
typedef int (*compareToL)(Item, Item);

typedef struct Element {
  Item info;
  struct Element *next;
  struct Element *previous;
} Element;

typedef struct Base {
  Element *first;
  Element *last;
  int size;
} Base;

List createL() {
  Base *base = NULL;
  base = (Base *)malloc(sizeof(Base));
  if (base != NULL) {
    base->first = NULL;
    base->last = NULL;
    base->size = 0;
  } else {
    printf("Error in alocation memory.\n");
  }
  return (List)base;
}


int lengthL(List list) {
  Base *base = (Base *)list;
  if (list != NULL)
    return base->size;

  return 0;
}

int isEmpty(List list) {
  Base *L1 = (Base *)list;
  if (L1->first == NULL) {
    return 1;
  }
  return 0;
}

int insertEndL(List list, Item item) {
  Base *base = (Base *)list;
  Element *element = NULL;
  if (base != NULL) {
    element = (Element *)malloc(sizeof(Element));
    if (element == NULL) {
      return 0;
    }
    element->info = item;
    if (base->first != NULL) {
      element->next = NULL;
      element->previous = base->last;
      base->last->next = element;
      base->last = element;
    } else {
      base->first = element;
      base->last = element;
      element->next = NULL;
      element->previous = NULL;
    }
    base->size = base->size + 1;
    return 1;
  }
  return 0;
}


Item searchItemL(List list, Item item, compareToL func) {
  Base *base = (Base *)list;
  Element *aux = NULL;
  Item info = NULL;
  int i = 0, j = 0;
  if (base != NULL) {
    if (base->first != NULL) {
      j = base->size;
      aux = base->first;
      for (i = 1; i <= j; i++) {
        if (func(aux->info, item) == 1) {
          info = aux->info;
          break;
        }
        aux = aux->next;
      }
    }
  }
  return info;
}

int removeBeginL(List list, eraseItemL func) {
  Base *base = (Base *)list;
  Element *aux = NULL;
  if (base != NULL) {
    if (base->first != NULL && base->size == 1) {
      if (func != NULL)
        func(base->last->info);
      free(base->last);
      base->last = NULL;
      base->first = NULL;
      base->size = base->size - 1;
      return 1;
    }
    if (base->first != NULL) {
      aux = base->first->next;
      aux->previous = NULL;
      if (func != NULL)
        func(base->first->info);
      free(base->first);
      base->first = aux;
      base->size = base->size - 1;
      return 1;
    }
  }
  return 0;
}

int removeEndL(List list, eraseItemL func) {
  Base *base = (Base *)list;
  Element *aux = NULL;
  if (base != NULL) {
    if (base->first != NULL && base->size == 1) {
      if (func != NULL)
        func(base->last->info);
      free(base->last);
      base->last = NULL;
      base->first = NULL;
      base->size = base->size - 1;
      return 1;
    }
    
    if (base->first != NULL && base->size > 1) {
      aux = base->last->previous;
      aux->next = NULL;
      if (func != NULL)
        func(base->last->info);
      free(base->last);
      base->last = aux;
      base->size = base->size - 1;
      return 1;
    }
  }
  return 0;
}

int removeMiddleL(List list, int p, eraseItemL func) {
  Base *base = (Base *)list;
  Element *aux = NULL;
  int i, j;
  if (p <= 0) {
    return 0;
  }
  j = lengthL(list);
  if (p == 1) {
    removeBeginL(list, func);
    return 1;
  } else if (p >= j) {
    removeEndL(list, func);
    return 1;
  } else {
    if (base != NULL) {
      if (base->first != NULL) {
        aux = base->first;
        base->size = base->size - 1;
        for (i = 1; i <= j; i++) {
          if (i == p) {
            if (func != NULL)
              func(aux->info);
            aux->previous->next = aux->next;
            aux->next->previous = aux->previous;
            free(aux);
            break;
          }
          aux = aux->next;
        }
        return 1;
      }
    }
  }
  return 0;
}

Item getItemL(List list, int p) {
  Base *base = (Base *)list;
  int i, j;
  Element *aux = NULL;
  Item item = NULL;
  if (base != NULL) {
    if (base->first != NULL) {
      aux = base->first;
      j = lengthL(list);
      if (p <= 0 || p > j) {
        return NULL;
      }
      for (i = 1; i <= j; i++) {
        if (i == p) {
          item = aux->info;
          return item;
        }
        aux = aux->next;
      }
    }
  }
  return NULL;
}


int eraseListL(List list, eraseItemL func) {
  Base *base = (Base *)list;
  Element *aux, *aux2;
  int i, j;
  if (base != NULL) {
    if (base->first != NULL) {
      aux = base->first;
      j = lengthL(list);
      for (i = 1; i <= j; i++) {
        aux2 = aux;
        aux = aux->next;
        if (func != NULL)
          func(aux2->info);
        free(aux2);
      }
      base->first = NULL;
      base->last = NULL;
      base->size = 0;
      return 1;
    }
  }
  return 0;
}

void eraseBase(List list) {
  Base *base = (Base *)list;
  if (base != NULL) {
    free(base);
  }
}

void removeItemL(List list, Posic p) {
  Base *L1 = (Base *)list;
  Element *No = (Element *)p;
  Element *aux, *aux2;
  if (isEmpty(list) == 0) {
    if (No->previous == NULL) {
      aux = No->next;
      L1->first = aux;
      if (L1->first != NULL) {
        L1->first->previous = NULL;
      }
    } else if (No->next == NULL) {
      aux = No->previous;
      L1->last = aux;
      if (L1->last != NULL) {
        L1->last->next = NULL;
      }
    } else {
      aux = No->previous;
      aux2 = No->next;
      aux->next = aux2;
      aux2->previous = aux;
    }

    if (No != NULL) {
      free(No);
    }
    L1->size--;
  }
}

Item get(List list, Posic p) {
  Element *No = (Element *)p;
  if (isEmpty(list) == 0) {
    if (No->info != NULL) {
      return No->info;
    }
  }
  return NULL;
}

Posic getFirst(List list) {
  Base *L1 = (Base *)list;
  return L1->first;
}

Posic getNext(List list, Posic p) {
  Element *No = (Element *)p;
  return No->next;
}

Posic getLast(List list) {
  Base *L1 = (Base *)list;
  return L1->last;
}

Posic getPrevious(List list, Posic p) {
  Element *No = (Element *)p;
  return No->previous;
}

List startList(List list){
  if(list == NULL){
    return createL();
  }else{
    return list;
  }
}



List USER = NULL;
List TOPIC = NULL;
List POST = NULL;
List TWITTE = NULL;
List FOLLOWERS = NULL;


int compareUsers(Item item1, Item item2){
	data *data1 = (data*) item1;
	data *data2 = (data*) item2;

	if(strcmp(data1->username, data2->username) == 0){
		return 1;
	}

	return 0;
}

int compareFollewers(Item item1, Item item2){
	data *data1 = (data*) item1;
	data *data2 = (data*) item2;

	if((strcmp(data1->username, data2->username) == 0) && (strcmp(data1->otherName, data2->otherName) == 0) ){
		return 1;
	}

	return 0;
}


//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////

int *
create_user_1_svc(char **argp, struct svc_req *rqstp)
{
	static int  result;
  USER = startList(USER);
  data *dt;
  int i, length = lengthL(USER);

  Element *element = ((Base *)USER)->first;
  while(element != NULL){
    data *dt = (data *)(element->info);
    if(strcmp(dt->username, *argp)==0){
      printf("Erro ao criar usuário %s.", dt->username);
      result = 0;
      return &result;
    }else{
      element = element->next;
    }
  }
  dt = malloc(sizeof(data));
  dt->username = malloc((strlen(*argp)+1)*sizeof(char));
  strcpy(dt->username, *argp);

  result = insertEndL(USER, dt);

  printf("Usuário %s criado.\n", dt->username);

	return &result;
}

char **
list_users_1_svc(void *argp, struct svc_req *rqstp)
{
	static char * result = NULL;
  result = NULL;
  if(lengthL(USER)==0){
    return &result;
  }

  char *aux;
  USER = startList(USER);
  data *dt;
  Element *element = ((Base *)USER)->first;
  printf("Usuários:\n");
  while(element!=NULL){
    dt = (data *)(element->info);
    printf("%s(%d)", dt->username, lengthL(USER));
    if(result == NULL){
      result = malloc(sizeof(char)*(strlen(dt->username) + 2));
      strcpy(result, dt->username);
    }else{
      aux = malloc(sizeof(char)*(strlen(result) + strlen(dt->username) + 2));
      strcpy(aux, result);
      strcat(aux, dt->username);
      result = aux;
    }

    strcat(result, "\n");
    element = element->next;
  }

  printf("%s\n", result);
	return &result;
}

int *
follow_1_svc(data *argp, struct svc_req *rqstp)
{
	static int  result;

	FOLLOWERS = startList(FOLLOWERS);
  USER = startList(USER);

  char *username = argp->username;
  char *otherName = argp->otherName;



  data *dt;
  Element *element = ((Base *)USER)->first;
  while(element!=NULL){
    dt = (data *)(element->info);

    if(strcmp(dt->otherName, otherName) == 0){
      element = ((Base *)FOLLOWERS)->first;
      while(element!=NULL){
        dt = (data *)(element->info);
        if(strcmp(username, dt->username)==0 && strcmp(otherName, dt->otherName)){
          result = 0;
          return &result;
        }
        element = element->next;
      }
      dt = malloc(sizeof(data));
      dt->username = malloc(sizeof(char)*(strlen(username) + 1));
      dt->otherName = malloc(sizeof(char)*(strlen(otherName) + 1));
      strcpy(dt->username, username);
      strcpy(dt->otherName, otherName);

      result = insertEndL(FOLLOWERS, dt);
      printf("Usuário %s está seguindo %s.\n", dt->username, dt->otherName);
      return &result;
    }
    element = element->next;
  }

  result = 0;
  return &result;

}

int *
post_topic_1_svc(data *argp, struct svc_req *rqstp)
{
	static int result;

  if(TOPIC == NULL){
    result = 0;
    return &result;
  }

  char *user = argp->username;
  char *topic = argp->topic;
  char *text = argp->text;



  data *dt;
  Element *element = ((Base *)TOPIC)->first;
  while(element!=NULL){
    dt = (data *)(element->info);
    
 
    element = element->next;
  }



  
  /*data *dt;
  Element **/element = ((Base *)TOPIC)->first;
  while(element!=NULL){
    dt = (data *)(element->info);
    
    if(strcmp(dt->topic, topic)==0){
      POST = startList(POST);

      dt = malloc(sizeof(data));
      dt->username = malloc(sizeof(char)*(strlen(user)+1));
      dt->topic = malloc(sizeof(char)*(strlen(topic)+1));
      dt->text = malloc(sizeof(char)*(strlen(text)+1));
      strcpy(dt->username, user);
      strcpy(dt->topic, topic);
      strcpy(dt->text, text);
      
      result = insertEndL(POST, dt);
      printf("Nova postagem em %s : \nUsuário : %s\n%s\n", dt->topic, dt->username, dt->text);
	    return &result;
    }
    element = element->next;
  }

  result = 0;
	return &result;
}

char **
hashtags_1_svc(void *argp, struct svc_req *rqstp)
{
	static char *result = NULL;
  data *p = NULL;
  Posic posic;
  char *string1 = NULL;


	TOPIC = startList(TOPIC);

	if(!isEmpty(TOPIC)){
		
		posic = getFirst(TOPIC);
    do{
      p = (data*) get(TOPIC, posic);
      if(p != NULL){
        if(result == NULL){
          string1 = NULL;
          string1 = (char*) malloc(strlen(result) * sizeof(char));
          if(string1 != NULL){
            strcpy(string1, result);
            free(result);
            result = (char*) malloc((strlen(string1) + strlen(p->topic)) * sizeof(char));
            if(result != NULL){
              strcpy(result, string1);
              strcat(result, p->topic);
            }

          }
        }
        else
        {
          result = (char*) malloc(strlen(p->topic) * sizeof(char));
          if(result != NULL){
            strcpy(result, p->topic);
          }
        }
      }
      posic = getNext(TOPIC, posic);
    }while(posic != NULL);


	}

 	return &result;
}

int *
new_topic_1_svc(data *argp, struct svc_req *rqstp)
{
	static int  result = 0;
	data *t = NULL;

	TOPIC = startList(TOPIC);

	if(!isEmpty(TOPIC)){
		
		t = (data*) malloc(sizeof(data));

		if(t == NULL){
			return &result;
		}

		t->username = (char*) malloc(strlen(argp->username) * sizeof(char));
		if(t->username == NULL){
			return &result;
		}

		t->topic = (char*) malloc(strlen(argp->topic) * sizeof(char));
		if(t->topic == NULL){
			return &result;
		}

		strcpy(t->username, argp->username);
		strcpy(t->topic, argp->topic);

		if(insertEndL(TOPIC, t) != 1){
			return &result;
		}

		result = 1;
	}

 	return &result;
}

int *
unfollow_1_svc(data *argp, struct svc_req *rqstp)
{
	static int  result = 0;
	data *t = NULL;
	data *p = NULL;
  Posic posic = NULL;

	FOLLOWERS = startList(FOLLOWERS);

	if(!isEmpty(FOLLOWERS)){
		
		t = (data*) malloc(sizeof(data));

		if(t == NULL){
			return &result;
		}

		t->username = (char*) malloc(strlen(argp->username) * sizeof(char));
		if(t->username == NULL){
			return &result;
		}

		t->otherName = (char*) malloc(strlen(argp->otherName) * sizeof(char));
		if(t->otherName == NULL){
			return &result;
		}

		strcpy(t->username, argp->username);
		strcpy(t->otherName, argp->otherName);

    posic = getFirst(FOLLOWERS);
    do{
      p = (data*) get(FOLLOWERS, posic);
      if(compareFollewers(t, p) == 1){
        removeItemL(FOLLOWERS, posic);
        p = NULL;
        break;
      }
      posic = getNext(FOLLOWERS, posic);
    }while(posic != NULL);

		result = 1;
	}

 	return &result;
}

char **
retrievetopic_1_svc(data *argp, struct svc_req *rqstp)
{
	static char *result = NULL;
  data *p = NULL;
  Posic posic;
  char *string1 = NULL;


	POST = startList(POST);

	if(!isEmpty(POST)){
		
		posic = getFirst(POST);
    do{
      p = (data*) get(POST, posic);
      if(p != NULL){
        if(strcmp(p->topic, argp->topic) == 0){
          if(result == NULL){
            string1 = NULL;
            string1 = (char*) malloc(strlen(result) * sizeof(char));
            if(string1 != NULL){
              strcpy(string1, result);
              free(result);
              result = (char*) malloc((strlen(string1) + strlen(p->text)) * sizeof(char));
              if(result != NULL){
                strcpy(result, string1);
                strcat(result, p->text);
              }

            }
          }
          else
          {
            result = (char*) malloc(strlen(p->text) * sizeof(char));
            if(result != NULL){
              strcpy(result, p->text);
            }
          }
        }

      }
      posic = getNext(POST, posic);
    }while(posic != NULL);

	}

 	return &result;
}

int *
twitte_1_svc(data *argp, struct svc_req *rqstp)
{
	static int  result = 0;
	data *t = NULL;

	TWITTE = startList(TWITTE);

	if(!isEmpty(TWITTE)){
		
		t = (data*) malloc(sizeof(data));

		if(t == NULL){
			return &result;
		}

		t->username = (char*) malloc(strlen(argp->username) * sizeof(char));
		if(t->username == NULL){
			return &result;
		}

		t->text = (char*) malloc(strlen(argp->text) * sizeof(char));
		if(t->text == NULL){
			return &result;
		}

		strcpy(t->username, argp->username);
		strcpy(t->text, argp->text);

		if(insertEndL(TWITTE, t) != 1){
			return &result;
		}

		result = 1;
	}

 	return &result;
}
