#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void print(int *a,int n)
{
    printf("The elements are:\n");
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
}
int* randarray(int n)
{
    if(n<=0)
        return NULL;
    int *a=malloc(n*sizeof(n));
    for(int i=0;i<n;i++)
        a[i]=rand()%n;
    return a;
}
void swap(int *a,int*b)
{
    int t=*a;
    *a=*b;
    *b=t;
}


//Pivot at end
int partition2(int *a,int l,int u)
{
    int p1=l-1,pivot=a[u];
    for(int p2=l;p2<u;p2++)
    {
        
        if(a[p2]<pivot)
        {
            p1+=1;
            swap(&a[p1],&a[p2]);
        }
    }
    swap(&a[p1+1],&a[u]);
    
    return p1+1;
}

void quicksort2(int *a,int l,int u)
{
    if(l<u)
    {
        int p=partition2(a,l,u);
        quicksort2(a,l,p-1);
        quicksort2(a,p+1,u);
    }
}


//Randomized pivot
int partition3(int *a,int l,int u)
{
    int p1=l-1,pivot=a[u];
    for(int p2=l;p2<u;p2++)
    {
        
        if(a[p2]<pivot)
        {
            p1+=1;
            swap(&a[p1],&a[p2]);
        }
    }
    swap(&a[p1+1],&a[u]);
    
    return p1+1;
}
int randomized_partition3(int*a,int l,int u)
{
    int i=rand()%(u-l+1);
    swap(&a[u],&a[i+l]);
    return partition3(a,l,u);
}

void quicksort3(int *a,int l,int u)
{
    if(l<u)
    {
        int p=randomized_partition3(a,l,u);
        quicksort3(a,l,p-1);
        quicksort3(a,p+1,u);
    }
}


//Pivot at Begining
int partition1(int *a,int l,int u)
{
    int p1=u+1,pivot=a[l];
    for(int p2=u;p2>l;p2--)
    {
        
        if(a[p2]>pivot)
        {
            p1-=1;
            swap(&a[p1],&a[p2]);
        }
    }

    swap(&a[p1-1],&a[l]);
    
    return p1-1;
}

void quicksort1(int *a,int l,int u)
{
    if(l<u)
    {
        int p=partition1(a,l,u);
        quicksort1(a,l,p-1);
        quicksort1(a,p+1,u);
    }
}
int check(int *a,int n)
{
    for(int i=0;i<n-1;i++)
        if(a[i]>a[i+1])
            return 0;
    return 1;
}
void main()
{   
    clock_t t1, t2, t3;
    srand(time(0));
    int n = 1000000;
    int *a;
    
	t1 = -clock();
    a=randarray(n);
    quicksort1(a,0,n-1);
    print(a,n);
	t1 += clock();
	printf("Time taken: %lf\n", (double)(t1/CLOCKS_PER_SEC));
    
	t2 = -clock();
    a=randarray(n);
    quicksort2(a,0,n-1);
    print(a,n);
	t2 += clock();
	printf("Time taken: %lf\n", (double)(t2/CLOCKS_PER_SEC));
    
	t3 = -clock();
    a=randarray(n);
    quicksort3(a,0,n-1);
    print(a,n);
	t3 += clock();
	printf("Time taken: %lf\n", (double)(t3/CLOCKS_PER_SEC));
}
