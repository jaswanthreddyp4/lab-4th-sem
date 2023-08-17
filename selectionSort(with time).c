#include<stdio.h>
#include<time.h>
void selectionSort(int arr[],int n){
    for(int i=0;i<n;i++){
        int min=i;
        for(int j=i;j<n;j++){
            if(arr[j]<arr[min])
            min=j;
        }
        int temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
    
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
}
int main(){
    int n;
    printf("enter number of elements\n");
    scanf("%d",&n);
    int arr[n];
    printf("after sorting\n");
    for(int i=0;i<n;i++){
        arr[i]=rand()%100;
    }
    clock_t begin=clock();
    selectionSort(arr,n);
    clock_t end=clock();
    double timer=(double)(end-begin)/CLOCKS_PER_SEC;
    printf("time is %.9lf",timer);
}
