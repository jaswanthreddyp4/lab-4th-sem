//if there is edge between 0 and 1 with weight 12 enter as 0 1 12
//if there is edge between 0 and 2 with weight 20 enter as 0 2 20  and soo on.....
//to end entering enter -1 -1 n(any value)

#include<stdio.h>
#define infinite 1000
int n;
void dijkstra(int adjacency[][n],int visited[n],int fin[n],int source)
{
    int temp,temp1;
     for(int i=0;i<n;i++)
     {
        visited[source]=1;
        int min = 1000;
        for(int j=0;j<n;j++)
        {
            if(adjacency[source][j]!=0 && adjacency[source][j]<=fin[j] && !visited[j])
            {
              temp1 = adjacency[source][j] + fin[source];
                if(temp1<=fin[j])
                   fin[j] = temp1;
                if(fin[j]<=min)
                {
                    min = fin[j];
                    temp=j;
                }
            }
        }
        source = temp;
     }   
}
void main()
{
    printf("Enter the number of vertices\n");
    scanf("%d",&n);
    int adjacency[n][n];
    int p=0,q=0,w;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            adjacency[i][j]=0;
        }
    }
    while(p!=-1 && q!=-1)
    {
        printf("\nEnter the edges and their weights : ");
        scanf("%d %d %d",&p,&q,&w);
        adjacency[p][q] = w;
        adjacency[q][p] = w;
    }
    int source;
    printf("Enter the source of the graph\n");
    scanf("%d",&source);
    int visited[n],fin[n];
    for(int i=0;i<n;i++)
    {
       visited[i]=0;
       if(i==source)
          fin[i]=0;
       else
         fin[i]=infinite;
    }
    dijkstra(adjacency,visited,fin,source);
    printf("The costs for the each from source is\n");
    for(int i=0;i<n;i++)
      printf("The minimum cost required for reaching %d from %d is %d\n",i,source,fin[i]);
    printf("\n");
}
