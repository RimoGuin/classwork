#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *start = NULL:

void create_ll(){
    start = NULL;
    struct node *new_node, *ptr;
    int num;
    printf("\nEnter -1 to exit");
    printf("\nEnter the data: ");
    scanf("%d", &num);
    while(num != -1){
        if(start == NULL){
            new_node = (struct node*)malloc(sizeof(struct node));
            new_node->prev = NULL;
            new_node->data = num;
            new_node->next = NULL;
            start = new_node;
        }
        else{
            ptr = start;
            new_node = (struct node*)malloc(sizeof(struct node));
            new_node->data = num;
            while(ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = new_node;
            new_node->prev = ptr;
            new_node->next = NULL;
        }
        printf("\nEnter the data: ");
        scanf("%d", &num);
    }
}

void display(){
    struct node *ptr;
    ptr = start;
    while(ptr != NULL){
        printf("\t%d", ptr->data);
        ptr = ptr->next;
    }
}

void beg(){
    struct node *new_node;
    int num;
    printf("\nEnter the data: ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    start->prev = new_node;
    new_node->next = start;
    new_node->prev = NULL;
    start = new_node;
}

void end(){
    struct node *new_node;
    int num;
    printf("\nEnter the data: ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = start;
    while(ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = new_node;
    new_node->prev = ptr;
    new_node->next = NULL;
}

void before(){
    struct node *new_node, *ptr;
    int num, val;
    printf("\nEnter the data: ");
    scanf("%d", &num);
    printf("\nEnter the value before which data is to be inserted: ");
    scanf("%d", &val);
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = start;
    while(ptr->data != val)
        ptr = ptr->next;
    new_node->next = ptr;
    new_node->prev = ptr->prev;
    ptr->prev->next = new_node;
    ptr->prev = new_node;
}

void after(){
    struct node *new_node, *ptr;
    int num, val;
    printf("\nEnter the data: ");
    scanf("%d", &num);
    printf("\nEnter the value after which data is to be inserted: ");
    scanf("%d", &val);
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = start;
    while(ptr->data != val)
        ptr = ptr->next;
    new_node->prev = ptr;
    new_node->next = ptr->next;
    ptr->next->prev = new_node;
    ptr->next = new_node;
}

void delend(){
    struct node *ptr;
    ptr = start;
    while(ptr->next != NULL)
        ptr = ptr->next;
    ptr->prev->next = NULL;
    free(ptr);
    return start;
}

void delbeg(){
    struct node *ptr;
    ptr = start;
    start = start->next;
    start->prev = NULL;
    free(ptr);
}


