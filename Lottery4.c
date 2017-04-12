/*
============================================================
=   Catherine Etter
=   C Program for Programming II | Spring 2017
=   This program will:
=    Generate a 7 number list and compare to a 7 number list 
=    entered by the user.
============================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int checkRepeat(int array[],int place,int num);
void bubbleSort(int array[],int size);
void printArray(int array[],int size);
void compAndPrint(int userNum[],int ranNum[],int size);
    
void main(void)
{
    int userNum[7]; //User's numbers
    int ranNum[7]; //Generated numbers
    char inputS[10]; //String input of user
    int input; //Numerical input of user
    int i,count; //Counter for for loop and while loop
    
    printf("This program generates a 7 int array and compares it\nto a user-entered 7 int array to find duplicates.\n\n");
    srand(time(NULL)); //Sets time as random seed
    
    for(i=0;i<7;i++){ //Fills array with 7 unique numbers
        do{
            input=rand()%50+1;
        }while(checkRepeat(ranNum,i,input));
        ranNum[i]=input;
    }
    for(i=0;i<7;i++){ //Gets user's numbers as a string and converts to int in case of non-int input
        count=0;
        do{
            count!=0?printf("ERROR: Out of bounds or repeated number.\n"):count++;
            printf("Enter a number 1-50 for place %d: ",i+1);
            fgets(inputS,10,stdin);
            input=atoi(inputS);
        }while(checkRepeat(userNum,i,input)||input>50||input<1); //while duplicate number or out of bounds
        printf(" You entered: %d\n",input);
        userNum[i]=input;
    }
    
    printf("\nUser Array:\n  Unsorted: ");
    printArray(userNum,7);
    bubbleSort(userNum,7);
    printf("\n  Sorted:   ");
    printArray(userNum,7);
    
    printf("\nComputer Array:\n  Unsorted: ");
    printArray(ranNum,7);
    bubbleSort(ranNum,7);
    printf("\n  Sorted:   ");
    printArray(ranNum,7);
    
    printf("\n");
    compAndPrint(userNum,ranNum,7);
}



int checkRepeat(int array[],int place,int num) //Checks if repeating number from beginning to current place.
{
    int i; 
    int repeat=0; // 0 for no repeat, 1 for repeat
    
    for(i=0;i<place;i++){
        if(array[i]==num){ //returns 1 as soon as a repeated number is found
            return 1;
        }
    }
    return 0;
}



void bubbleSort(int array[],int size) //Orders the array numerically
{
    int notSorted=1,temp, pass=1, i=1;
    
    while(notSorted){
        notSorted=0;
        for(i=0;i<size-1;i++){ //check every two elements in array
            if (array[i]>array[i+1]){ //switch if previous element bigger than second
                temp=array[i];
                array[i]=array[i+1];
                array[i+1]=temp;
                notSorted=1;
            }
        }
    }
}



void printArray(int array[],int size) //prints array to stdout
{    
    int i;
    
    for(i=0;i<size;i++){ //for every element in array
        printf(" %d ",array[i]);
    }
}



void compAndPrint(int userNum[],int ranNum[],int size) //finds duplicates in two arrays
{
    int ran,user,matches=0;
    
    for(ran=0;ran<size;ran++){ //for every element in ranNum[]
        for(user=0;user<size;user++){ //for every element in userNum[]
            if(ranNum[ran]==userNum[user]){ //increment matches if duplicate found
                printf(" %d is the same!\n",userNum[user]);
                matches++;
            }
        }
    }
    matches==1? printf("\nFound %d match",matches) : printf("\nFound %d matches.",matches); //use correct grammar
}
