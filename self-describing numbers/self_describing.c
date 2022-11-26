#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check(int,int);
int getNumDigits(int);
int main()
{
    int num,temp=0, digit=0,count=0;
    int test_cases;
    FILE *self_in;
    self_in = fopen("self.txt", "r");

    if (self_in == NULL) 
    {
        printf("Error! File cannot be opened Check if file path is correct or if file exists.");
        exit(1);
    }


    fscanf (self_in, "%i", &test_cases);
    int testcase_count = 0;

    while (testcase_count < test_cases) 
    {
        fscanf (self_in, "%i", &num);
        temp=num;
        int flag = 1;
        int numDigit = getNumDigits(temp);
        while(temp>0)
        {
            digit=temp%10;
            int count=check(num,numDigit);
            if(count!= digit)
            {
                printf("\nNot self-describing");
                flag = 0;
                break;
            }
            temp=temp/10;
            numDigit--;
        }
        if(flag)
        {
            printf("\nSelf-describing");   
        }

        testcase_count++;
    }
    
    
}

//check number of times the digit appear in number 
int check(int num,int digit)
{
    //printf("\n%i", num);
    int count=0;
    while(num>0)
    {
        if(num%10 == digit)
        {
            count++;
        }
        num=num/10;
    }
    return count;
}

//to check number of digits in number 
    int getNumDigits(int num)
    {
    int digits = 0;
    while(num>0)
    {
        digits++;
        num=num/10;   
    }
    return digits-1;
}
















