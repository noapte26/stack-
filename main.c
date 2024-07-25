#include <stdio.h>
#include <stdlib.h>
typedef struct node node;
struct node {
    int data;
    node*pNext;
};
node*newNode(int value){
    node*n =(node*) malloc(sizeof(node));
    if(n){
        n->data = value;
        n->pNext = NULL;
    }
    return n;
}
 node*push(node*pTop, int data){
    node*pn = newNode(data);
    if(pn){
       pn->pNext =pTop ;
       pTop = pn;
    }
    return pTop;


}
int pop(node** ppTop){
    int data=0;
    if(!(*ppTop)){
        printf("stack is empty.\n");
        return 0;
    }
    data =(*ppTop)->data;
    node* temp=*ppTop;
    *ppTop = (*ppTop) ->pNext;
    free(temp);
    return data;
}
int isEmpty(node*pTop){
    if (!pTop){
        return 1;
    }
    return 0;
}
int peek(node* top){
    if(top){
        return top->data;
    }
    return 0;
}
void displayStack(node*top){
    while(top){
        printf("%d ", top->data);
        top = top->pNext;
    }
}
void sortStack(node** ppTop){             // Max on top
    if(!*ppTop){
        printf("stack is empty!\n");
        return ;
    }
    node* pTop2 = NULL;
    while(!isEmpty(*ppTop)){
        int temp = pop(ppTop);
        while(!isEmpty(pTop2) && peek(pTop2) > temp){
            int x = pop(&pTop2);
            *ppTop = push(*ppTop, x);
        }
        pTop2 = push(pTop2, temp);
    }
    *ppTop = pTop2;
}
int main()
{
    node* pTop1 = NULL;
    pTop1 = push(pTop1, 23);
    pTop1 = push(pTop1, 92);
    pTop1 = push(pTop1, 98);
    pTop1 = push(pTop1, 31);
    pTop1 = push(pTop1, 3);
    pTop1 = push(pTop1, 34);
    pTop1 = push(pTop1, 2);
    printf("Display the stack : \n");
    displayStack(pTop1);
    printf("\n");
    int x=pop(&pTop1);
    printf("after poping %d from the stack, the stack : \n",x );
    displayStack(pTop1);
    printf("\nAfter sorting the stack :\n");
    sortStack(&pTop1);
    displayStack(pTop1);
    printf("\n");
    return 0;
}
