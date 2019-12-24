/**
 * Author: Jorge Sirias
 * COP 4338 - Programming 3
 * Professor: Caryl Rahn
 * 1/31/19
 *
 * Purpose: The purpose of this program is to write a calculator program that takes input from the command line alongside flags for options.
 *
 * I affirm that I wrote this program myself without any help form any other people or sources from the internet.
 * 
 * **/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv)
{

    extern char *optarg; //Holds value after colon(:) when processing the argv array.
    extern int optind;  
     
    int c; //Holds value that is returned by the getopt function which represents an ASCII value
    int aflag=0, mflag=0, xflag=0;//Flags that are used in the command line to indicate what type of operation to carry out
                                   //a flag denotes addition, m flag denotes multiplication and x flag denotes power of 2

    int value; // Variable that holds the starting numerical value for which will be used for computation

    int aNum = -1, mNum = -1;

    static char usage[]= "usage: ./minicalc [-a num] [-m num] [-x] value";

    //printf("There are %d inputs on the command line\n", argc); //DELETE

    if( argc < 2 ) //If argCount is missing value then exit program
    {

      printf("Try running the program with some arguments\n\n\t%s \n\n\tSomething like:\n\n\t./minicalc -a 5 30 \n\t./minicalc -m 2 4 \n\t./minicalc -x 30\n\t./minicalc -a 5 -m 10 -x 20\n", usage); 

    }

    //printf("About to enter while getopt loop"); //DELETE

    while((c = getopt(argc, argv, "a:m:x")) != -1)  // While there are still arguments passed from command line, continue loop
    {

      //printf("\n%c\n", c); //DELETE      
      //printf("Entering Loop\n"); //DELETE
      switch(c)
      {
       
        case 'a':
          aflag = 1;
          aNum  = atoi(optarg);     
          break;
       
        case 'm':
          mflag = 1;
          mNum  = atoi(optarg);
          break;

        case 'x':
          xflag=1;
          break;


      }
     // printf("Exited while loop"); //DELETE   
    }  
    //printf("\naNum = %d", aNum); //DELETE
    if(aNum != -1)      
    {
        if(!((aNum >= 1) && (aNum<=500)))
        {

          printf("\nPlease pick a number between 1 and 500 inclusive\n");
          exit(1);

        }
    }
    //printf("\nmNum = %d\n", mNum); //DELETE
    if(mNum != -1)
    {  
        if(!((mNum >= 1) && (mNum<=10)))
        {

          printf("\nPlease pick a number between 1 and 10 inclusive\n");
          exit(1);

        }
    }

    //printf("\noptind: %d", optind); //DELETE

    value = atoi(argv[optind]); //Gets initial value after all options have been parsed by getopt

    //printf("\nvalue: %d", value);  //DELETE

    /**
    *Here if all options are true then perform arithmetic operations based on natural arithmetic law
    * */
    if( (xflag == 1) && (aflag == 1) && (mflag == 1) )
    {

        double total = 0; //Local variable that will hold total of arithmetic operation
        
        total = (double)(value * value); // When X option is selected square initial value    
        total = (double)(total * mNum);  // Multiply squared total to mNum
        total = (double)(total + aNum);  // Add total to aNum;

        printf("\nThe result of your input is: %.2lf\n", total);

        exit(0);

    }

    /**
    *Here if x flag is omitted but all other options are chosen then proceed based on arithmetic rules 
    * */
    if( (aflag == 1) && (mflag == 1) )
    {

        double total = 0; //Local variable that will hold total of arithmetic operation

        total = (double)(value * mNum);
        total = (double)(total + aNum); 

        printf("\nThe result of your input is: %.2lf\n", total);        

        exit(0);

    }

    /**
    *Here in this instance x flag is paired with just one option and processed accordingly
    * */
    if(xflag==1)
    {

        double total = 0;//Local variable that will hold the total of arithmetic operation

        if(aflag==1)
        {

          total = (double)(value*value);
          total = (double)(total+aNum);

          printf("\nThe result of your input is: %.2lf\n", total); 

        }
        else if(mflag==1)
        {

          total = (double)(value*value);
          total = (double)(total*mNum);
         
          printf("\nThe result of your input is: %.2lf\n", total);

        }
        else
        {

          total = (double)(value*value);
          printf("\nThe result of your input is: %.2lf\n", total);

        }

        exit(0);

    }

    /**
    *Here in this instance only one option is chosen tha is not -x flag and is processed accordingly
    * */
    if(aflag == 1)
    {

        double total = 0; //Local variable that will hold the total of arithmetic operation

        total = (double)(value+aNum);

        printf("\nThe result of your input is: %.2lf\n", total);

        exit(0);

    }
    else if(mflag == 1)
    {

        double total = 0; //Local variable that will hold the total of arithmetic operation

        total = (double)(value*mNum);

        printf("\nThe result of your input is: %.2lf\n", total);

        exit(0);

    }
    else if(argc == 2) //In this case the user has only put in a initial value and no options
    {

        printf("\nYou have not chosen to perform any operations on the given value.\nPlease follow this format:\n\t%s\n", usage);

    }

    exit(0);    

}

