#include <stdio.h>
#include <stdlib.h>

#define kAll 57
#define kLeave 7

typedef struct person{
    int sequence;
    struct person *next;
}personNode;


void makeANode(int number, personNode **newNode);
void insertNode(personNode **newNode, personNode **head);


int main(void)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int result = 0;
    int temp = 0;

    personNode *newNode = NULL;
    personNode *head = NULL;
    personNode *current = NULL;
    personNode *previous = NULL;

    for (j = 0; j < kAll; j++)
    {
        temp = j + 1;

        makeANode(temp, &newNode);

        insertNode(&newNode, &head);

        if (j == kAll-1)
        {
            newNode->next = head;
        }

    }

    current = head;
    i = 1;

    while (1)
    {
        if (i % kLeave == 0)
        {
            previous->next = current->next;
            current = previous->next;
            i++;
        }

        else
        {
            previous = current;
            current = current->next;
            i++;
        }

        if (previous->sequence == current->sequence)
        {
            result = previous->sequence;
            break;
        }
    }

    printf("%d", result);
    return 0;
}


void makeANode(int number, personNode **newNode)
{

    *newNode = (personNode*)malloc(sizeof(personNode));

    (*newNode)->sequence = number;

    (*newNode)->next = NULL;

}

void insertNode(personNode **newNode, personNode **head)
{
    personNode *curr = *head;
    
    if (*head == NULL)
    {
        *head = *newNode;
    }

    else
    {
        while (curr->next!=NULL)
        {
            curr = curr->next;
        }

        curr->next = *newNode;
    }
}