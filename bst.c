#include <stdio.h>
#include <stdlib.h>

struct node
{
    int num;
    struct node *L;
    struct node *R;
};
// use Node instead of struct node
typedef struct node Node;

Node *insert(Node *node, int num);
Node *search(Node *node, int num);
int isFound(int n);
int isFound2(int n);
void print(Node *node);
void del(int num);

Node *headNode = NULL;

int main()
{
    char op;
    int num;
    char a;
    print(headNode);
    do
    {
        scanf("%c", &op);
        if (op == 'p')
        {
            print(headNode);
            printf("\n");
        }
        else
        {
            scanf(" %d", &num);
            if (op == 'i')
            {
                headNode = insert(headNode, num);
            }
            else if (op == 'd')
            {
                del(num);
            }

            else if (op == 's')
            {
                isFound(num);
                
            }
        }

    } while (scanf("%hhd",&a) != EOF);
}

Node *parent(Node *node, int num)
{
    if(node -> num == num)
    {
        return NULL;
    }
    if ((node->L != NULL && node->L->num == num) || (node->R != NULL && node->R->num == num))
    {
        return node;
    }
    if (node->num < num)
    {
        return parent(node->R, num);
    }
    else
    {
        return parent(node->L, num);
    }

}

void del(int num)
{
    /*
    if(headNode != NULL)
    {
        struct node *temp = parent(headNode, num);
        if(isFound2(num) && temp != NULL)
        {
            
            Node *nodeTodelete = search(headNode, num);
            int flag;
            printf("%d", temp -> num);
            
            if (temp -> L != NULL && temp -> L -> num == num)
                {
                    flag = 0;


                }
                else
                {
                    flag = 1;
                }

            if (nodeTodelete->L == NULL && nodeTodelete->R == NULL)
            {
                if(flag ==0)
                {
                    temp -> L = NULL;
                    free(nodeTodelete);
                }
                else
                {
                    temp -> R = NULL;
                    free(nodeTodelete);
                }
                
            }
            else if (nodeTodelete->L == NULL && nodeTodelete->R != NULL)
            {
                if(flag ==0)
                {
                    temp -> L = nodeTodelete -> R;
                    free(nodeTodelete);
                }
                else
                {
                    temp -> R = nodeTodelete -> R;
                    free(nodeTodelete);
                }
                
            }
            else if (nodeTodelete->L != NULL && nodeTodelete->R == NULL)
            {
            if(flag ==0)
                {
                    temp -> L = nodeTodelete -> L;
                    free(nodeTodelete);
                }
                else
                {
                    temp -> R = nodeTodelete -> L;
                    free(nodeTodelete);
                }
                
            }
            else
            {

                
                struct node *ser;
                struct node *rty = nodeTodelete -> L;
                while((rty->L != NULL && rty->L->num == num) || (rty->R != NULL && rty->R->num == num))
                {
                    rty = rty-> R;
                }
                ser = rty->R;
                if(flag ==0)
                {

                    
                    temp -> L = ser;
                    free(nodeTodelete);
                }
                else
                {
                    temp -> R = ser;
                    free(nodeTodelete);
                }

                if(ser -> L != NULL)
                    rty -> R = ser -> L;
                
                //nodeTodelete = currentNode->L;
            }
            printf("deleted\n");
            
        }
    }*/



    if(headNode != NULL && isFound2(num) == 1)
    {
        Node *nodeTodelete = search(headNode, num);

        if(headNode == nodeTodelete)
        {
            if (nodeTodelete->L == NULL && nodeTodelete->R == NULL)
            {
                headNode = NULL;
                
            }
            else if (nodeTodelete->L == NULL && nodeTodelete->R != NULL)
            {
                headNode = nodeTodelete -> R;
                
            }
            else if (nodeTodelete->L != NULL && nodeTodelete->R == NULL)
            {
                headNode = nodeTodelete -> L;
                
            }
            else
            {
                struct node *ser = nodeTodelete -> L;
                if(ser -> R == NULL)
                {
                    ser -> R = headNode -> R;
                    headNode = ser;
                }
                else
                {
                    struct node *rty;

                    while(ser->R->R != NULL && ser->R->R->num != num)
                    {
                        ser = ser-> R;
                    }
                    rty = ser->R;
                    if(rty -> L != NULL)
                    {
                        ser ->R = rty -> L;
                    }
                    else
                    {
                        ser -> R = NULL;
                    }
                    

                    rty ->L = headNode -> L;
                    rty ->R = headNode -> R;

                    headNode = rty;
                    
                }
            }
            
        }
        else
        {
            struct node *top =parent(headNode, num);
            int flag;    
            if (top -> L != NULL && top -> L -> num == num)
                {
                    flag = 0;
                }
            else
                {
                    flag = 1;
                }

            if (nodeTodelete->L == NULL && nodeTodelete->R == NULL)
            {
                if(flag == 0)
                {
                    top -> L = NULL;
                }
                else
                {
                    top -> R = NULL;
                }
            }
            else if (nodeTodelete->L == NULL && nodeTodelete->R != NULL)
            {
                if(flag == 0)
                {
                    top -> L = nodeTodelete -> R;
                }
                else
                {
                    top -> R = nodeTodelete -> R;
                }
            }
            else if (nodeTodelete->L != NULL && nodeTodelete->R == NULL)
            {
                if(flag == 0)
                {
                    top -> L = nodeTodelete -> L;
                }
                else
                {
                    top -> R = nodeTodelete -> L;
                }
                
            }
            else
            {
                struct node *ser = nodeTodelete -> L;
                if(ser -> R == NULL)
                {
                    ser -> R = nodeTodelete -> R;
                    if(flag == 0)
                    {
                        top -> L = ser;
                    }
                    else
                    {
                        top -> R = ser;
                    }
                }
                else
                {
                    struct node *rty;

                    while(ser->R != NULL && ser->R->num != num)
                    {
                       ser = ser-> R;
                    }
                    rty = ser->R;
                    ser ->R = rty -> L;

                    rty ->L = nodeTodelete -> L;
                    rty ->R = nodeTodelete-> R;

                    if(flag == 0)
                    {
                        top -> L = rty;
                    }
                    else
                    {
                        top -> R = rty;
                    }
                }
            }





        }
        printf("deleted\n");
        free(nodeTodelete);
    }
    else
    {
        printf("absent\n");
    }


}

Node *search(Node *node, int num)
{

    if (node == NULL)
    {
        return 0;
    }
    else if (node->num == num)
    {
        return node;
    }
    if (node->num < num)
    {
        return search(node->R, num);
    }
    else
    {
        return search(node->L, num);
    }
}

int isFound(int n)
{
    Node *node = search(headNode, n);

    if (node == NULL)
    {
        printf("absent\n");
        return 0;
    }
    else
    {
        printf("present\n");
        return 1;
        
    }
}

int isFound2(int n)
{
    Node *node = search(headNode, n);

    if (node == NULL)
    {
        
        return 0;
    }
    else
    {
        
        return 1;
        
    }
}

Node *insert(Node *node, int num)
{
    // Allocate memory for new node
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->num = num;
    // Set end of list
    newNode->L = NULL;
    newNode->R = NULL;

    // this is new List
    if (node == NULL)
    {
        printf("inserted\n");
        return node = newNode;
        
    }

    else if (newNode->num < node->num)
    {
        node->L = insert(node->L, num);
    }
    else if (newNode->num > node->num)
    {
        node->R = insert(node->R, num);
    }

    else if (newNode->num == node->num)
    {
        printf("not inserted\n");
    }
    free(newNode);
    return node;
}

void print(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    else
    {
        printf("(");
        print(node->L);
        printf("%d", node->num);
        print(node->R);
        printf(")");
    }
}