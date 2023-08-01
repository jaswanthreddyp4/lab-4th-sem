#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int partition(int array[],int low,int high){
    int pivot=array[low];
    int i=low;
    int j=high;
    while(i<j){
        while(array[i]<=pivot&&i<=high-1){
        i++;
    }
    while(array[j]>pivot&&j>=low+1){
        j--;
    }
    if(j>i){
        int temp=array[i];
        array[i]=array[j];
        array[j]=temp;
    }
    }
    int temp=array[low];
    array[low]=array[j];
    array[j]=temp;
    return j;
}

void quickSort(int array[],int low,int high){
    if(low<high){
        int partitionIndex=partition(array,low,high);
        quickSort(array,low,partitionIndex-1);
        quickSort(array,partitionIndex+1,high);
    }
}
void main(){
    printf("enter size of matrix\n");
    int n;
    scanf("%d",&n);
    int array[n];
    srand(time(0));
    printf("randomly generated array\n");
    for(int i=0;i<n;i++){
        array[i]=rand()%100;
        printf("%d\t",array[i]);
    }
    printf("\n");
    clock_t start=clock();
    quickSort(array,0,n-1);
    clock_t end=clock();
    printf("sorted array\n");
    for(int i=0;i<n;i++){
        printf("%d\t",array[i]);
    }
}
