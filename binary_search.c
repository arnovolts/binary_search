#include <stdio.h>
#include <stdlib.h>

int binary_search(int arr[], int start, int end, int n);

// Maximum size of the array
#define MAX 500

int main(int argc, char* argv[])
{
    // Incorrect number of arguments 
    if (argc != 3)
    {
        printf("usage ./binary_search <filepath> <number>\n");
        return 1;
    }

    FILE *inpt = fopen(argv[1],"r");

    if (inpt == NULL)
    {
        printf("Could not open file.\n");
        return 2;
    }

    // Convert string to integer
    int n = atoi(argv[2]);

    int numbers[MAX];
    int buffer = 0;
    int counter = 0;

    // Load integers from the file in memory
    int i = fscanf(inpt, "%d", &buffer);
    while (i != EOF )
    {
        // Add the number in the array
        numbers[counter] = buffer;

        // Move to the next line
        i = fscanf(inpt, "%d", &buffer);
        counter++;

    }
   
    // Look if the number is in the array
    int index = binary_search(numbers, 0, counter - 1, n);
    if (index >= 0)
    {
        printf("Found at index %i\n", index);
    }
    else
    {
        printf("%i not present in %s\n", n, argv[1]);
    }
    
    fclose(inpt);
    return 0;
}

int binary_search(int arr[], int start, int end, int n)
{

    // Gets the middle point between two bounds
    int middle = (start + end) / 2;

    // Found
    if (arr[middle] == n)
    {
        return middle;
    }
        
    // Not found
    if (start == middle)
    {
       return -1;
    }


    // Look on the right half of the array
    if (n < arr[middle])
    { 
        return binary_search(arr, start, middle, n);
    }
    

    // Look on the left half of the array 
    return binary_search(arr, middle + 1, end, n);
    
}