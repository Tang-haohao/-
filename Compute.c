#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define NUM 7
 
//typedef struct MGraph		/* 邻接表存储结构 */
//{
//     int edges[NUM][NUM];
//     int n;  //node number
//	 int e;	 //edge	number
//} MGraph;

typedef struct MyGraph		/* 邻接表存储结构 */
{
     int edges[MAX][MAX];
     int node_number;  //node number
	 int edge_number;  //edge number
} MyGraph;

typedef MyGraph* pMyGraph; 

 
//MGraph *build_mgraph();
void Dijkstra(MGraph *mgraph, int v);
void Dispath(int dis[],int pre[],int visited[], int n, int v);
void Ppath(int path[], int i, int v);
int main(void)
{
     MGraph *mgraph;
 
//     printf("\n*************************************************************\n");
//     printf("该图的矩阵表示为:\n");
//     mgraph=build_mgraph();
     printf("\n*************************************************************\n");
     printf("dijkstra 算法:\n");
     Dijkstra(mgraph,0);
     printf("\n*************************************************************\n");
     
     return 0;
}
 
//MGraph *build_mgraph()
//{
//     int i,j;
//     int num_e=0;
//     MGraph *mgraph=(MGraph *)malloc(sizeof(MGraph));
//     int matrix[NUM][NUM]={{0,4,6,6,INT_MAX,INT_MAX,INT_MAX},
//			   {INT_MAX,0,1,INT_MAX,7,INT_MAX,INT_M      AX},
//			   {INT_MAX,INT_MAX,0,INT_MAX,6,4,INT_MAX},
//			   {INT_MAX,INT_MAX,2,0,INT_MAX,5,INT_MAX},
//			   {INT_MAX,INT_MAX,INT_MAX,INT_MAX,0,INT_MAX,6},
//			   {INT_MAX,INT_MAX,INT_MAX,INT_MAX,1,0,8},
//			   {INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,0}};
//     for(i=0;i<NUM;i++)
//     {
//	  for(j=0;j<NUM;j++)
//	  {
//	       mgraph->edges[i][j]=matrix[i][j];
//	       if(matrix[i][j]!=0 && matrix[i][j]!=INT_MAX)
//		    num_e++;
//	  }
//     }
//     mgraph->n=NUM;
//     mgraph->e=num_e;
// 
//     printf("node=%d;edges=%d\n",mgraph->n,mgraph->e);
//     for(i=0;i<NUM;i++)
//     {
//	  for(j=0;j<NUM;j++)
//	  {
//	       if(mgraph->edges[i][j]!=INT_MAX)
//		    printf("%3d",mgraph->edges[i][j]);
//	       else
//		    printf("%3c",'&');
//	  }
//	  printf("\n");
//     }
// 
//     return mgraph;
//}

pMyGraph mgraph=produceGraph(pPATH path_head,pNODE node_head);

void Dijkstra(MGraph *mgraph, int v)
{  
     int icounter,jcounter;
     int tk;
     int dijkstra_min;
     int num=mgraph->node_number;
     int dijkstra[num];
     int selected[num]={0};
     int pre[num];	//到达终点前经过的最近的一个点 

     selected[v]=1;
     for(icounter=0;icounter<mgraph->node_number;icounter++)
     {
	  dijkstra[icounter]=mgraph->edges[v][icounter];	//先给dijkstra[icounter]数组一个初始的模糊最短路径值 
	  pre[icounter]=v;	//经过的前一个点v 
     }
        
     for(icounter=0;icounter<mgraph->node_number;icounter++)
     {
	  dijkstra_min=INF;
	  for(jcounter=0;jcounter<mgraph->node_number;jcounter++)
	  {  
	       if(!selected[jcounter] && dijkstra[jcounter]<dijkstra_min)
	       {
		    dijkstra_min=dijkstra[jcounter];
		    tk=jcounter;
	       }
	  }
	  selected[tk]=1;
	  for(jcounter=0;jcounter<mgraph->n;jcounter++)
	  {
	       if(!selected[jcounter] && mgraph->edges[tk][jcounter]!=INF && dijkstra[tk]+mgraph->edges[tk][jcounter] < dijkstra[jcounter])
	       {
		    dijkstra[jcounter]=dijkstra[tk]+mgraph->edges[tk][jcounter];
		    pre[jcounter]=tk;
	       }
	  }
     }  
     Dispath(dijkstra,pre,selected,mgraph->node_number,v);
}
 
void Dispath(int dis[],int pre[],int visited[], int n, int v)
{
     int i;
     for(i=0;i<n;i++)
     {
	  if(visited[i])
	  {
	       printf("从%d到%d的最短路径长度为:%d\t路径为:",v,i,dis[i]);
	       printf("%d, ",v);
	       Ppath(pre,i,v);
	       printf("%d\n",i);
	  }
	  else
	       printf("no path\n");
     }
}
void Ppath(int pre[], int i, int v)
{
     int k;
     k=pre[i];
     if(k==v)
	  return;
     Ppath(pre,k,v);
     printf("%d, ",k);
}

