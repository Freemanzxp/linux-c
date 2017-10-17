#include <stdio.h>
#include <stdlib.h>
#include "linktable.h"

void help();
void add();
void sub();
void mult();
void divs();
void abss();
void relax();
void quit();

#define CMD_MAX_LEN 128
#define DESC_LEN    1024
#define CMD_NUM     10

/* data struct and its operations */

typedef struct DataNode
{
    tLinkTableNode * pNext;
    char*   cmd;
    char*   desc;
    int     (*handler)();
} tDataNode;

int SearchCondition(tLinkTableNode * pLinkTableNode, void * args)
{
    char * cmd = (char*)args;
    tDataNode * pNode = (tDataNode *)pLinkTableNode;
    if(strcmp(pNode->cmd, cmd) == 0)
    {
        return  SUCCESS;  
    }
    return FAILURE;	       
}

/* find a cmd in the linklist and return the datanode pointer */
tDataNode* FindCmd(tLinkTable * head, char * cmd)
{
    return  (tDataNode*)SearchLinkTableNode(head,SearchCondition, cmd);
}

/* show all cmd in listlist */
int ShowAllCmd(tLinkTable * head)
{
    tDataNode * pNode = (tDataNode*)GetLinkTableHead(head);
    while(pNode != NULL)
    {
        printf("%s - %s\n", pNode->cmd, pNode->desc);
        pNode = (tDataNode*)GetNextLinkTableNode(head,(tLinkTableNode *)pNode);
    }
    return 0;
}

int InitMenuData(tLinkTable ** ppLinkTable)
{

     *ppLinkTable = CreateLinkTable();
     tDataNode * pNode = (tDataNode*)malloc(sizeof(tDataNode));
     pNode->cmd = "help";
     pNode->desc = "help you get started";
     pNode->handler = help;
     AddLinkTableNode(*ppLinkTable, (tLinkTableNode*)pNode);

     pNode = (tDataNode*)(tDataNode*)malloc(sizeof(tDataNode));
     pNode->cmd = "add";
     pNode->desc = "add two numbers";
     pNode->handler = add;
     AddLinkTableNode(*ppLinkTable, (tLinkTableNode*)pNode);

     pNode = (tDataNode*)(tDataNode*)malloc(sizeof(tDataNode));
     pNode->cmd = "sub";
     pNode->desc = "subtraction of two numbers";
     pNode->handler = sub;
     AddLinkTableNode(*ppLinkTable, (tLinkTableNode*)pNode);

     pNode = (tDataNode*)(tDataNode*)malloc(sizeof(tDataNode));
     pNode->cmd = "mult";
     pNode->desc = "multiply two numbers";
     pNode->handler = mult;
     AddLinkTableNode(*ppLinkTable, (tLinkTableNode*)pNode);

     pNode = (tDataNode*)(tDataNode*)malloc(sizeof(tDataNode));
     pNode->cmd = "divs";
     pNode->desc = "div two numbers";
     pNode->handler = divs;
     AddLinkTableNode(*ppLinkTable, (tLinkTableNode*)pNode);

     pNode = (tDataNode*)(tDataNode*)malloc(sizeof(tDataNode));
     pNode->cmd = "abss";
     pNode->desc = "absolute value";
     pNode->handler = abss;
     AddLinkTableNode(*ppLinkTable, (tLinkTableNode*)pNode);

     pNode = (tDataNode*)(tDataNode*)malloc(sizeof(tDataNode));
     pNode->cmd = "relax";
     pNode->desc = "take easy,take a joke!";
     pNode->handler = relax;
     AddLinkTableNode(*ppLinkTable, (tLinkTableNode*)pNode);

     pNode = (tDataNode*)malloc(sizeof(tDataNode));
     pNode->cmd = "quit";
     pNode->desc = "Quit from Menu Program V1.0";
     pNode->handler = quit;
     AddLinkTableNode(*ppLinkTable, (tLinkTableNode*)pNode);
	 
     return 0;
}


tLinkTable * head = NULL;

int main()
{
    InitMenuData(&head); 
   /* cmd line begins */
    while(1)
    {
        char cmd[CMD_MAX_LEN];
        printf("Input a cmd number > ");
        scanf("%s", cmd);
        tDataNode *p = FindCmd(head, cmd);
        if( p == NULL)
        {
            printf("This is a wrong cmd!\n ");
            continue;
        }
        printf("%s - %s\n", p->cmd, p->desc); 
        if(p->handler != NULL) 
        { 
            p->handler();
        }
   
    }
}

void help()
{
    ShowAllCmd(head);
}

void add()
{
    double num1, num2, add;
    printf("Please input two numbers:");
    scanf("%lf %lf", &num1, &num2);
    add = num1 + num2;
    printf("%lf + %lf = %lf\n", num1, num2, add);
}

void sub()
{
    double num1, num2, sub;
    printf("Please input two numbers:");
    scanf("%lf %lf", &num1, &num2);
    sub = num1 - num2;
    printf("%lf - %lf = %lf\n", num1, num2, sub);
}

void divs()
{
    double num1, num2, result;
    printf("Please input two numbers:");
    scanf("%lf %lf", &num1, &num2);
    if(num2==0)
    {
        printf("Error:num2 can't be 0!\n");
    }
    else
    {
        result = num1 / num2;
        printf("%lf / %lf = %f\n", num1, num2, result);
    }
}

void mult()
{
    double num1, num2, mult;
    printf("Please input two numbers:");
    scanf("%lf %lf", &num1, &num2);
    mult = num1 * num2;
    printf("%lf * %lf = %f\n", num1, num2, mult);
}

void abss()
{
    double num, result;
    printf("Please input one number:");
    scanf("%lf", &num);
    if(num<0)
    {
        result = -num;
    }
    else result = num;
    printf("|%lf| = %f\n", num, result);
}

void relax()
{
    printf("A Good Boy:\n");
    printf("Little Robert asked his mother for two cents.\nWhat did you do with the money I gave you yesterday?\n");
    printf("I gave it to a poor old woman, he answered.You are a good boy, said the mother proudly. Here are two cents more.\nBut why are you so interested in the old woman?She is the one who sells the candy.\n");
}

void quit()
{
    exit(0);
}
