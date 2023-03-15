#include<stdio.h>
int stack[50], i, j, n, ch, top = -1;
void push();
void pop();
void display();
int main(){
    printf("Enter a number of elements using stack:\n");
    scanf("%d", &n);
    printf("***STACK USING ARRAY***\n");
    printf("1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
    while(ch!=4){
        printf("Enter your choice:");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("***EXIT***\n");
                break;
            default:
                printf("Enter a valid input!\n");
        }
    }
 }
void push(){
    int val;
    if(top == n-1)
        printf("STACK IS IN OVERFLOW\n");
    else{
        printf("Enter the value to be pushed:");
        scanf("%d", &val);
        top++;
        stack[top] = val;
    }
}
void pop(){
    if(top == -1)
        printf("STACK IS IN UNDERFLOW\n");
    else
        top--;
}
void display(){
    for(i = top; i >= 0; i--)
        printf("%d\n", stack[i]);
    if(top == -1)
        printf("STACK IS EMPTY.\n");
}
