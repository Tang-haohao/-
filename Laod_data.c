#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>

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
        printf("Failed to read file, press any key to exit\n"); 
        getch();//不回显函数     
        exit(1);
    }
	fgets(row, 200, file);		//读取文件	
	str = strtok(row,BLANK);	//strtok()用来将字符串分割成一个个片段
    
    while (1)
	{
    	fgets(row, 200, file);
    	str = strtok(line,BLANK);
    	if(strcmp(str,"<node") == 0)	//找到<node那部分的数据 
		{
    	break;
		} 
    }
    
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
        str = strtok(line,BLANK);
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
        printf("Failed to read file, press any key to exit\n"); 
        getch();//不回显函数     
        exit(1);
    }
    
    fgets(row, 200, file);	  //neglect the first line	
    fgets(row, 200, file);
    
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
        sscanf(token,"length=%lf",&longness);
        path_new->length=longness;
        pPath ->Nextpath = path_new;
        pPath=path_new;
        fgets(row, 200, file);
        str = strtok(line,BLANK);
    }
    fclose(file);
    return head_pPath;
}






pMyGraph produceGraph(pPATH path_head,pNODE node_head){
  	pPATH path_p=path_head;
  	pNODE node_p=node_head;
  	pMyGraph graph_p=(pMyGraph)malloc(sizeof(MyGraph));
  	int counteri, counterj;
  	graph_p->node_number=0;
    while (node_p->Nextnode!=NULL) {
        graph_p->node_number=graph_p->node_number+1;
        node=node->nextNode;
    }
	graph_p->edge_number=0;	
    while (path_p->Nextpath!=NULL) {
        graph_p->edge_number=graph_p->edge_number+1;
        path_p=path_p->Nextpath;
    }
    for ( counteri=0; counteri<graph_p->node_number; counteri++) {
        for ( counterj=0; counterj<graph_p->node_number; counterj++) {
            if (counterj!=counteri) {
                graph_p-> edges[counteri][counterj]=INF;
            }
            else {
				graph_p-> edges[counteri][counterj]=0;
			}
        }
    }
	
}







Graph* createGraph(Node*headNode,Path*headPath){
    Graph* agraph=(Graph*)malloc(sizeof(Graph));
    int num=0;
    Node*node=headNode;
    Path*path=headPath;
    while (node->nextNode!=NULL) {
        num++;
        node=node->nextNode;
    }
    agraph->vexnum=num;
    num=0;
    while (path->nextPath!=NULL) {
        num++;
        path=path->nextPath;
    }
    agraph->edgnum=num;
    //initiate the matrix
    int i, j; 
    for ( i=0; i<agraph->vexnum; i++) {
        for ( j=0; j<agraph->vexnum; j++) {
            if (i==j) {
                agraph->matrix[i][j]=0;
            }
            else agraph->matrix[i][j]=INF;
        }
    }
    path=headPath->nextPath;
    //make the matrix be the lenth
    for ( i=0; i<agraph->edgnum; i++) {
        int fir=getPosition(path->nodeA,headNode);
        int sec=getPosition(path->nodeB,headNode);
        agraph->matrix[fir][sec]=path->length;
        agraph->matrix[sec][fir]=path->length;
        path=path->nextPath;
    }
    return agraph;
}

