#include<stdio.h>
#define sz 100
#include<stdlib.h>
int cq[sz],rear=-1,count=0,front=0;
void insert();
void deletion();
void display();

int main()
{
    int item,ch;
    for(;;)
    {
        printf("1. Insert\n 2. Delete\n 3. Display\n 4. Exit\n Enter your choice:  ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\n");
                    printf("Enter the print job in spool:\n");
                    scanf("%d",&item);
                    insert(item);
                    break;
            case 2: printf("\n");
                    deletion();
                    break;
            case 3: printf("\n");
                    display();
                    break;
            case 4: exit(0);
            default: printf("Enter a valid number!\n");
        }
    }
    return (0);
}

void insert(int item)
{
    rear=(rear+1)%sz;
    cq[rear]=item;
    count++;
}

void deletion()
{
    if(count==0)
    {
        printf("No job in print spool!\n");
    }
    else
    {
        printf("%d exits print spool\n",cq[front]);
        front=(front+1)%sz;
        count--;
    }
}

void display()
{
    int i,j;
    if(count==0)
    {
        printf("Print spool is empty!\n");
    }
    else
    {
        printf("Content of print Spool\n");
        j=front;
        for(i=j;i<count;i++)
        {
            printf("%d is printing...\n",cq[j]);
            j=(j+1)%sz;
        }
    }
}


