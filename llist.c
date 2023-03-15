#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct nodeType{
    int info;
    struct nodeType *next;
}node;

void createEmptyList(node **head);
void traverseInOrder1(node *head);
void traverseInReverseOrder2(node *head);
node *searchInUnsortedList(node *head, int item);
node *searchInSortedList(node *head, int item);
void auxilliarySearch(node *head, node **ploc, node **loc, int item);
void insertAtBeginning(node **head, int item);
void insertAfterElement(node *head, int item, int after);
void insertAtEnd(node **head, int item);
void deleteFromBeginning(node **head);
void deleteFromEnd(node **head);
void deleteAfterElement(node *head, int after);
void reverseList(node **head);
void deleteList(node **head);

void createEmptyList(node **head){
    *head = NULL;
}

void traverseInOrder1(node *head){
    while(head != NULL){
        printf("%d\t", head->info);
        head = head->next;
    }
}

void traverseInReverseOrder2(node *head){
    if(head->next != NULL){
        traverseInReverseOrder2(head->next);
    printf("%d\t", head->info);
    }
}

node *searchInUnsortedList(node *head, int item){
    while((head != NULL) || (head->info != item))
        head = head->next;
    return head;
}

node *searchInSortedList(node *head, int item){
    while(head != NULL){
        if(head->info == item)
            return head;
        else 
            head = head->next;
    }
    return NULL;
}

void auxilliarySearch(node *head, node **ploc, node **loc, int item){
    int flag = 0;
    if(head == NULL)
        *ploc = *loc = NULL;
    else if(head->info == item){
        *ploc = NULL;
        *loc = head;
    }else{
        *ploc = head;
        *loc = head->next;
        while((*loc != NULL) && (!flag)){
            if((*loc)->info == item)
                flag = 1;
            else{
                *ploc = *loc;
                *loc = (*loc)->next;
            }
        }
    }
}

void insertAtBeginning(node **head, int item){
    node *ptr;
    ptr = (node *) malloc (sizeof(node));
    ptr->info = item;
    if(*head == NULL)
        ptr->next = NULL;
    else
        ptr->next = *head;
    *head = ptr;
}

void insertAtEnd(node **head, int item){
    node *ptr, *loc;
    ptr = (node *) malloc (sizeof(node));
    ptr->info = item;
    ptr->next = NULL;
    if(*head == NULL)
        *head = ptr;
    else{
        loc = *head;
        while(loc->next != NULL)
            loc = loc->next;
        loc->next = ptr;
    }
}

void insertAfterElement(node *head, int item, int after){
    node *ptr, *loc;
    loc = searchInUnsortedList(head, after);
    if(loc == (node *)NULL)
        return;
    ptr = (node *) malloc (sizeof(node));
    ptr->info = item;
    ptr->next = loc->next;
    loc->next = ptr;
}

void deleteFromBeginning(node **head){
    node *ptr;
    if(*head == NULL)
        return;
    else{
        ptr = *head;
        *head = (*head)->next;
        free(ptr);
    
    }
}

void deleteFromEnd(node **head){
    node *ptr, *loc;
    if(*head == NULL)
        return;
    else if((*head)->next == (node *)NULL){
        ptr = *head;
        *head = NULL;
        free(ptr);
    }
}

void deleteAfterElement(node *head, int after){
    node *ptr, *loc;
    loc = searchInUnsortedList(head, after);
    if(loc == (node *)NULL)
        return;
    ptr = loc->next;
    loc->next = ptr->next;
    free(ptr);
}

void reverseList(node **head){
    node *prevoiusnode, *currentnode, *nextnode;
    currentnode = *head;
    nextnode = currentnode->next;
    prevoiusnode = NULL;
    currentnode->next = NULL;
    while(nextnode != NULL){
        prevoiusnode = currentnode;
        currentnode = nextnode;
        nextnode = currentnode->next;
        currentnode->next = prevoiusnode;
    }
    *head = currentnode;
}

void deleteList(node **head){
    node *ptr;
    while(*head != NULL){
        ptr = *head;
        *head = (*head)->next;
        free(ptr);
    }
}

void main(){
    node *head;
    int choice, element, after;
    createEmptyList(&head);
    while(1){
        printf("****MENU****");
        printf("\n1.Insert at beginning");
        printf("\n2.Insert at End.");
        printf("\n3.Insert after a given element");
        printf("\n4.Traverse in order");
        printf("\n5.Traverse in reverse order");
        printf("\n6.Delete from beginning");
        printf("\n7.Delete from end");
        printf("\n8.Delete after a given element");
        printf("\n9.Reverse linked list");
        printf("\n10.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: printf("\nEnter element: ");
                    scanf("%d", &element);
                    insertAtBeginning(&head, element);
                    break;
            case 2: printf("\nEnter element: ");
                    scanf("%d", &element);
                    insertAtEnd(&head, element);
                    break;
            case 3: printf("\nEnter element: ");
                    scanf("%d", &element);
                    printf("\nEnter after which element to insert: ");
                    scanf("%d", &after);
                    insertAfterElement(head, element, after);
                    break;
            case 4: if(head == NULL)
                        printf("\nList is empty");
                    else
                        traverseInOrder1(head);
                    printf("\nPress any key to continue...");
                    getch();
            case 5: if(head == NULL)
                        printf("\nList is empty");
                    else
                        traverseInReverseOrder2(head);
                    printf("\nPress any key to continue...");
                    getch();
            case 6: deleteFromBeginning(&head);
                    break;
            case 7: deleteFromEnd(&head);
                    break;
            case 8: printf("\nEnter element after which to delete: ");
                    scanf("%d", &after);
                    deleteAfterElement(head, after);
                    break;
            case 9: reverseList(&head);
                    break;
            case 10: deleteList(&head);
                     exit(1);
            default: printf("\nWrong choice. Please enter correct choice");
        }
    }
}
