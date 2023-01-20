/*
Name - Prince Abiy
ID- 133240218
Section - ZCC
Email - pabiy@myseneca.ca

*/
#ifndef COMMONHELPERS_H_
#define COMMONHELPERS_H_

int currentYear(void);
void clearStandardInputBuffer(void);

// helper functions 

int getInteger();
int getPositiveInteger();
double getDouble();
double getPositiveDouble();
int getIntFromRange(int lowerBound, int upperBound);
char getCharOption(char str[]);
void getCString(char* c, int lowerBound, int upperBound);
void getPassword(char* c); //
#endif