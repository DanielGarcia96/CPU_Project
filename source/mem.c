/*
* programmer : Lap and Faisal
*
* Desciption : 
* Main
* -stdin address in "hex", for example : "fcd1"
* -call writeMemory and readMemory functions
* -print out data
*
* writeMemory function
* -reads hex address
* -first hex number for chip select 
* -second, third and forth hex numbers converts into decimal 
* number which for memory location to store data
* -write data into memory
*
* readMemory function
* -read data from memory uses same stdin address from main
* -coverts fist hex for chip select
* -2,3,4 digits are address for memory location
* -read data from memory, returns data to main 
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include "mem.h"


/*int main()
{
    char address[10];
    char inputAddr[10];
    char inputData []= "abcdefghi444444444444444444444";
    int i = 0;

    char* returnData;


    fgets(inputAddr, 10, stdin);
    inputAddr[strlen(inputAddr) -1] = '\0';

    printf("\nWrite into memory\nAddress\n");
    while (inputAddr[i] != '\0')
    {
        address[i] = inputAddr[i];
        printf("%c",address[i]);
        i++;

    }

    printf("\n");
    //mem(chars, data);
    writeMemory(address, inputData);
    returnData = readMemory(address);

    printf("Output data %s\n", returnData);
    return 0;
}*/


void writeMemory(char addr_16bits[], char inputData[])
{
//   char memoryArray[16][4096] = {};

    int chipSel = 0;
    int number = 0;
    int k = 0;

     // *** convert hex to decimal for chip select ***
    if( addr_16bits[0]>='A' && addr_16bits[0]<='F' )
        chipSel = addr_16bits[0]-(int)('A')+10;
    if( addr_16bits[0]>='a' && addr_16bits[0]<='f' )
        chipSel = addr_16bits[0]-(int)('a')+10;
    if( addr_16bits[0]>='0' && addr_16bits[0]<='9' )
        chipSel = addr_16bits[0]-(int)('0');

    printf("Chip select %d\n", chipSel);

    // *** convert hexadecimal string to number ***
    for(int j = 1; j < sizeof(addr_16bits); j++)
    {
        number *= 16;
        //const char c = *addr_16bits;
        if( addr_16bits[j] >='A' && addr_16bits[j]<='F' )
            number += addr_16bits[j]-(int)('A')+10;
        if( addr_16bits[j]>='a' && addr_16bits[j]<='f' )
            number += addr_16bits[j]-(int)('a')+10;
        if( addr_16bits[j]>='0' && addr_16bits[j]<='9' )
            number += addr_16bits[j]-(int)('0');
    }

    printf("Momory location %d\n", number);  
    printf("Data size %lu\n", strlen(inputData)); 
    printf("Write data \n");
    
    //Write data into memory
    for(int n = 0; n < strlen(inputData); n++)
    {
        memoryArray[chipSel][number + n] = inputData[n];
        printf("%c", inputData[n]);
    }
    printf("\n");
}

char* readMemory(char addr_16bits[])
{
//   char memoryArray[16][4096] = {};

    int chipSel = 0;
    int number = 0;
    int k = 0;

    char readData[4096];

     // *** convert hex to decimal for chip select ***
    if( addr_16bits[0]>='A' && addr_16bits[0]<='F' )
        chipSel = addr_16bits[0]-(int)('A')+10;
    if( addr_16bits[0]>='a' && addr_16bits[0]<='f' )
        chipSel = addr_16bits[0]-(int)('a')+10;
    if( addr_16bits[0]>='0' && addr_16bits[0]<='9' )
        chipSel = addr_16bits[0]-(int)('0');

    printf("\nRead data from memory \nChip select %d\n", chipSel);

    // *** convert hexadecimal string to number ***
    for(int j = 1; j < sizeof(addr_16bits); j++)
    {
        number *= 16;
        //const char c = *addr_16bits;
        if( addr_16bits[j] >='A' && addr_16bits[j]<='F' )
            number += addr_16bits[j]-(int)('A')+10;
        if( addr_16bits[j]>='a' && addr_16bits[j]<='f' )
            number += addr_16bits[j]-(int)('a')+10;
        if( addr_16bits[j]>='0' && addr_16bits[j]<='9' )
            number += addr_16bits[j]-(int)('0');
    }

    printf("From address location %d\n", number);  
    //printf("size %d\n", strlen(data)); 

    //Caluate data size
    for (k  = 0 ; memoryArray[chipSel][number + k] != '\0'; k++);
    printf("Data zize %d\n", k);
    printf("Data read ");
     
     //Read data from memory 
    for(int m = 0; m < k; m++)
    {
        Data[m] = memoryArray[chipSel][number + m];
//      printf("%c", memoryArray[chipSel][number+m]);
        printf("%c", Data[m] );
    }

    printf("\n");
    
    //Return data
    return Data;
}
