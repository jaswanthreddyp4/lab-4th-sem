#include<stdio.h>
int n,a[10][10],p[10][10];
void path(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            p[i][j]=a[i][j];
        }
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(p[i][k]==1&&p[k][j]==1)
                p[i][j]=1;
            }
        }
    }
    
}
void main(){
    printf("enter number of nodes\n");
    scanf("%d",&n);
    printf("enter adjacaency matrix\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    path();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d\t",p[i][j]);
        }
        printf("\n");
    }
}
