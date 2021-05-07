#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>
#include <limits.h>
#include "Parameter.h"
#include "load_data.h"


#define BLANK " "
//Loading data from a file into a program

pNODE loadNode(char filename[]){
	double lat, lgt;
	char* str;
	char row[200];
	int ID;
	pNODE pnode=(pNODE) malloc(sizeof(Node)); 		//通过malloc为指针pnode申请空间 
	pNODE head_pNode=pnode;		//初始化头指针
	pnode->node_id=0;  
    pnode->node_lat=0;
    pnode->node_lgt=0;
    pnode->Nextnode=NULL;
	FILE* file;
	file = fopen(filename,"r");
    if(file == NULL)
    {
        printf("\nFailed to read file, press any key to exit"); 
        getch();//不回显函数     
		return NULL;
    }
	fgets(row, 200, file);		//读取文件	
	str = strtok(row,BLANK);	//strtok()用来将字符串分割成一个个片段
    
    while (1)
	{
    	fgets(row, 200, file);
    	str = strtok(row,BLANK);
    	if(strcmp(str,"<node") == 0)	//找到<node那部分的数据 
		{
    	break;
		} 
    }
                                        //向链表的节点中赋值 
    while (strcmp("<node",str) == 0) {
        pNODE node_new=(pNODE) malloc(sizeof(Node)); 
        str = strtok(NULL, BLANK);
        sscanf(str,"id=%d",&ID);
        node_new -> node_id = ID;
        
        str = strtok(NULL, BLANK);
        sscanf(str,"lat=%lf",&lat);
        node_new -> node_lat =lat;
        
        str = strtok(NULL, BLANK);
        sscanf(str,"lon=%lf",&lgt);
        node_new -> node_lgt =lgt;   
	
        fgets(row, 200, file);
        str = strtok(row,BLANK);
        pnode -> Nextnode = node_new;
        pnode=node_new;
	}
    fclose(file);
    return head_pNode;
}

pPATH loadPath(char filename[]){
    char* str;
    char row[200];
	double longness;
	int node_first, node_second, ID;
	pPATH pPath=(pPATH) malloc(sizeof(Path)); 		//通过malloc为指针pPath申请空间 
	pPATH head_pPath=pPath;		//初始化头指针
	pPath->path_id=0;      
    pPath->first_node=0;
    pPath->second_node=0;
    pPath->length=0;
    pPath->Nextpath=NULL;
    FILE* file = fopen(filename,"r");
    if(file == NULL)
    {
        printf("\nFailed to read file, press any key to exit"); 
        getch();//不回显函数     
		return NULL;
    }
    
    fgets(row, 200, file);	  //neglect the first line	
    fgets(row, 200, file);
    str = strtok(row,BLANK);
    
    //向链表的节点中赋值                          
    while (strcmp("<link",str) == 0) {
        pPATH path_new=(pPATH) malloc(sizeof(Path)); 
        str = strtok(NULL, BLANK);
        sscanf(str,"id=%d",&ID);
		path_new->path_id=ID;

        str = strtok(NULL, BLANK);
        sscanf(str,"node=%d",&node_first);
		path_new->first_node=node_first;

        str = strtok(NULL, BLANK);
        sscanf(str,"node=%d",&node_second);
        path_new->second_node=node_second;
        
        str = strtok(NULL, BLANK);
        str = strtok(NULL, BLANK);
        sscanf(str,"length=%lf",&longness);
        path_new->length=longness;
        pPath ->Nextpath = path_new;
        pPath=path_new;
        fgets(row, 200, file);
        str = strtok(row,BLANK);
    }
    fclose(file);
    return head_pPath;
}

pMyGraph produceGraph(pPATH path_head,pNODE node_head){
  	pPATH path_p=path_head;
  	pNODE node_p=node_head;
  	pMyGraph graph_p=(pMyGraph)malloc(sizeof(MyGraph));
  	int counteri, counterj, counterx;
  	int fir_n, sec_n;
  	graph_p->node_number=0;
  	if(path_p==NULL||node_p==NULL){
  		return NULL;
	  }
    while (node_p->Nextnode!=NULL) {
        graph_p->node_number=graph_p->node_number+1;	//计算有多少个node 
		node_p=node_p->Nextnode;
    }
	graph_p->edge_number=0;

    while (path_p->Nextpath!=NULL) {
        graph_p->edge_number=graph_p->edge_number+1;	//计算有多少条path 
		path_p=path_p->Nextpath;
    }
    for ( counteri=0; counteri<graph_p->node_number; counteri++)
	{
        for ( counterj=0; counterj<graph_p->node_number; counterj++) 
		{
            if (counterj!=counteri) 
			{
                graph_p-> edges[counteri][counterj]=INT_MAX;	//距离为INF说明两个node之间没有直接相连的路 
            }
            else 
			{	
				graph_p-> edges[counteri][counterj]=0;		//相同的node间距离为零 
			}
        }
    }
    path_p=path_head;  //为什么要写成path_p=path_head->Nextpath?
    for ( counterx=0; counterx<graph_p->edge_number; counterx++) {
    	//寻找first_node对应的index 
      	pNODE node_p2=node_head;	//为什么马成晓要写pNODE node_p2=node_head->Nextnode
		int index=0,aindex=-1,bindex=-1;	//如果aindex或bindex后面依然是-1说明没找到对应的点 
    	while (node_p2->Nextnode!=NULL) 
	   	{
    	    if (node_p2->node_id==path_p->first_node) 
			{
				aindex=index;
			}
    	    node_p2=node_p2->Nextnode;
    	    index++;
    	}
    	if (node_p2->node_id==path_p->first_node)
		{
    	    aindex=index;
    	}
		//寻找second_node对应的index 
		node_p2=node_head;	//为什么马成晓要写pNODE node_p2=node_head->Nextnode
		index=0;
    	while (node_p2->Nextnode!=NULL) 
		{
    	    if (node_p2->node_id==path_p->second_node) 
			{
				bindex=index;
			}
    	    node_p2=node_p2->Nextnode;
    	    index++;
    	}
    	if (node_p2->node_id==path_p->second_node)
		{
    	    bindex=index;
    	}
		//给图像数组赋值 
        graph_p->edges[aindex][bindex]=path_p->length;
        graph_p->edges[bindex][aindex]=path_p->length;
		path_p=path_p->Nextpath;
    }	 
 	return graph_p; 
}


