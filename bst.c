#include<stdio.h>
#include<malloc.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *tree;
void create_tree(struct node*);
struct node *insertElement(struct node*, int);
void preorderTraversal(struct node*);
void inorderTraversal(struct node*);
void postorderTraversal(struct node*);
struct node *deleteElement(struct node*, int);
int Height(struct node*);
struct node *deleteTree(struct node*);
struct node *minValNode(struct node *);

void create_tree(struct node *tree){
    tree = NULL;
}
struct node* insertElement(struct node *tree, int val){
    struct node *ptr, *nodeptr, *parentptr;
    ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = val;
    ptr->left = ptr->right = NULL;
    if(tree == NULL){
        tree = ptr;
        tree->left = tree->right = NULL;
    }
    else{
        parentptr = NULL;
        nodeptr = tree;
        while(nodeptr != NULL){
            parentptr = nodeptr;
            if(val < nodeptr->data)
                nodeptr = nodeptr->left;
            else
                nodeptr = nodeptr->right;
        }
        if(val < parentptr->data)
            parentptr->left = ptr;
        else
            parentptr->right = ptr;
    }
    return tree;
}

void preorderTraversal(struct node *tree){
    if(tree != NULL){
        printf("%d\t", tree->data);
        preorderTraversal(tree->left);
        preorderTraversal(tree->right);
    }
}

void inorderTraversal(struct node *tree){
    if(tree != NULL){
        inorderTraversal(tree->left);
        printf("%d\t", tree->data);
        inorderTraversal(tree->right);
    }
}

void postorderTraversal(struct node *tree){
    if(tree != NULL){
        postorderTraversal(tree->left);
        postorderTraversal(tree->right);
        printf("%d\t", tree->data);
    }
}

struct node *deleteElement(struct node *tree, int val){
    if(tree == NULL){
        return tree;
    }
    if(val < tree->data)
        tree->left = deleteElement(tree->left, val);
    else if(val > tree->data)
        tree->right = deleteElement(tree->right, val);
    else{
        if(tree->left == NULL){
            struct node* temp = tree->right;
            free(tree);
            return temp;
        }
        else if(tree->right == NULL){
            struct node* temp = tree->left;
            free(tree);
            return temp;
        }

        //node with 2 children
        struct node *temp = minValNode(tree->right);
        tree->data = temp->data;
        tree->right = deleteElement(tree->right, temp->data);
    }
    return tree;
}

struct node *minValNode(struct node *node){
    struct node* current = node;
    while(current && current->left != NULL)
        current = current->left;
    return current;
}

int main(){
    int option, val;
    struct node *ptr;
    create_tree(tree);
    do{
        printf("\n***MENU***");
        printf("\n1. Insert Element");
        printf("\n2.Preorder traversal");
        printf("\n3.Inorder traversal");
        printf("\n4.Postorder traversal");
        printf("\n5.Delete element");
        printf("\n6.Exit");
        printf("\nEnter your option: ");
        scanf("%d", &option);
        switch(option){
            case 1: printf("\nEnter value of new node: ");
                    scanf("%d", &val);
                    tree = insertElement(tree, val);
                    break;
            case 2: printf("\nPreorder traversal: ");
                    preorderTraversal(tree);
                    break;
            case 3: printf("\nInorder traversal: ");
                    inorderTraversal(tree);
                    break;
            case 4: printf("\nPostorder traversal: ");
                    postorderTraversal(tree);
                    break;
            case 5: printf("\nEnter element to be deleted: ");
                    scanf("%d", &val);
                    tree = deleteElement(tree, val);
                    break;
        }
    }while(option != 6);

    return 0;
}
