#include<stdio.h>
int n, a[10][10], p[10][10];

void path() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            p[i][j] = a[i][j];
        }
    }
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(p[i][k] + p[k][j] < p[i][j])
                    p[i][j] = p[i][k] + p[k][j];
            }
        }
    }
}

int main() {
    printf("Enter number of nodes:\n");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    path();
    printf("Shortest path matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d\t", p[i][j]);
        }
        printf("\n");
    }
    return 0;
}
