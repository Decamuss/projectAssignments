#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool readPuzzle(FILE *file, char puzzle[9][9]);
bool containsDuplicate(char arr[9]);
bool checkRows(char puzzle[9][9]);
bool checkCols(char puzzle[9][9]);
bool checkBlocks(char puzzle[9][9]);

int main(int argc, char *argv[])
{

    if (argc == 2)
    {
        FILE *fp = fopen(argv[1], "r");
        if (fp == NULL)
        {
            printf("file not found.\n");
        }
        else
        {
            char grid[9][9];
            bool hasGaps = readPuzzle(fp, grid);

            if (checkRows(grid) && checkCols(grid) && checkBlocks(grid))
            {
                printf("%s\n", hasGaps ? "solvable" : "correct");
                
            }
            else
            {
                printf("%s\n", hasGaps ? "unsolvable" : "incorrect");
            
            }
        }
    }

    else
    {
        printf("One argument expected.\n");
    }
}

// Reads file and returns 2d array representingsodoku grid
bool readPuzzle(FILE *file, char puzzle[9][9])
{
    bool hasGaps = false;
    bool proccesGap = false;
    int gapLocation = 0;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            // Char to read from file
            char c;

            do
            {
                // read next char
                c = (char)fgetc(file);
            }
            // skip if char is newline
            while (c == '\n');

            if (c == ' '){
                hasGaps = true;
                proccesGap = true;
                gapLocation = j;
            }
            // srtore char in grid
            puzzle[i][j] = c;
        }
        if (proccesGap){
            // array used to determine which num is missing
            int nums[9] = {0};
            for (int u = 0; u < 9; u++){
                // skip blank
                if (u == gapLocation){
                    continue;
                }
                int index = (puzzle[i][u]) - '0' -1;
                nums[index] = 1;
                
            }

            // fill in missing number
            for (int u = 0; u < 9; u++){
                if (nums[u] == 0)
                    puzzle[i][gapLocation] = u + '0'+ 1;
            }

            proccesGap = false;
        }
    }
    return hasGaps;
}

// given array of 9 numbers determine if any duplicates
bool containsDuplicate(char arr[9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (i != j && arr[i] != ' ')
            {
                if (arr[i] == arr[j])
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool checkRows(char puzzle[9][9])
{
    return true;
    for (int i = 0; i < 9; i++)
    {
        // extract ith row
        char *temp = puzzle[i];

        if (containsDuplicate(temp))
        {
            return false;
        }
    }
    // no duplicates were found
    return true;
}

bool checkCols(char puzzle[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        // extract ith row
        char temp[9];
        for (int j = 0; j < 9; j++)
        {
            temp[j] = puzzle[j][i];
            //printf("%c", temp[j]);
            
        }
        
        //printf("\n");

        if (containsDuplicate(temp))
        {
            return false;
        }
    }
    // no duplicates were found
    return true;
}

bool checkBlocks(char puzzle[9][9])
{
    // for (int grid_num = 0; grid_num < 9; grid_num++)
    // {

    char temp[9];
    int s, j = 0;
    for (int k = 0; k < 9; k += 3)
    {
        s = 0;
        for (int i = 0; i < 9; i++)
        {
            for (j = k; j < k + 3; j++)
            {
                temp[s] = puzzle[i][j];
                // printf("%c", temp[s]);
                s++;
            }
            // printf("\n");

            if (s == 9)
            {
                s = 0;
                // printf("Temp = ");
                // for (int h = 0; h < 9; h++)
                // {
                //     printf("%c", temp[h]);
                // }
                // printf("\n");
                if (containsDuplicate(temp))
                {
                    return false;
                }
            }
        }
    }
    // }
    // no duplicates were found
    return true;
}
