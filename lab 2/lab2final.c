#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pick {
    char CustomerID[30];
    char CustomerName[30];
    char StoreID[30];
    char StreetAddress[30];
    char ZipCode[30];
};

struct pick* picks;
int count = 0;
int picksizes;
static int enterin;

void printrecords() { // prints all record 
    int i;
    struct pick *temp = picks;
    for (i=0; i<count; i++) {
        printf("\nCustomer ID: %s\n", temp->CustomerID);
        printf("Customer Name: %s\n", temp->CustomerName);
        printf("Store ID: %s\n", temp->StoreID);
        printf("Street Address: %s\n", temp->StreetAddress);
        printf("Zip Code: %s\n", temp->ZipCode);
        temp++;
    }
}

void printnumberofrecs() { // prints the number of records 
    printf("\nThe number of records: %d\n", count);
}

void printsizesofdata() { // prints the size of the database 
    printf("The size of the database is: %d\n", picksizes);
}

/*A new record is added to a data structure using this function. 
 *The user is prompted to enter the necessary data for the record 
 *before it is added to the data structure.
 */
void addrec() {
    struct pick *diff_picks = malloc(sizeof(struct pick));
    count += 1;
    enterin += 1;
    if (diff_picks == NULL) {
        printf("This didn't work.\n");
        return;
    }
    //tells the user to enter record information
    printf("Enter CustomerID: ");
    scanf("%s", diff_picks->CustomerID);

    printf("Enter Customer Name: ");
    scanf("%s", diff_picks->CustomerName);

    printf("Enter StoreID: ");
    scanf("%s", diff_picks->StoreID);

    printf("Enter Street Address: ");
    scanf("%s", diff_picks->StreetAddress);

    printf("Enter Zip Code: ");
    scanf("%s", diff_picks->ZipCode);
    getchar();
    picks = diff_picks;
    picksizes += sizeof(struct pick); // increments the total size of the data struct 
}

/* If there are any records to remove, 
 *this function deletes the last record from the data structure. 
 *The data structure's size and count are updated appropriately.
 */
void deletrec() { 
    if (count > 0) { //checks if theres records to delete 
        
    count--;
        picksizes -= sizeof(struct pick);
        enterin++; //increment count of entered records 
        struct pick *new_picks = malloc(count * sizeof(struct pick));
        if (new_picks == NULL) {
            printf("Memory allocation error\n");
            exit(1);
        }
        memcpy(new_picks, picks, count * sizeof(struct pick));
        free(picks);
        picks = new_picks;

    } else { // this is if there are no records to delete
        printf("No records to delete.\n");
    }
}


void printnumacess(){ //prints the number of acesses to databse 
    printf("Here are the number of accesses: %d\n", enterin);
}

int main() {
    int choice;
    while(1) {
        printf("\n---------------------\n");
        printf("MENU\n");
        printf("---------------------\n");
        printf("1. Print all records\n");
        printf("2. Print number of records\n");
        printf("3. Print size of database\n");
        printf("4. Add record\n");
        printf("5. Delete record\n");
        printf("6. Print number of accesses to database\n");
        printf("7. Exit\n");
        printf("Pick a choice: ");
        char input[100];
        fgets(input, 100, stdin);
        choice = atoi(input);

        switch (choice) {
            case 1:
                printrecords();
                break;
            case 2:
                printnumberofrecs();
                break;
            case 3:
                printsizesofdata();
                break;
            case 4:
                addrec();
                break;
            case 5:
                deletrec();
                break;
            case 6:
                printnumacess();
                break;
            case 7:
                printf("bye\n");
                exit(1);
                break;
            default:
                printf("You pick the wrong thing try it over.\n");
                 }
    }
}
