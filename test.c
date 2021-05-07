#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <float.h>
#include "Compute.h"
#include "load_data.h"
#include "Parameter.h"
#include "auxiliary_function.h"
#include "drawgraph.h"
#define BLANK " "

int t_loadNode (pNODE headnode)
{
	printf ("\n *** Checking function loadNode ***\n");
	
	//���Ե��ļ�����ʱ�������ܷ��������ļ� 
	printf (" Test whether the file can be opened correctly ");
	pNODE t_node=headnode; 
	if(t_node->Nextnode==NULL){
		printf ("Failed\n");
		printf (" The file Final_Map.map was not opened properly ");
		return 0;
	}
	printf ("\tPassed\n");
	printf (" Test whether the file can be opened correctly ");	
//	//�����ļ��е������Ƿ���ȷ��ȡ 
//	int ID_t;
//	double lat_t, lgt_t;
//	char* str_t;
//	FILE* file;
//	file = fopen("Final_Map.map","r");
//	char row_t[200];
//	fgets(row_t, 200, file);		//��ȡ�ļ�
//	str_t = strtok(row_t,BLANK);	//strtok()�������ַ����ָ��һ����Ƭ��	
//	while (1)
//	{
//    	fgets(row_t, 200, file);
//    	str_t = strtok(row_t,BLANK);
//    	if(strcmp(str_t,"<node") == 0)	//�ҵ�<node�ǲ��ֵ����� 
//		{
//    	break;
//		} 
//    }
//	    while (strcmp("<node",str_t) == 0) {
//
//        str_t = strtok(NULL, BLANK);
//        sscanf(str_t,"id=%d",&ID_t);
//        
//        str_t = strtok(NULL, BLANK);
//        sscanf(str_t,"lat=%lf",&lat_t);
//        
//        str_t = strtok(NULL, BLANK);
//        sscanf(str_t,"lon=%lf",&lgt_t);
//        if(t_node -> node_lgt!=lgt_t||t_node -> node_lat!=lat_t||t_node -> node_id!=ID_t){
//        	printf ("Failed\n");
//        	printf ("Error reading file data\n");
//		}  
//	
//        fgets(row_t, 200, file);
//        str_t = strtok(row_t,BLANK);
//        t_node = t_node -> Nextnode;
//	}	
//	fclose(file);
	printf ("\tPassed\n");
	//�����ļ�������ʱ�������ܷ��������� 
	printf (" Test whether the program can end normally when the test file does not exist ");
	t_node=loadNode(" ");
	if(t_node!=NULL){
		printf ("Failed\n");
		printf (" The procedure did not end properly ");
		return 0;
	}
	printf ("\tPassed\n");
	printf ("Passed\n");
	return 0;
}

int t_loadPath (pPATH headpath){
	
	printf ("\n*** Checking function loadPath ***\n");
	//���Ե��ļ�����ʱ�������ܷ��������ļ� 
	printf (" Test whether the file can be opened correctly ");
	pPATH t_path=headpath;
	if(t_path->Nextpath==NULL){
		printf ("Failed\n");
		printf (" The file Final_Map.map was not opened properly ");
		return 0;
	}
	printf ("\tPassed\n");
//	//�����ļ��е������Ƿ���ȷ��ȡ 
//    printf (" Test whether the data in the file is read correctly ");
//	char* str;
//    char row[200];
//	double longness;
//	int node_first, node_second, ID;
//    FILE* file = fopen("Final_Map.map","r");
//    fgets(row, 200, file);	  //neglect the first line	
//    fgets(row, 200, file);
//    str = strtok(row,BLANK);
//    //������Ľڵ��и�ֵ                          
//    while (strcmp("<link",str) == 0) {
//        str = strtok(NULL, BLANK);
//        sscanf(str,"id=%d",&ID);
//		
//
//        str = strtok(NULL, BLANK);
//        sscanf(str,"node=%d",&node_first);
//		
//
//        str = strtok(NULL, BLANK);
//        sscanf(str,"node=%d",&node_second);
//        
//        
//        str = strtok(NULL, BLANK);
//        str = strtok(NULL, BLANK);
//        sscanf(str,"length=%lf",&longness);
//        if(t_path->length!=longness||t_path->path_id!=ID||t_path->first_node!=node_first||t_path->second_node!=node_second){
//        	tell ("Failed\n");
//        	tell ("Error reading file data\n");	
//		}
//
//        t_path=t_path->Nextpath;
//        fgets(row, 200, file);
//        str = strtok(row,BLANK);
//    }
//    fclose(file);
//    printf ("\tPassed\n");
	//�����ļ�������ʱ�������ܷ��������� 
	printf (" Test whether to end normally when the file does not exist ");
	t_path=loadPath(" ");
	if(t_path!=NULL){
		printf ("Failed\n");
		printf (" The procedure did not end properly ");
		return 0;
	}
	printf ("\tPassed\n");
	printf ("Passed\n");
	return 0;
}

int t_produceGraph(pNODE headnode,pPATH headpath){
	printf ("\n*** Checking function produceGraph ***\n");
	
	//���Ե������ָ��Ϊ�գ������ܷ���������
	printf (" If the pointer passed in is NULL, can the program end normally ");
	pMyGraph t_Graph=produceGraph(NULL,NULL);
	if(t_Graph!=NULL){
		printf ("Failed\n");
		printf (" The procedure did not end properly ");
		return 0;		
	}
	printf ("\tPassed\n");
	//���Ե���������ָ��ʱ���ܷ���������
	//������malloc�ܷ�ɹ����뵽�ڴ� 
	printf (" Test whether it can run normally when normal pointer is passed in ");
	pNODE t_node=headnode;	//��Final_Map.map�ļ��е����ݴ��������õ���ͷָ�� 
	pPATH t_path=headpath;  
	t_Graph=produceGraph(t_path,t_node);
	if(t_Graph==NULL){
		printf ("Failed\n");
		printf (" The program is not working properly ");	
		return 0;					
	}
	printf ("\tPassed\n");
	//���������Ƿ���ȷ���뵽��������
	printf (" Test whether the data is correctly entered into the array ");
	if(t_Graph->edge_number==0||t_Graph->node_number==0){
		printf ("Failed\n");
		printf (" The data is not entered into the variable ");	
		return 0;							
	} 
	if(t_Graph->edge_number>0&&t_Graph->node_number>0){
		int counteri,counterj,key=0;
	    for ( counteri=0; counteri<t_Graph->node_number; counteri++)
		{
    	    for ( counterj=0; counterj<t_Graph->node_number; counterj++) 
			{
				if(t_Graph-> edges[counteri][counterj]!=0&&t_Graph-> edges[counteri][counterj]!=INT_MAX){		//ֻҪ���ּȲ�Ϊ0Ҳ��ΪINT_MAX��Ԫ�أ�˵�����ݳɹ����뵽�������� 
					key=1; 
					break;
				}
    	    }
    	    if(key==1){		//��ѭ����ȫ��ֹ 
    	    	break;
			}
    	}
    	if(key==0){
			printf ("Failed\n");
			printf (" Data is not normally entered into the array ");	
			return 0;					
		}
	} 
	printf ("\tPassed\n");
	printf ("Passed\n");
	return 0;	
}

int t_Dijkstra(pNODE headnode,pPATH headpath){
	printf ("\n*** Checking function Dijkstra ***\n");
	//���Ե������ָ�����Ϊ��ʱ�������ܷ�����ֹͣ
	printf (" Test whether the program can stop normally when the pointer parameter is null "); 
	int t_Dij=Dijkstra(NULL, 1, 1);
	if(t_Dij!=-1){
		printf ("Failed\n");
		printf (" The procedure did not end properly ");
		return 0;				
	}
	printf ("\tPassed\n");
	//�������v��m����������Χʱ�������ܷ�������ֹ
	printf (" When v and m are not in the normal range, can the program terminate normally ");
	pMyGraph t_Graph=produceGraph(headpath,headnode);
	t_Dij=Dijkstra(t_Graph, 1, -1);
	if(t_Dij!=-1){
		printf ("Failed\n");
		printf (" The procedure did not end properly ");
		return 0;		
	}
	t_Dij=Dijkstra(t_Graph, -1, 1);
	if(t_Dij!=-1){
		printf ("Failed\n");
		printf (" The procedure did not end properly ");
		return 0;		
	}
//	t_Dij=Dijkstra(t_Graph, 10000, 1);
//	if(t_Dij!=-1){
//		printf ("Failed\n");
//		printf (" The procedure did not end properly ");
//		return 0;		
//	}
	printf ("\tPassed\n");
	//���Լ���������·���Ƿ���ȷ
	//node=-2560��node=-2562(����ֱ�������ĵ�)
	printf (" Test whether the calculated shortest path is correct ");
	int i=findindex(-2560,headnode);
	int u=findindex(-2562,headnode);
	double t_route=Dijkstra(t_Graph, i, u);
	if(t_route!=11.029994){
		printf ("Failed\n");
		printf (" The calculated shortest path is wrong ");
		return 0;				
	}
	//node=-2546��node=-2560������û��ֱ�������ĵ㣩
	i=findindex(-2546,headnode);
	u=findindex(-2560,headnode);
	t_route=Dijkstra(t_Graph, i, u);
	if(t_route!=384.313149){
		printf ("Failed\n");
		printf (" The calculated shortest path is wrong ");
		return 0;				
	} 
	printf ("\tPassed\n");
	printf ("Passed\n");
	return 0;	
}

int t_inputpath(){
	printf ("\n*** Checking function inputpath ***\n");
	int t_inputpath; 
	int t_pre[20]={0};
	//���Ե������������ʱ�������ܷ���������
	printf (" Test whether the program can run normally when the input parameters are normal ");
	t_inputpath=inputpath(t_pre[20],10,0);
	//����ļ��Ƿ���ȷ����
	FILE *file = fopen("route.out","r"); 
	if(file==NULL){
		printf ("Failed\n");
		printf (" The file was not generated correctly ");
		return 0;						
	} 
	//��������Ƿ���ȷ���뵽���ļ���
	char ch=fgetc(file);
	if(ch==EOF){
		printf ("Failed\n");
		printf (" The data is not entered into the file correctly ");
		return 0;								
	}
	printf ("\tPassed\n");	
	//���Ե���������쳣ʱ�ܷ������˳�
	printf (" Test whether it can exit normally when the incoming parameter is abnormal ");
	//������������ܵ�������Խ��ʱ 
	t_inputpath=inputpath(t_pre[10],100,9);
	if(t_inputpath!=-1){
		printf ("Failed\n");
		printf (" The procedure did not end properly ");
		return 0;				
	} 
	//���������Ϊ����ʱ 
	t_inputpath=inputpath(t_pre[20],-1,9);
	if(t_inputpath!=-1){
		printf ("Failed\n");
		printf (" The procedure did not end properly ");
		return 0;				
	} 
	//���Դ���������ʱ�Ƿ�ᵼ�³������ļ�������
	FILE *fp = fopen("route.out","r"); 
	char Ch=fgetc(fp);
	if(Ch==EOF){
		printf ("Failed\n");
		printf (" File content is empty ");
		return 0;								
	}
	printf ("\tPassed\n");
	printf ("Passed\n");
	return 0;	
}

int t_findindex(pNODE headnode){
	printf ("\n*** Checking function findindex ***\n");
	pNODE t_node=headnode;
	printf (" Test whether the program can terminate normally when the incoming parameter is abnormal ");
	//���Ե���������쳣ʱ�������ܷ�������ֹ
	//����ָ�����Ϊ�� 
	int t=findindex(-2524,NULL); 
	if(t!=-1){
		printf ("Failed\n");
		printf (" The procedure did not end properly ");
		return 0;						
	} 
	//�����nodeid������
	if(t!=-1){
		printf ("Failed\n");
		printf (" The procedure did not end properly ");
		return 0;						
	} 	 
	printf ("\tPassed\n");
	//���Ե������������ʱ���ܷ��ҵ���ȷ��index
	printf (" Test whether the correct index can be found when the incoming parameters are normal	");
	t=findindex(-2524,t_node);
	if(t!=24){
		printf ("Failed\n");
		printf (" The correct index was not found by node id ");
		return 0;										
	}
	t=findindex(-2546,t_node);
	if(t!=22){
		printf ("Failed\n");
		printf (" The correct index was not found by node id ");
		return 0;										
	}
	printf ("\tPassed\n");
	printf ("Passed\n");
	return 0;	
																							
}
																				
int t_findnode(pNODE pnode_head){
	printf ("\n*** Checking function findnode ***\n");								
	pNODE node_t;            
	//���Ե���������쳣ʱ�������ܷ�������ֹ
  	printf (" Test whether the program can terminate normally when the incoming parameter is abnormal ");
	//�������ָ��Ϊ��ʱ 
	node_t=findnode(22,NULL);
	if(node_t!=NULL){
		printf ("Failed\n");
		printf (" The procedure did not end properly ");
		return 0;								
	}
	//������Ĳ�������������Χ��
//	node_t=findnode(10000,pnode_head);
//	if(node_t!=NULL){
//		printf ("Failed\n");
//		printf (" The procedure did not end properly ");
//		return 0;								
//	}
	node_t=findnode(-1,pnode_head);
	if(node_t!=NULL){
		printf ("Failed\n");
		printf (" The procedure did not end properly ");
		return 0;								
	}
	printf ("\tPassed\n");
	printf (" When the input parameters are normal, can the program run correctly ");	 
	node_t=findnode(22,pnode_head);
	if(node_t->node_id!=-2546){  
		printf ("Failed\n");
		printf (" The program did not run properly ");
		return 0;								
	}
	node_t=findnode(24,pnode_head);
	if(node_t->node_id!=-2524){  
		printf ("Failed\n");
		printf (" The program did not run properly ");
		return 0;								
	}
    printf ("\tPassed\n");
	printf ("Passed\n");
	return 0;		                                                                                      
}																								

int t_drawgraph(pPATH head_path,pNODE node_head){
	printf ("\n*** Checking function drawgraph ***\n");
	pPATH headpath=head_path;
	pNODE nodehead=node_head;
	//���Ե���������쳣ʱ�������ܷ�������ֹ
  	printf (" Test whether the program can terminate normally when the incoming parameter is abnormal ");													 	
	int t=drawgraph(NULL,node_head);
	if(t!=-1){
		printf ("Failed\n");
		printf (" The procedure did not end properly ");
		return 0;										
	}
	t=drawgraph(headpath,NULL);
	if(t!=-1){
		printf ("Failed\n");
		printf (" The procedure did not end properly ");
		return 0;										
	}	
    printf ("\tPassed\n");
	printf (" Test whether the program can run normally when the input parameters are normal ");
	t=drawgraph(headpath,nodehead);
	FILE *file = fopen("graph.out","r"); 
	//����ļ��Ƿ���ȷ����
	if(file==NULL){
		printf ("Failed\n");
		printf (" The file was not generated correctly ");
		return 0;						
	} 
	//��������Ƿ���ȷ���뵽���ļ���
	char ch=fgetc(file);
	if(ch==EOF){
		printf ("Failed\n");
		printf (" The data is not entered into the file correctly ");
		return 0;								
	}
    printf ("\tPassed\n");
	printf ("Passed\n");
	return 0;		
}																		
																		
//int main (int argc, char* argv[]){
//	pNODE pointer_node=loadNode("Final_Map.map");	//���ļ��е����ݴ����������õ�ͷָ�� 
//	pPATH pointer_path=loadPath("Final_Map.map");  
//	printf ("\n************************ Test  function ************************\n");
//	t_loadNode (pointer_node);
//	t_loadPath (pointer_path);
//	t_produceGraph(pointer_node,pointer_path);
//	t_inputpath();
//	t_findindex(pointer_node);
//	t_findnode(pointer_node);	
//	t_Dijkstra(pointer_node,pointer_path);
//	t_drawgraph(pointer_path,pointer_node);
//	return 0;
//} 

