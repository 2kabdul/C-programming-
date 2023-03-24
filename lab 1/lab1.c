#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int debug = 0; 
int add(){ 
    int num1;
    int num2;
    int sum;
    printf("First Number: ");
    scanf("%d", &num1); 
    printf("Second Number: ");
    scanf(" %d", &num2);
    sum = num1 + num2;
    printf("Numbers were %d and %d.\n the sum of the two are: %d\n", num1, num2,sum);
    if (debug){ 
        fprintf(stderr,"(debugging): you have %d and %d\n", num1, num2);
    
    }
    return 0;
    
}
float multiply(){
    float num1;
    float num2;
    float product;
    printf("First Number: ");
    scanf(" %f", &num1); 
    printf("Second Number: ");
    scanf(" %f", &num2);
    product = num1 * num2;
    printf("Numbers were %f and %f.\nYour product was: %0.3f\n", num1, num2, product);
    if (debug){ 
        fprintf(stderr,"(debugging): you have %f and %f\n", num1, num2);
    
    }
    return 0;
 
}
int reverse(){
    char str[100];
    char reverse[100];
    int i = 0;
    printf(" Enter a string (no whitespace characters): ");
    scanf(" %s", str);
    int len = strlen(str);
    for (int i = len -1; i >= 0; i --){
        printf("%c", str[i]);
    }
    printf("\n");
    if(debug){
        fprintf(stderr,"(debugging): you have %s. reverse is %s\n", str, reverse);
    }
    return 0;
}
int similar(){
    char str1[50], str2[50];
    int i;
    printf("Enter your fist string: ");
    scanf("%s",str1);
    printf("Enter your second string: ");
    scanf("%s",str2);
    i=strcmp(str1,str2);  
    if(i==0){
        printf("The strings are equal");
    }
    if(i<0){
        printf("The strings are not equal");
    }
    if(debug){
        fprintf(stderr,"debugged, It works.\n");
        }
    return 0;
}
int main (int argc, char*argv[]){

    if (argc < 2){
        printf("Usage: lab1 [debug | no-debug]");
        exit(1);
    }
    if(strcmp(argv[1], "debug") == 0){
        debug = 1;
    }
    if(debug){
        fprintf(stderr, "It is debugging");
    }
    int selection; 
    while(selection !=5){
    printf("Menu: \n");
    printf("1) Add 2 numbers (integers)\n");
    printf("2) Multiply 2 numbers (floats)\n");
    printf("3) Read in string and reverse the string as output \n");
    printf("4) Enter 2 words and see if there similar\n");
    printf("(5) Exit\n");

    printf("Choose an option: ");
    scanf("%d", &selection);  
        switch(selection){
            case 1: 
                printf("You picked 1\n");
                add();
                break;
            case 2:
                printf("You picked 2\n");
                multiply();
                break;
            case 3:
                printf("You picked 3\n");
                reverse();
                break;
            case 4:
                printf("You picked 4\n");
                similar();
                break;
            case 5:
                printf("\nYou have exited the menu.");
                break;
            default:
                printf("Choose a number 1,2,3,4,5\n");
                break;
        }
    }
        return 0;
}



