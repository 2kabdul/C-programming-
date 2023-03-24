Readme Document


Created by: Hamza Mohamed and Abdullahi Farah


Program Description:
This program utilizes various structures, pointers and dynamic memory allocation. It also enables users to manage records by providing functions.


Data Definitions:
struct: Stores Variables
static int: Used to modify scope of a variable or function


Menu Definitions:
1.printrecords
-Allows for records to be printed while being stored in the database
-Includes variables such as CustomerID,CustomerName,StoreID,StreetAddress, ZipCode
2.printsumberofrecs
-Allows for records to be printed while being stored in the database
3.printsizesofdata
-Allows the size of the database to be identified
-Uses bytes to calculate the size of database
4.addrec
-Allows user to create and add new records to the structure
-Variables include: CustomerID,CustomerName,StoreID,StreetAddress,ZipCode
5.deleterec
-Deletes/removes records chosen
-This function is used to free some memory
6.printnumacess
-Function is used to print the number of accesses
-Function identifies when something has changed in database
7.exit
-Function ends the program


Functions used:
Void printrecords()
        Prints records prompted
Void printnumberofrecs()
        Prints the number of records prompted
Void printsizeofdata()
        Prints the size of data prompted


Void addrec()
        Adds new records prompted
Void deleterec()
     Deletes record that was previously added


Void printnumacess()
        Prints the number of accesses prompted