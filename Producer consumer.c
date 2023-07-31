#include<stdio.h>
#include<stdlib.h>

typedef struct stack{
    int n;
    int top;
}stk;
void main(){
    int choice;
    stk stk;

    printf("Enter the maximum number of elements: ");
    scanf("%d", &stk.n);

    stk.top = -1;

    printf("Enter choice\n1. Producer\n2. Consumer\n3. Exit: ");
    do{
        scanf("%d", &choice);
        switch(choice){
            case 1:
                producer(&stk);
                break;
            case 2:
                consumer(&stk);
                break;
            case 3:
                printf("THANK YOU! BYE!\n");
                exit(0);
            default:
                printf("Incorrect input! Please try again!\n");
        }
    }while(choice != 3);
}

void producer(stk *stk){
    if(stk->top == stk->n - 1){
        printf("BUFFER IS FULL!\n");
    }
    else{
        printf("Producer produces item %d\n", ++(stk->top) + 1);
    }
}

void consumer(stk *stk){
    if(stk->top == -1){
        printf("BUFFER IS EMPTY!\n");
    }
    else{
        printf("Consumer consumes item %d\n", --(stk->top) + 2);
    }
}
