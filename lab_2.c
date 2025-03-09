// Program Name : Parts Record Manager
// Author : Christina Tu

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {                    // holds part records
    int partNum;
    char partName[100];
    float partSize;
    char partSizeMetric[20];
    float partCost;
} partRecord;


// variable used only in this file
partRecord *records = NULL;         // a pointer to allocate records
int numOfRecords = 0;          
static int numOfChanges = 0;  


void printAllRecords() {
    printf("Current Records: \n");
    
    for (int i = 0; i < numOfRecords; i++) {
        printf ("Record %d:\n", i + 1);
        printf ("Part Number = %d\n", records[i].partNum);
        printf ("Part Name = %s\n", records[i].partName);
        printf ("Part Size = %.2f\n", records[i].partSize);
        printf ("Part Size Metric = %s\n", records[i].partSizeMetric);
        printf ("Part Cost = %.2f\n", records[i].partCost);
        printf ("\n");
    }
}

int printNumOfChanges(bool print) {
    if (print) {
        printf ("You have modified the database %d times\n", numOfChanges);
    } else {
        numOfChanges++;
        printf ("%d modifications so far\n", numOfChanges);
    }
    return numOfChanges;
}

void addRecord() {
    partRecord *newRecords = (partRecord *) malloc ((numOfRecords + 1) * sizeof(partRecord));       // allocate new memory to store updated records list
    if (!newRecords) {
        printf ("Memory Allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < numOfRecords; i++) {        // copying existing records into new memory
        newRecords[i] = records[i];
    }

    printf ("\nEnter Part Number: ");
    scanf ("%d", &newRecords[numOfRecords].partNum);

    printf ("Enter Part Name: ");
    scanf ("%s", newRecords[numOfRecords].partName);

    printf ("Enter Part Size: ");
    scanf ("%f", &newRecords[numOfRecords].partSize);

    printf ("Enter Part Size Metric (ex: lbs, kg, inches): ");
    scanf ("%s", newRecords[numOfRecords].partSizeMetric);

    printf ("Enter Part Cost: ");
    scanf ("%f", &newRecords[numOfRecords].partCost);

    free(records);      // free old memory and assign to new memory
    records = newRecords;
    numOfRecords++;
    printNumOfChanges(false);
    printf("Record added successfully\n");
}

void deleteRecord() {
    if (numOfRecords == 0) {
        printf ("No records to delete\n");
        return;
    }

    partRecord *newRecords = (partRecord *) malloc ((numOfRecords - 1) * sizeof(partRecord));   // allocates new memory with one less record
    if (numOfRecords > 1 && !newRecords) {
        printf ("Memory allocation failed after deletion\n");
        exit(1);
    }

    for (int i = 0; i < numOfRecords - 1; i++) {    // copy all but last record to new memory
        newRecords[i] = records[i];
    }

    free(records);  // free old memory and assign to new memory
    records = newRecords;
    numOfRecords--;
    printNumOfChanges(false);
    printf ("Last record deleted successfully\n");
}

void printNumOfRecords() {
    printf ("Total number of records: %d\n", numOfRecords);
}

void dataBaseSize() {
    printf ("Total memory allocated: %lu bytes\n", numOfRecords * sizeof(partRecord));
}

int main() {
    int selection;

    // displays menu
    while (true) {    
        printf ("\n Parts Management System\n");
        printf ("1. Print all records\n");
        printf ("2. Add record\n");
        printf ("3. Delete the last record\n");
        printf ("4. Print number of records\n");
        printf ("5. Print database size\n");
        printf ("6. Print number of changes\n");
        printf ("7. Exit\n");
        printf ("Please enter your selection (1-7): \n");
        scanf ("%d", &selection);

        switch (selection) {
            case 1: 
                printAllRecords();
                break;

            case 2:
                addRecord();
                break;

            case 3: 
                deleteRecord();
                break;

            case 4:
                printNumOfRecords();
                break;

            case 5:
                dataBaseSize();
                break;

            case 6:
                printNumOfChanges(true);
                break;

            case 7:
                printf ("\n Thank you for using the Parts Management System! \n");
                free(records);  // free memory before exiting
                return 0;

            default:
                printf ("Re-enter a number 1-7 \n");
                break;
        }
    }
}