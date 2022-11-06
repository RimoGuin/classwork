#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<malloc.h>

struct node{
    struct node *left;
    struct node *right;
    int data;
    char thread; //If thread = '0', then normal pointer, else, thread
};

void createtree(struct node **root){
    *root = NULL;
}

void inorderTraversal(struct node *root){
    struct node *pPtr, *qPtr;
    pPtr = root;
    do{
        qPtr = NULL;
        while(pPtr != NULL){//Traverse left branch
            qPtr = pPtr; 
            pPtr = pPtr->left;
        }
        if(qPtr != NULL){//Tree is not empty
            printf("%d ", qPtr->data);
            pPtr = qPtr->right;
            while((qPtr->thread == '1') && (pPtr != NULL)){
                printf("%d ", pPtr->data);
                qPtr = pPtr;
                pPtr = pPtr->right;
            }
        }
    }
    while(pPtr != NULL);
}

void insertElement(struct node **tree, int element){
    struct node *ptr, *nodeptr, *parentptr;
    ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = element;
    ptr->left = NULL;
    if(*tree == NULL){
        *tree = ptr;
        ptr->right = NULL;
        ptr->thread = '0';
    }
    else{
        parentptr = NULL;
        nodeptr = *tree;
        while(nodeptr != NULL){
            parentptr = nodeptr;
            if(element < nodeptr->data)
                nodeptr = nodeptr->left;
            else{
                if(nodeptr->thread == '1')
                    nodeptr = NULL;
                else
                    nodeptr = nodeptr->right;
            }
        }
        if(element < parentptr->data){
            parentptr->left = ptr;
            ptr->right = parentptr;
            ptr->thread = '1';
        }else{
            if(parentptr->thread == '1'){
                parentptr->thread = '0';
                ptr->thread = '1';
                ptr->right = parentptr->right;
                parentptr->right = ptr;
            }else{
                ptr->thread = '0';
                ptr->right = NULL;
                parentptr->right = ptr;
            }
        }
    }
}

struct node *findlargestnode(struct node *tree){
    if((tree->thread == '1') || (tree->right == NULL))
        return tree;
    else
        return findlargestnode(tree->right);
}

void deletenode(struct node **tree, int element){
    struct node *tempPtr1, *tempPtr2;
    char tempThread;
    if(*tree == NULL){
        printf("\nTree is empty.");
        getch();
        return;
    }
    if(element < (*tree)->data)
        deletenode(&((*tree)->left), element);
    else if(element > (*tree)->data)
        deletenode(&((*tree)->right), element);
    /*node with 2 children*/
    else if((*tree)->left && (*tree)->right && (*tree)->thread == '0'){
        tempPtr1 = findlargestnode((*tree)->left);
        deletenode(&((*tree)->left), tempPtr1->data);
    }else{
        tempPtr1 = *tree;
        /*terminal node*/
        if(((*tree)->left == NULL) && ((*tree)->right == NULL) || ((*tree)->thread == '1'))
            *tree = NULL;
        else if((*tree)->left != NULL){      /*Left child only*/
            tempThread = (*tree)->thread;
            tempPtr2 = (*tree)->right;
            *tree = (*tree)->left;
            (*tree)->thread = tempThread;
            if(tempThread == '1')
                (*tree)->right = tempPtr2;    
        }
        else                                 /*Right child only*/
            *tree = (*tree)->right;
        free(tempPtr1);
    }
}

void removetree(struct node **tree){
    if(*tree != NULL){
        removetree(&((*tree)->left));
        if((*tree)->thread == '0')
            removetree(&((*tree)->right));
        free(*tree);
    }
}

int main(){
    int choice, element, height;
    struct node *root, *loc;
    createtree(&root);
    while(1){
        printf("\n***MENU***");
        printf("\n1.Insert node");
        printf("\n2.Inorder traversal");
        printf("\n3.Delete node");
        printf("\n4.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: printf("Element to be inserted into tree: ");
                    scanf("%d", &element);
                    insertElement(&root, element);
                    break;
            case 2: printf("\nInorder Traversal: ");
                    inorderTraversal(root);
                    printf("\nPress any key to continue: ");
                    getch();
                    break;
            case 3: printf("\nElement to be deleted form tree: ");
                    scanf("%d", &element);
                    deletenode(&root, element);
                    break;
            case 4: removetree(&root);
                    exit(0);
        }
    }
}
