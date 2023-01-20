/*
*****************************************************************************
                        Assignment 1 - Milestone 2
Full Name  : Prince Abiy
Student ID#: 133240218
Email      : pabiy@myseneca.ca
Section    : ZHH

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//
// Copy your work done from Milestone #1 (core.c) into this file
// - Organize your functions in the same order as they are listed in the core.h file
// - Also copy the commented "sections" to help with finding functions quickly!
//

#include<time.h>
#include"core.h"
#include<string.h>

int flag = 0;
// Uses the time.h library to obtain current year information
// Get the current 4-digit year from the system
int currentYear(void)
{
    time_t currentTime = time(NULL);
    return localtime(&currentTime)->tm_year + 1900;
}

// Empty the standard input buffer
void clearStandardInputBuffer(void)
{
    while (getchar() != '\n')
    {
        ; // On purpose: do nothing
    }
}

void suspend(void)
{
    printf("<< ENTER key to Continue... >>");
    clearStandardInputBuffer();
    putchar('\n');

}

int inputInt()
{

    int tempInt;
    char tempChar = 'x';
    do
    {

        scanf("%d%c", &tempInt, &tempChar);


        if (tempChar != '\n')
        {
            clearStandardInputBuffer();
            printf("Error! Input a whole number: ");

        }


    } while (tempChar != '\n');


    return tempInt;



}

int inputIntPositive()
{
   
    int num;

    {

         num = inputInt();

        while (num <= 0)
        {
            printf("ERROR! Value must be > 0: ");
            num = inputInt();
        }

        


    }while (num <= 0);
        return num;
}

int inputIntRange(int lowerBound, int upperBound)
{

    int tempInt;
    char tempChar = 'x';
    do
    {

        scanf("%d%c", &tempInt, &tempChar);


        if (tempChar != '\n')
        {
            clearStandardInputBuffer();

            printf("Error! Input a whole number: ");

        }
        else
        {
            if (tempInt >= lowerBound && tempInt <= upperBound)
            {
                return tempInt;
            }
            else
            {

                printf("ERROR! Value must be between %d and %d inclusive: ", lowerBound, upperBound);
            }
        }
    } while ((tempChar != '\n') || (tempInt < lowerBound || tempInt > upperBound));
    return tempInt;
}

char inputCharOption(char str[])
{



    while (1)
    {

        char c;
        char tempChar;

        scanf("%c%c", &c, &tempChar);
        int isMatched = 0;
        int i = 0;


        if (tempChar == '\n')
        {

            while (1)
            {
                if (str[i] == '\0')
                    break;

                if (str[i] == c)
                {
                    isMatched = 1;
                    break;
                }
                i++;
            }


        }
        else
        {

            clearStandardInputBuffer();
        }
        if (isMatched == 0)
        {
            // not found 
            printf("ERROR: Character must be one of [%s]: ", str);
        }
        else if (isMatched == 1)
        {
            // found
            return c;
        }

    }
    clearStandardInputBuffer();
}

void inputCString(char* c, int lowerBound, int upperBound)
{

    while (1)
    {

        char str[1000];


        scanf("%[^\n]s", str);
        int len = strlen(str);
        if (len >= lowerBound && len <= upperBound)
        {

            strcpy(c, str);
            clearStandardInputBuffer();
            break;
        }
        else
        {

            if (lowerBound == upperBound)
            {
                printf("ERROR: String length must be exactly %d chars: ", upperBound);

            }
            else if (len > upperBound)
            {
                printf("ERROR: String length must be no more than %d chars: ", upperBound);

            }
            else
            {
                printf("ERROR: String length must be between %d and %d chars: ", lowerBound, upperBound);

            }
            clearStandardInputBuffer();
        }
    }


}



int countchar(const char* s)
{
    int count = 0;
    while (*s != '\0')
    {
        count++;
        s++;
    }
    return count;
}



void displayFormattedPhone(const char* phone)
{

    if (phone == NULL)
    {
        printf("(___)___-____");
        return;
    }
    int i = 0;
    int count = 0;





    int len = countchar(phone);
    for (i = 0; i < len; i++)
    {
        if (phone[i] >= '0' && phone[i] <= '9')
        {
            count++;
        }
    }

    if (len != 10 || len != count)
    {
        printf("(___)___-____");
    }

    else
    {
        printf("(%c%c%c)%c%c%c-%c%c%c%c",
            phone[0],
            phone[1],
            phone[2],
            phone[3],
            phone[4],
            phone[5],
            phone[6],
            phone[7],
            phone[8],
            phone[9]);
    }
}