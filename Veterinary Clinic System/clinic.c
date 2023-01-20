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
#include <string.h>
#include <stdio.h>

// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"

//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
           "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
            "Number: %05d\n"
            "Phone : ", patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
            patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}




//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData* data)
{
    int selection;

    do {
        printf("Veterinary Clinic System\n"
               "=========================\n"
               "1) PATIENT     Management\n"
               "2) APPOINTMENT Management\n"
               "-------------------------\n"
               "0) Exit System\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            printf("<<< Feature not yet available >>>\n\n");
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do {
        printf("Patient Management\n"
               "=========================\n"
               "1) VIEW   Patient Data\n"
               "2) SEARCH Patients\n"
               "3) ADD    Patient\n"
               "4) EDIT   Patient\n"
               "5) REMOVE Patient\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            suspend();
            break;
        case 2:
           searchPatientData(patient, max);
           suspend();
            break;
        case 3:
           addPatient(patient, max);
           suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
           removePatient(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
    int selection;

    do {
        printf("Edit Patient (%05d)\n"
               "=========================\n"
               "1) NAME : %s\n"
               "2) PHONE: ", patient->patientNumber, patient->name);
        
        displayFormattedPhone(patient->phone.number);
        
        printf("\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! Put all the remaining function definitions below !!!
// Note: Maintain the same order/sequence as it is listed in the header file
// ---------------------------------------------------------------------------

// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void displayAllPatients(const struct Patient patient[], int max, int fmt)
{
    {
        int i, flag = 0;
     
        for (i = 0; i < max; i++)
        {
            if (patient[i].patientNumber != 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            printf("*** No records found ***\n");
        }
        else
        {
            displayPatientTableHeader();
            for (i = 0; i < max; i++)
            {
                
                if (patient[i].patientNumber != 0)
                {

                    displayPatientData(&patient[i], fmt);

                }
            }
        }
        printf("\n");





    }
}


// Search for a patient record based on patient number or phone number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientData(const struct Patient patient[], int max)
{

   
    int choice;
    do
    {
        printf("Search Options\n"
            "=========================\n"
            "1) By patient number\n"
            "2) By phone number\n"
            "-------------------------\n"
            "0) Previous menu\n"
            "-------------------------\n"
            "Selection: ");
       
        choice = inputIntRange(0, 2);
        putchar('\n');
        // call the appropriate function depending on user input
        if (choice == 1)
        {
            searchPatientByPatientNumber(patient, max);
            
        }

        else if (choice == 2)
        {
            searchPatientByPhoneNumber(patient, max);
            suspend();
        }


    } while (choice);
}

// Add a new patient record to the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void addPatient(struct Patient patient[], int max)
{
    int i;
    int x;
    int isFound = 0;
   
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber == 0)
        {
             isFound = 1;
             x = i;
             break;
        }
    }

    if (isFound == 0)
    {
        printf("ERROR: Patient listing is FULL!\n\n");
    }
    else
    {
        patient[x].patientNumber = nextPatientNumber(patient, max);
        inputPatient(&patient[x]);
        printf("*** New patient record added ***\n");
    }
    
    
        
}
    
    
    
    
    
    
    
    

// Edit a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)


void editPatient(struct Patient patient[], int max)
{
    int index;

    printf("Enter the patient number: ");
    int pno = inputIntPositive();

     index = findPatientIndexByPatientNum(pno, patient, max);
     if (index == -1)
     {
         printf("ERROR: Patient record not found!\n");
     }
     else
     {
         menuPatientEdit(&patient[index]);
     }
}

// Remove a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void removePatient(struct Patient patient[], int max)
{
    printf("Enter the patient number: ");
    int patno = inputIntPositive();

        int index = findPatientIndexByPatientNum(patno, patient, max);
        if (index == -1)
        {
            printf("ERROR: Patient record not found!\n");

            
        }
               

        else
        {
            printf("\n");
            displayPatientTableHeader();
            displayPatientData(&patient[index], 2);

            printf("\nAre you sure you want to remove this patient record? (y/n): ");
            char ysno = inputCharOption("YynN");
            if (ysno == 'y' || ysno == 'Y')
            {

                // yes delete the record
                patient[index].patientNumber = 0;


                printf("\nPatient record has been removed!\n\n");


            }
            else if (ysno == 'n' || ysno == 'N')
            {
                printf("Operation aborted.\n");

            }
        }
    
        





}


//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientByPatientNumber(const struct Patient patient[], int max)
{

    int i;
    int index;

    int pno;


    printf("\nEnter the patient number: ");
    pno = inputIntPositive();


    index = findPatientIndexByPatientNum(pno, patient, max);
    if (index == -1)
    {
        printf("\n*** No records found ***\n\n");

        

    }
    else
    {
        printf("\n");
        displayPatientData(&patient[index], FMT_FORM);
        printf("\n");

    }




}

// Search and display patient records by phone number (tabular)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientByPhoneNumber(const struct Patient patient[], int max) 
{
    char pnum[11];
    printf("Search by phone number: ");
    inputCString(pnum, 10, 10);
    printf("\n");
    int flag = 0;
    int i;
    for (i = 0; i < max; i++)
    {
        if (strcmp(pnum, patient[i].phone.number) == 0)
        {
            flag = 1;
            break;
        }
    }
    displayPatientTableHeader();
    if (flag == 0)
    {
        printf("\n");
        printf("*** No records found ***\n");
    }
    else
    {
        for (i = 0; i < max; i++)
        {
            if (strcmp(pnum, patient[i].phone.number) == 0)
                displayPatientData(&patient[i], FMT_TABLE);
        }
    }
    printf("\n");
}





// Get the next highest patient number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)


int nextPatientNumber(const struct Patient patient[], int max)
{
    // find and set unique account number
    int i, largest = -1;
    for (i = 0; i < max; i++)
    {
        int temp = patient[i].patientNumber;
        if (temp > largest)
        {
            largest = temp;
        }
    }
   return largest ;
}








// Find the patient array index by patient number (returns -1 if not found)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
int findPatientIndexByPatientNum(int patientNumber,const struct Patient patient[], int max)
{

    {
        int i;
        
        int x = -1;
      
        for (i = 0; i < max; i++)
        {
           
            if (patient[i].patientNumber == patientNumber)
            {
               x = i;
                break;
            }
        }
        return x;
    }

}












//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void inputPatient(struct Patient* patient)
{
    printf("Patient Data Input\n"
        "------------------\n");
    printf("Number: " );
    patient->patientNumber = inputIntPositive();
    printf("Name  : ");
    inputCString(patient->name, 1, NAME_LEN);
    printf("\n");
   
    inputPhoneData(&(patient->phone));


}

// Get user input for phone contact information
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void inputPhoneData(struct Phone* phone)
{

    int choice;
    
    printf("Phone Information\n"
        "-----------------\n");
    printf("How will the patient like to be contacted?\n");
    printf("1. Cell\n");
    printf("2. Home\n");
    printf("3. Work\n");
    printf("4. TBD\n");
    printf("Selection: ");
    choice = inputIntRange(1, 4);

    printf("\n");
    if (choice == 1)
    {
        printf("Contact: ");
        puts("CELL");
        strcpy(phone->description, "CELL");
    }
    if (choice == 2)
    {
        printf("Contact: ");
        puts("HOME");
        strcpy(phone->description, "HOME");
    }
    if (choice == 3)
    {
        printf("Contact: ");
        puts("WORK");
        strcpy(phone->description, "WORK");
    }
    if (choice == 4)
    {
        strcpy(phone->description, "TBD");
    }
    else
    {
        printf("Number : ");
        inputCString(phone->number, 1, PHONE_LEN);
        printf("\n");
    }


}