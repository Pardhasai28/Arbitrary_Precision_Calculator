#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define SUCCESS 1
#define FAILURE 0

#define RED "\033[1;31m" 
#define RESET "\033[0m"
#define GREEN "\033[1;32m"
#define BBLUE "\033[1;94m"
#define BCYAN "\033[1;96m"
#define BMAGENTA "\033[1;95m"
#define ORANGE "\033[38;5;208m"
#define YELLOW "\033[1;33m"

typedef struct Dllist
{
    int data;
    struct Dllist *prev;
    struct Dllist *next;
}Dll;
int compare_list(Dll *h1, Dll *h2);
int validate_num(char *);
int validate_operator(char *);
int compare_abs(char *a, char *b);
int create_list(char arr[],Dll **head,Dll **tail);
int print_list(Dll *head);
int print_resultlist(Dll *head);
void Add(Dll *head1,Dll *head2,Dll *tail1,Dll *tail2,Dll **rhead,Dll **rtail);
void Sub(Dll *head1,Dll *head2,Dll *tail1,Dll *tail2,Dll **rhead,Dll **rtail);
void Mul(Dll *head1,Dll *head2,Dll *tail1,Dll *tail2,Dll **rhead,Dll **rtail);
void Div(Dll *head1,Dll *head2,Dll *tail1,Dll *tail2,Dll **rhead,Dll **rtail);
void Mod(Dll *head1,Dll *head2,Dll *tail1,Dll *tail2,Dll **rhead,Dll **rtail);
void Pow(Dll *head1,Dll *head2,Dll *tail1,Dll *tail2,Dll **rhead,Dll **rtail);
