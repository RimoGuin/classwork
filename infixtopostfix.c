#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Stack{
    int top;
    unsigned capacity;
    int* array;
};

struct Stack* createStack(unsigned capacity){
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    if(!stack) return NULL;
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isEmpty(struct Stack* stack){
    return stack->top = -1;
}

char peek(struct Stack* stack){
    return stack->array[stack->top];
}

char pop(struct Stack* stack){
    if(!isEmpty(stack))
        return stack->array[stack->top--];
    return '$';
}

void push(struct Stack* stack, char op){
    stack->array[++stack->top] = op;
}

//Utility function to check if the given character is an operand or not
int isOperand(char ch){
    return(ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
}

//Utility function to return precedence of a given operator
//Higher number returned means higher precedence
int precedence(char ch){
    switch(ch){
        case '^' : return 4;
        case '*' :
        case '/' : return 3;
        case '%' : return 2;
        case '+' : 
        case '-' : return 1;
    }
    return -1;
}

//Main function which converts infix to postfix expression
int infixToPostfix(char* exp){
    int i, k;

    struct Stack* stack = createStack(strlen(exp));
    if(!stack) return -1;//Check if stack was created or not

    for(i = 0, k = -1; exp[i]; ++i){
        //If scanned character is operand, add it to output
        if(isOperand(exp[i]))
            exp[++k] = exp[i];
        //If scanned character is an '(', push it to stack
        else if(exp[i] == '(')
            push(stack, exp[i]);
        //If scanned character is ')', pop and output from the stack
        //until an '(' is encountered
        else if(exp[i] == ')'){
            while(!isEmpty(stack) && peek(stack) != '(')
                exp[++k] = pop(stack);
            if(!isEmpty(stack) && peek(stack) != '(')
                return -1; // Invalid expression
            else pop(stack);
        }

        else{ //An operator is encountered
            while(!isEmpty(stack) && precedence(exp[i]) <= precedence(peek(stack)))
                exp[++k] = pop(stack);
        push(stack, exp[i]);
        }
    }

    //Pop all the operators from stack
    while(!isEmpty(stack))
        exp[++k] = pop(stack);

    exp[++k] = '\0';
    printf("%s", exp);
}

int main(){
    char e[100];
    char* exp;
    printf("Enter the infix expression: ");
    scanf("%s", e);
    exp = e;
    infixToPostfix(exp); //Function call
    return 0;
}
