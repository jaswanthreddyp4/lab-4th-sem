#include<stdio.h>

int max(int a,int b){
    if(a>b)
    return a;
    return b;
}
void main(){
    int n;
    printf("enter number of items\n");
    scanf("%d",&n);
    int weight[n];
    int value[n];
    printf("enter weights\n");
    for(int i=0;i<n;i++){
        scanf("%d",&weight[i]);
    }
      printf("enter values\n");
    for(int i=0;i<n;i++){
        scanf("%d",&value[i]);
    }
    int capacity;
    printf("enter capacity \n");
    scanf("%d",&capacity);
    int matrix[n+1][capacity+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<capacity;j++){
            matrix[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=capacity;j++){
            if(j-weight[i-1]<0)
            matrix[i][j]=matrix[i-1][j];
            else{
                matrix[i][j]=max(matrix[i-1][j],value[i-1]+matrix[i-1][j-weight[i-1]]);
            }
        }
    }
    for(int i=0;i<n+1;i++){
        for(int j=0;j<capacity+1;j++){
            printf("%d\t",matrix[i][j]);
        }
        printf("\n");
    }
    
}
