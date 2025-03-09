Christina Tu

This program is a user menu that allows the user to select items in which they interact with and providing outputs.
The user selects 1-7

1 - printing all records

2 - adding new records

3 - deleting the last record

4 - printing the number of records

5 - printing the size of the database

6 - printing the number of modifications

7 - exit

void printAllRecords()
- doesn't have a return value and returns the menu
- no output type
- it prints out the record menu

int PrintNumOfChanges()
- has an int type
- int output because the print variable is a bool and bool uses 1 and 0
- it increments any modifications made and prints out the number of modifications

void addRecord()
- doesn't have a return type
- no output type
- adds the user's input into the database and incrementing the modifications

void deleteRecord()
- no return type
- no output type
- deletes the most recent record by allocating the existing record into a new memory with one less record

void numOfRecords()
- no return type
- no output type
- prints the total number of records that have been added or deleted

void dataBaseSize()
- no return type
- no output type
- prints the total memory that has been allocated in bytes by printing the number of records and size of struct (partRecord)

No extra files used
