#include <stdio.h>
#include <stdlib.h>

void print_matrix(int** arr, int rows)
{
  int i, j;
  for(i = 0; i < rows; i++)
  {
    for(j = 0; j < rows; j++)
    {
      if(j!=rows-1)
      {
        printf("%d ", arr[i][j]);
        
      }
      else{
        printf("%d", arr[i][j]);
        
      }
      
    } 
    printf("\n");
  }
  
}

void multiply(int** arr, int rows, int n, int** copy)
{
  // printf("here mu\n");
  int i, j, k;
  
  if(n == 1)
    return;

  if(n == 0)
  {
    for(i = 0; i < rows; i++)
      for(j = 0; j < rows; j++)
        arr[i][j] = 0;
    return;
  }

  
  
  // Allocate memory dynamically 
  int** new_arr = (int**)(malloc(sizeof(int*) * rows));
  for(i = 0; i < rows; i++)
    new_arr[i] = (int*)(malloc(sizeof(int) * rows));

  for(i = 0; i < rows; i++)
    for(j = 0; j < rows; j++)
      new_arr[i][j] = 0;

  for(i = 0; i < rows; i++)
    for(j = 0; j < rows; j++)
    {
      for(k = 0; k < rows; k++)
      {
        new_arr[i][j] += arr[i][k] * copy[k][j];
        //printf("%d ", new_arr[i][j]);
      }
      //printf("\n");
      //printf("[%d][%d] set to %d\n", i, j, new_arr[i][j]);
    }

  for(i = 0; i < rows; i++)
    for(j = 0; j < rows; j++)
      arr[i][j] = new_arr[i][j];

   // Free new_arr 
  for(i = 0; i < rows; i++)
    free(new_arr[i]);
  free(new_arr);


  multiply(arr, rows, n - 1, copy);
}

int main(int argc, char* argv[])
{
  int rows, i, j, n;

  FILE* fp = fopen(argv[1], "r");
  fscanf(fp, "%d", &rows);
  

  // Allocate memory dynamically 
  int** arr = (int**)(malloc(sizeof(int*) * rows));
  for(i = 0; i < rows; i++)
    arr[i] = (int*)(malloc(sizeof(int) * rows));

  for(i = 0; i < rows; i++)
  {
    for(j = 0; j < rows; j++)
      fscanf(fp, "%d", &arr[i][j]);
  }

  int** copy = (int**)(malloc(sizeof(int*) * rows));
   for(i = 0; i < rows; i++)
    copy[i] = (int*)(malloc(sizeof(int) * rows));

  for(i = 0; i < rows; i++)
  {
    for(j = 0; j < rows; j++)
      copy[i][j]=arr[i][j];
  }


  // print_matrix(arr, rows);
  fscanf(fp, "%d", &n);
  // printf("n = %d\n", n);
  
  // Do the matrix multiplication 
  multiply(arr, rows, n, copy);
  print_matrix(arr, rows);
  
  for(i = 0; i < rows; i++)
    free(arr[i]);

  free(arr);

for(i = 0; i < rows; i++)
    free(copy[i]);

  free(copy);

  fclose(fp);
  return 0;
}