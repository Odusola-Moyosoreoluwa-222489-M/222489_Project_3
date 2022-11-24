#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct File
{
    char name[10];
    int id;
} file;

void sortByAscending(file arr[], int size);

int deleteDuplicateFiles(file arr[], int size);

void main(){
    int noOfTestCases;
    FILE *fp;
    fp = fopen("files.in", "r"); // Open the file
    if (fp == NULL)
    {
        printf("File doesn't exist");
        exit(0);
    }
    
    fscanf(fp, "%d", &noOfTestCases); // Read from file
    for (int i = 0; i < noOfTestCases; i++)
    {
        int noOfFiles;
        file allFiles[100];
        fscanf(fp, "%d", &noOfFiles);
        // Store the files in structures
        for (int i = 0; i < noOfFiles; i++)
        {
            char tempName[20];
            int tempId;
            fscanf(fp, "%s", &tempName);
            fscanf(fp, "%d", &tempId);
            strcpy(allFiles[i].name, tempName);
            allFiles[i].id = tempId;
        }
        sortByAscending(allFiles, noOfFiles);
        noOfFiles = deleteDuplicateFiles(allFiles, noOfFiles);
        for (int i = 0; i < noOfFiles; i++)
        {
            printf("%d ", allFiles[i].id);
        }        
        printf("\n");
    }
    fclose(fp); // Close the file
}

void sortByAscending(file arr[], int size)
{
    file tempFile;
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j].id > arr[j+1].id)
            {
                tempFile = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tempFile;
            }
            
        }
    }
}

int deleteDuplicateFiles(file arr[], int size)
{
    for (int i = 0; i < size; i++)
        {
        for (int j = i + 1; j < size; j++)
        {
            // Compare each struct for duplicate names
            if (strcmp(arr[i].name, arr[j].name) == 0)
            {
                for (int k = j; k < size; k++)
                {
                    // Shift the elements to the right using the index
                    arr[k] = arr[k+1];
                }
                size--;
                j--;
            }
            
        }
        
    }
    // Returns the new size of the array
    return size;
    
}
