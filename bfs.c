#include<stdio.h>
#include<stdbool.h>
# define max 100

int graph[max][max];
int visited[max];
int queue[max];
int front=-1,rear=-1;

void enqueue(int vertex){
    if(rear==max-1)
    return;
    else{
        if(front==-1)
        front=0;
        rear=rear+1;
        queue[rear]=vertex;
    }
}
int dequeue(){
    if(front==-1||front>rear)
    return;
    int vertex=queue[front];
    front++;
    return vertex;
}
bool isQueueEmpty(){
    return front==-1||front>rear;
}
void bfs(int startingVertex,int n){
    visited[startingVertex]=true;
    enqueue(startingVertex);
    
    while(!isQueueEmpty()){
       int currentVertex=dequeue();
       printf("%d\t",currentVertex);
       for(int i=0;i<n;i++){
       if(graph[currentVertex][i]&&!visited[i]){
           visited[i]=true;
              enqueue(i);
       } 
       }
    }
}
void main(){
    int n;
    printf("enter number of vertices in graph\n");
    scanf("%d",&n);
    printf("enter adjacency matrix\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    printf("enter starting vertex \n");
    int startingVertex;
    scanf("%d",&startingVertex);
    
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    bfs(startingVertex,n);
}
