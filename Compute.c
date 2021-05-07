#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Parameter.h"
#include "load_data.h"
#include "auxiliary_function.h"
#include "Compute.h"
#define NUM 7


double Dijkstra(pMyGraph mgraph, int v, int m)
{  
     int icounter,jcounter;
     int tk=v;
     double dijkstra_min;
     int num=mgraph->node_number;
     double dijkstra[num];
     int selected[5000]={0};
     int pre[num];	//到达终点前经过的最近的一个点 
     selected[v]=1;
     if(mgraph==NULL){
     	return -1;
	 }
	 if(v>=mgraph->node_number||m>=mgraph->node_number||v<0||m<0){
	 	return -1;
	 }
     for(icounter=0;icounter<mgraph->node_number;icounter++)
     {
	  dijkstra[icounter]=mgraph->edges[v][icounter];	//先给dijkstra[icounter]数组一个初始的模糊最短路径值 
	  pre[icounter]=v;	//经过的前一个点都是v 
     }
        
     for(icounter=0;icounter<mgraph->node_number;icounter++)
     {
	  dijkstra_min=INT_MAX;  	//最开始路与路间的距离都初始化为INT_MAX
	  for(jcounter=0;jcounter<mgraph->node_number;jcounter++)
	  {  
	       if(!selected[jcounter] && dijkstra[jcounter]<dijkstra_min)	//遍历每一条path，并找出node与node间最短路径 
	       {
		    dijkstra_min=dijkstra[jcounter];
		    tk=jcounter;
	       }
	  }
	  selected[tk]=1;	//已经得出最短路径的点要标记为1 
	  for(jcounter=0;jcounter<mgraph->node_number;jcounter++)
	  {
	       if(!selected[jcounter] && mgraph->edges[tk][jcounter]!=INT_MAX && dijkstra[tk]+mgraph->edges[tk][jcounter] < dijkstra[jcounter])
	       {
		    dijkstra[jcounter]=dijkstra[tk]+mgraph->edges[tk][jcounter];
		    pre[jcounter]=tk;	//将前一个经过的点记录为tk 
	       }
	  }
     }  
	 Dispath(dijkstra,pre,selected,mgraph->node_number,v,m);
	 inputpath (pre,m,v); 
	 return dijkstra[m];
}
 
int Dispath(double dis[],int pre[],int selected[], int n, int v, int m)
{
     int i,y=0;
     for(i=0;i<n;i++)
     {
	  if(selected[i])
	  {
	  	if(i==m)
		{
	       printf("从%d(序号)到%d(序号)的最短路径长度为: %lf\n路径为(序号): ",v,i,dis[i]);
	       printf("%d, ",v);
	       Ppath(pre,i,v);	//打印路径 
	       printf("%d\n",i);
	       y=1;
	   }
	  }
     }
     if(y==0){
     	printf("no path");
	 }
	 return 0;
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

int inputpath (int pre[],int i,int v){
	int len=sizeof(pre);
	if(i>=len||v>=len||i<0||v<0){
		return -1;
	}
	FILE *file = fopen("route.out","w");   	//以只写的方式打开文件，每次打开都会清空文件原有内容 
	pNODE pnode_head=loadNode("Final_Map.map");   
    int route=i;   
    double a_Latitude,a_longtitude;   
    while (1) {
        pNODE a_node=findnode(route,pnode_head);
        a_Latitude=a_node->node_lat;
        a_longtitude=a_node->node_lgt;
        fprintf(file," %lf %lf\n",a_longtitude,a_Latitude);		//将数据输入文件 
        if (route==v) {		//当route=v时说明已经重新回到起点 
            pNODE a_node=findnode(v,pnode_head);
        	a_Latitude=a_node->node_lat;
       		a_longtitude=a_node->node_lgt;
            fprintf(file," %lf %lf\n",a_longtitude,a_Latitude);
            break;
    	}
        route=pre[route];
    }
    fclose(file);
    return 0;
}   

