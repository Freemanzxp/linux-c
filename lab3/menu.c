#include<stdio.h>
#include<stdlib.h>
#include"linklist.h"


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


/* menu program */

static tDataNode head[] = 
{
    {"help",  "help you get started      ", help, &head[1]},
    {"add" ,  "add two numbers           ", add,  &head[2]},
    {"sub",   "subtraction of two numbers", sub,  &head[3]},
    {"mult",  "multiply two numbers      ", mult, &head[4]},
    {"divs",  "div two numbers           ", divs, &head[5]},
    {"abss",  "absolute value            ", abss, &head[6]},
    {"relax", "take easy,take a joke!    ", relax,&head[7]},
    {"quit",  "exit                      ", quit, NULL}
};


int main()
{
    /* cmd line begins */
    while(1)
    {
        char cmd[CMD_MAX_LEN];
	printf("Input a cmd number >>>  ");
	scanf("%s", cmd);
	tDataNode *p = FindCmd(head, cmd);
	if(p == NULL)
	{
	    printf("ERROR Command: '%s'\n", cmd);
	}
	else
	{
	    p->handler();
	}
    }
    return 0;
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
