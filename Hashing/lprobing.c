#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

int hash(int key){
    return key%SIZE;
}

int probe(int H[], int key){//Probe for insertion
    int index = hash(key);
    int i = 0;
    while(H[(index+i) % SIZE] != 0)
        i++;
    return (index+i) % SIZE;
}

void Insert(int H[], int key){
    int index = hash(key);
    if(H[index] != 0)
        index = probe(H, key);
    H[index] = key;
}

int Search(int  H[], int key){
    int index = hash(key);
    int i = 0;
    while(H[(index + i) % SIZE] != key)
        i++;
    return (index+i)%SIZE;
}

int main(){
    int HT[10] = {0};
    int ch = 1;
    while(ch != 0){
        printf("Enter key to be stored: ");
        scanf("%d", &ch);
        if(ch == 0)
            break;
        Insert(HT, ch);
    }
    for(int i = 0; i < 10; i++)
        printf("\t%d", HT[i]);

    printf("\nKey found at %d\n", Search(HT, 35));
}
