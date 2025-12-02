/******************************************************************************

Program: Regester Level Toolkit
Coder: Adam Kuefler
Date: 01/12/2025(dd/mm/yyyy)
Purpose: fast easy access to various tools for working with binary, hex, and BDCHex

*******************************************************************************/

#include <stdio.h>
#include <ctype.h>


int read_bits();
void PrintBinary(char cByteChar);

int main(){

    //Variable Declaration
    unsigned int i8Bit = 0;
    
    // int i = 0;

    int inputMode;
    int outputMode;


    //Forever Loop

    // Clear Terminal!
    printf("\e[1;1H\e[2J");

    printf("Welcome to the Super 8Bit Tool\n");
    printf("a utility made out of sheer lazyness\n\n");

    while(1) {

        printf("How Would You Like to Input Values?\n\n1) Decimal\n2) Hex(UnderDev)\n3) Binary\n\nEnter Selection: ");
        scanf("%d", &inputMode);

        switch (inputMode) {
            case 1:
                printf("Enter Decimal Value(0-255) :");
                scanf("%d", &i8Bit);
                break;
            case 2:
                printf("Enter a pair of Hex digits: 0x");                                 //Prompts For Hex Value Input
                scanf("%2hhx", &i8Bit);                                                      //Read/Store Two Hex Digits   

                break;
            case 3:
                printf("                                      76543210\n");
                printf("Enter 8 Bit Binary & press \"ENTER\": 0b");      //Prompt For input
                i8Bit = read_bits();                                 //Run Word #1 Through Read Function
        }
        
        printf("How Would You Like to Output Values?\n\n1) Decimal\n2) Hex\n3) Binary\n\nEnter Selection: ");
        scanf("%d", &outputMode);

        printf("\n");

        switch (outputMode) {
            case 1:
                printf("Value In Decimal = %d\n\n", i8Bit);
                break;
            case 2:
                if (i8Bit > 0xf) printf("Value In Hex = 0x%x\n\n", i8Bit);
                else printf("Value In Hex = 0x0%x\n\n", i8Bit);
                break;
            case 3:
                printf("Value In Binary ");      //Prompt For input
                PrintBinary(i8Bit);
                printf("\n\n");
                
        }

        printf("Press Enter To Continue: ");
        getchar();

        while ((getchar()) != '\n');        // Clear Input Buffer
        
        // Clear Terminal!
        printf("\e[1;1H\e[2J");     //Posibly Linux Only?
    }
    return 0;
}

/**********************************************************************
 * Function: int read_bits()
 * Coder: Adam Kuefler
 * Date: 01/12/2025
 * Purpose: 
 * ********************************************************************/
int read_bits() {
    
    //Variable Declaration
    int inChar;                 //Buffer Input Variable
    int output = 0;
    int i;

    //Intake Loop
    for(i = 9; i--; i < 1)
    {
        inChar = getchar();
        inChar = inChar - 48;

        if(inChar == 1){
            output |= (1 << i);
        }
        else output &= ~(1 << i);
    }

    while ((getchar()) != '\n');        // Clear Input Buffer
    return output;
    }

/********************************************************************************
 * Function: PrintBinary(char cByteChar)
 * Coder: Cory Thorp
 * Date: No thanks, I'm full
 * *****************************************************************************/
 void PrintBinary(char cByteChar)
{
    char cSteps = 0;
    
    //Output in binary format
    printf("0b");
    for(int iIndex = 7; iIndex >= 0; iIndex--)      //Start at MSB
    {
        cSteps = cByteChar >> iIndex;               //shift bytes to right by current value in index
        if(cSteps & 0x01)printf("1");               //if cstep bitwise and with 0b00000001 is true, print 1
        else printf("0");                           //otherwise print a 0
    }
    printf("\n");
    
}

