#include<stdio.h>
#include<time.h>
void bubbleSort(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
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
    bubbleSort(arr,n);
    clock_t end=clock();
    double timer=(double)(end-begin)/CLOCKS_PER_SEC;
    printf("time is %.9lf",timer);
}
