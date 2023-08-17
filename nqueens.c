#include <stdio.h>
int count =0;

int noAttack(char board[5][5],int row,int col,int n)
{
    for(int j=0;j<n;j++){
        if(board[row][j]=='Q')
            return 0;
    }
    for(int i=0;i<n;i++){
        if(board[i][col]=='Q')
            return 0;
    }
    int x=row,y=col;
    while(x>=0 && y>=0)
    {
        if(board[x][y]=='Q')
            return 0;
                x--;
                y--;
    }
    int x1 = row, y1=col;
    while(x1>=0 && y1<n)
    {
        if(board[x1][y1]=='Q')
            return 0;
        x1--;
        y1++;
    }
}
int solveNQueenProb(char board[5][5],int n,int row)
{
    if(row==n){
        printf("\n********Solution is %d****\n",++count);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                printf("%c",board[i][j]);
            }
            printf("\n");
        }
    }
    for(int col=0;col<n;col++){
        if(noAttack(board,row,col,n)){
            board[row][col]='Q';
            int canPlaceQ = solveNQueenProb(board,n,row+1);
            if(canPlaceQ==1){
                return 1;
            }
            board[row][col]='-';
        }
    }
}
int main() {
     char board[5][5];
    int n;
    printf("\n Enter the number of Queens:\t");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            board[i][j]='-';
        }
    }
    solveNQueenProb(board,n,0);
}
