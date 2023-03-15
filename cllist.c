#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};

struct node *start = NULL;

void create_cll(){
    struct node *new_node, *ptr;
    int num;
    printf("\n Enter –1 to end");
    printf("\n Enter the data : ");
    scanf("%d", &num);
    while(num != -1){
        new_node = (struct node*)malloc(sizeof(struct node));
        new_node -> data = num;
        if(start == NULL){
            new_node -> next = new_node;
            start = new_node;
        }
        else{
            ptr = start;
            while(ptr->next != start)
                ptr = ptr->next;
            ptr->next = new_node;
            new_node->next = start;
        }
        printf("\nEnter the data: ");
        scanf("%d", &num);
    }
}

void display(){
    struct node *ptr;
    ptr=start;
    while(ptr -> next != start){
        printf("\t %d", ptr -> data);
        ptr = ptr -> next;
    }
    printf("\t %d", ptr -> data);
}

void beg(){
    struct node *new_node, *ptr;
    int num;
    printf("\nEnter the data: ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = start;
    while(ptr->next != start)
        ptr = ptr->next;
    ptr->next = new_node;
    new_node->next = start;
    start = new_node;
}

void end(){
    struct node *new_node, *ptr;
    int num;
    printf("\nEnter the data: ");
    scanf("%d", &num);
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = start;
    while(ptr->next != start)
        ptr = ptr->next;
    ptr->next = new_node;
    new_node->next = start;
}

void before(){
    if(start == NULL)
        return;
    struct node *new_node, *ptr, *preptr;
    int num, val;
    printf("\nEnter the data: ");
    scanf("%d", &num);
    printf("\nEnter the value before which it is to be inserted: ");
    scanf("%d", &val);
    ptr = start;
    preptr = ptr;
    do{
        if(ptr->data == val){
            new_node = (struct node*)malloc(sizeof(struct node));
            new_node->data = num;
            new_node->next  = preptr->next;
            preptr->next = new_node;
        }
        preptr = ptr;
        ptr = ptr->next;
    }while(ptr != start);
}


void after(){
    if(start == NULL)
        return;
    struct node *new_node, *ptr, *preptr;
    int num, val;
    printf("\nEnter the data: ");
    scanf("%d", &num);
    printf("\nEnter the value after which it is to be inserted: ");
    scanf("%d", &val);
    ptr = start->next;
    do{
        if(ptr->data == val){
            new_node = (struct node*)malloc(sizeof(struct node));
            new_node->data = num;
            new_node->next  = ptr->next;
            ptr->next = new_node;
            if(ptr == start)
                start = ptr;
        }
        ptr = ptr->next;
    }while(ptr != start->next);
}

void del_beg(){
    struct node *ptr, *preptr;
    ptr = start;
    while(ptr->next != start){
        preptr = ptr;
        ptr = ptr->next;
    }
    ptr->next = start->next;
    free(start);
    start = ptr->next;
}

void del_end(){
    struct node *ptr, *preptr;
    ptr = start;
    while(ptr->next != start){
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = ptr->next;
    free(ptr);
}

void del_after(){
    struct node *preptr, *ptr;
    int val;
    printf("\nEnter the value after which the node is to be deleted: ");
    scanf("%d", &val);
    ptr = start;
    preptr = ptr;
    while(preptr->data != val){
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = ptr->next;
    if(ptr == start)
        start = preptr->next;
    free(ptr);
}

void del_list(){
    struct node *ptr;
    ptr = start;
    while(ptr->next != start)
        del_end();
    free(start);
}

void main(){
    int choice;
    while(1){
            printf("\n\n *****MAIN MENU *****");
        printf("\n 1: Create a list");
        printf("\n 2: Display the list");
        printf("\n 3: Add a node at the beginning");
        printf("\n 4: Add a node at the end");
        printf("\n 5: Delete a node from the beginning");
        printf("\n 6: Delete a node from the end");
        printf("\n 7: Delete a node after a given node");
        printf("\n 8: Delete the entire list");
        printf("\n 9: EXIT");
        printf("\n 10. Add a node before a given node");
        printf("\n 11. Add a node after a given node");
        printf("\n\n Enter your option : ");
        scanf("%d", &choice);
        switch(choice){
            case 1: create_cll();
                    printf("\nCIRCULAR NODE CREATED.");
                    break;
            case 2: display();
                    break;
            case 3: beg();
                    break;
            case 4: end();
                    break;
            case 5: del_beg();
                    break;
            case 6: del_end();
                    break;
            case 7: del_after();
                    break;
            case 8: del_list();
                    break;
            case 9: exit(0);
            case 10: before();
                     break;
            case 11: after();
                     break;
            default: printf("\nWrong choice. Please give correct choie.");
        }
    }
}
