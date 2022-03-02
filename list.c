#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int element;
  struct node* next;
}node;

node* head = NULL;
int count = 0;

node* find_node(int num)
{
  if(head == NULL)
    return NULL;

  node* current = head;
  while((current != NULL) && (current -> element <= num))
  {
    if(current -> element == num)
      return current;
    current = current -> next;
  }

  return NULL;
}

void delete_list(int num)
{
  node* current = head;
  if(head -> element == num)
  {
    head = head -> next;
    free(current);
    count--;
    return;
  }
  
  node* prev = NULL;
  while((current != NULL) && (current -> element != num))
  {
    prev = current;
    current = current -> next;
  }

  prev -> next = current -> next;
  free(current);
  --count;
}

void insert_list(int num)
{
  // Create a new node using malloc 
  node* new_node = (node*)(malloc(sizeof(node)));
  new_node -> element = num;
  new_node -> next = NULL;
  
  if(head == NULL)
    head = new_node;
  else if(head -> element > num)
  {
    new_node -> next = head;
    head = new_node;
  }
  else
  {
    node* current = head;
    while(current -> next != NULL && current -> next -> element < new_node -> element)
    {
      current = current -> next;
    }

    new_node -> next = current -> next;
    current -> next = new_node;
  }

  ++count;
}

void print_list()
{
  printf("%d :", count);
  node* current = head;
  while(current != NULL)
  {
    printf(" %d", current -> element);
    current = current -> next;    
  }
  printf("\n");
}

int main()
{
  char c;
  int num;
  
  while(scanf("%c %d", &c, &num)!= EOF)
  {
    if(c == 'i')
    {
      if(find_node(num) == NULL)
        insert_list(num);
      
      print_list();
    }
    else if(c == 'd')
    {
      if(find_node(num) != NULL)
        delete_list(num);
      print_list();
    }
    else 
      printf("ERROR: Enter i or d\n");
    
    scanf("%c", &c);
  }
  return 0;
}