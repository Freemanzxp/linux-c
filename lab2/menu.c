#include <stdio.h>
#include <stdlib.h>

void help();
void add();
void sub();
void mult();
void divs();
void abss();
void relax();
void quit();

int main()
{
    char input[1024];
    printf("Welcome to my world!\n");
    while(1)
    {
	scanf("%s", input);
	if(strcmp(input, "help") == 0)
	{
	    help();
	}
	else if(strcmp(input, "add") == 0)
	{
	    add();
	}
	else if(strcmp(input, "sub") == 0)
        {
	    sub();
        }
	else if(strcmp(input, "mult") == 0)
        {
            mult();
        }
	else if(strcmp(input, "divs") == 0)
        {
            divs();
        }
        else if(strcmp(input, "abss") == 0)
        {
            abss();
        }
	else if(strcmp(input, "relax") == 0)
        {
            relax();
        }
	else if(strcmp(input, "quit") == 0)
        {
            quit();
        }
	else
        {
            printf("Error!\n");
            printf("Please input help!\n");
        }
    }
    return 0;
}

void help()
{
    printf("*|*********|***************************|\n");
    printf("*|OPTION   |FUNCTION DESCRIPTION       |\n");
    printf("*|~~~~~~~~~|~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
    printf("*|help     |help you get started       |\n");
    printf("*|add      |add two numbers            |\n");
    printf("*|sub      |subtraction of two numbers |\n");
    printf("*|mult     |multiply two numbers       |\n");
    printf("*|divs     |div two numbers            |\n");
    printf("*|abss     |absolute value             |\n");
    printf("*|relax    |take easy,take a joke!     |\n");
    printf("*|quit     |exit                       |\n");
    printf("*|~~~~~~~~~|~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
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
	printf("Error:num2 can't be 0!");
    }
    result = num1 / num2;
    printf("%lf / %lf = %f\n", num1, num2, result);
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
