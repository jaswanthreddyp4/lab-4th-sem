#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void merge(int array[],int low,int mid,int high,int size){
    int temp[size];
    int left=low;
    int right=mid+1;
    int k=0;
    while(left<=mid&& right<=high){
    if(array[left]<=array[right]){
        temp[k]=array[left];
        left++;
        k++;
    }else{
        temp[k]=array[right];
        right++;
        k++;
    }
    }
    while(left<=mid){
        temp[k]=array[left];
        left++;
        k++;
    }
     while(right<=high){
        temp[k]=array[right];
        right++;
        k++;
    }
    for(int i=0;i<size;i++){
        array[i+low]=temp[i];
    }
}
void mergeSort(int array[],int low,int high){
    if(low>=high)
    return;
    else{
        int mid=(low+high)/2;
        mergeSort(array,low,mid);
        mergeSort(array,mid+1,high);
        merge(array,low,mid,high,high-low+1);
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
    mergeSort(array,0,n-1);
    clock_t end=clock();
    printf("sorted array\n");
    for(int i=0;i<n;i++){
        printf("%d\t",array[i]);
    }
}
