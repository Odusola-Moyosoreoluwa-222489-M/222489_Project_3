#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int getLength(long test);

int counter(long n, long d);

void printResult(long test, long result);


void main(){
    int noOTests;
    FILE *fp;
    fp = fopen("self.in", "r"); // Open the file
    if (fp == NULL)
    {
        printf("File doesn't exist");
        exit(0);
    }

    fscanf(fp, "%d", &noOTests); // Read from file
    for (int i = 0; i < noOTests; i++)
    {
        long testvalue, result = 0;
        fscanf(fp, "%lli", &testvalue);
        int lengthOfTestCase = getLength(testvalue);
        // Get the actual value of what the self-describing number is to look like
        for (int i = 0; i < lengthOfTestCase; i++)
        {
            int exp = lengthOfTestCase - i - 1;
            long newData = counter(testvalue, i) * pow(10, exp);
            result = result + newData;
            
        }
        // Compare the true value and the testcase
        printResult(testvalue, result);
        
    }
    fclose(fp); // Close the file
}

int getLength(long test){
    // Gets the length of the test case by continually dividing by 10, n times
    int testcaseLength = 0;
    do {
        test /= 10;
        ++testcaseLength;
    } while (test != 0);
    return testcaseLength;
}


int counter(long n, long d){
    if(n <= 0)
    return 0;
    
    long rem = n % 10;
    
    if(rem == d){
        return 1 + counter(n/10, d);
    }
    
    return counter(n/10, d);
}

void printResult(long test, long result)
{
    // Checks if it is a self-describing number
    if (test == result)
        {
            printf("self-describing\n");
        }        
        else {
            printf("not self-describing\n");
        }
}