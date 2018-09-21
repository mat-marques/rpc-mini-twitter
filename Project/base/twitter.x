#define PROGRAM_NUMBER 12345678
#define VERSION_NUMBER 1

/* tipo de dado que será passado aos procedimentos remotos */
struct followUser
{

    char *username;
    char *otherName;

};

struct post
{

    char *username;
    char *topic;
    char *text;

};

struct topic  
{

    char *username;
    char *topic;

};

struct retrieve  
{

    char *username;
    char *topic;
    char *timestamp;

};

struct twitteMessage
{

    char *username;
    char *text;

};

/* Definição da interface que será oferecida aos clientes */
program INTERFACE_PROG
{

    version INTERFACE_VERSION
    {

        int create_user(string) = 1;

        string list_users(void) = 2;

        int follow (followUser) = 3;

        int post_topic(post) = 4;

        string hashtags(void) = 5;

        int new_topic(topic) = 6;

        int unfollow (followUser) = 7;

        int retrievetopic(retrieve) = 8;

        int twitte(twitteMessage) = 9;

    } = VERSION_NUMBER;

} = PROGRAM_NUMBER;