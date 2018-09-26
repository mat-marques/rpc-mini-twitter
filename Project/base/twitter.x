#define PROGRAM_NUMBER 0x30D0D0DF
#define VERSION_NUMBER 1

/* tipo de dado que será passado aos procedimentos remotos */

struct data
{
    string username<>;
    string otherName<>;
    string text<>;
    string topic<>;
    string timestamp<>;
};

/* Definição da interface que será oferecida aos clientes */
program TWITTER_PROG
{

    version TWITTER_VERSION
    {

        int create_user(string) = 1;

        string list_users(void) = 2;

        int follow (data) = 3;

        int post_topic(data) = 4;

        string hashtags(void) = 5;

        int new_topic(data) = 6;

        int unfollow (data) = 7;

        string retrievetopic(data) = 8;

        int twitte(data) = 9;

    } = VERSION_NUMBER;

} = PROGRAM_NUMBER;