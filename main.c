#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include "Compute.h"
#include "load_data.h"
#include "Parameter.h"
#include "auxiliary_function.h"
#include "drawgraph.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//
int main(int argc, char *argv[]) {
	int fir_id,sec_id;
	int fir_index,sec_index;
	pNODE pointer_node=loadNode("Final_Map.map");	//将文件中的数据存入链表，并得到头指针 
	pPATH pointer_path=loadPath("Final_Map.map");  
	pMyGraph pointer_graph=produceGraph(pointer_path,pointer_node);
  	pNODE pointer_Node=pointer_node;
	pPATH pointer_Path=pointer_path; 
	while(1)
	{
		printf("\nPlz input the id of first node: ");	 
    	scanf("%i",&fir_id);				
		fir_index=findindex(fir_id,pointer_node);
		if(fir_index==-1){						//检测用户是否输入了正确的id 
//			printf("\nWithout this node, press any key to re-enter\n");
//			getch();
//			continue;
			printf("\nInput error, press any key to exit\n");
			getch();
			return 0;
		}
		break;
	}
	while(1){
    	printf("\nPlz input the id of second node: ");
    	scanf("%i",&sec_id);
		sec_index=findindex(sec_id,pointer_node);
		if(sec_index==-1){					//检测用户是否输入了正确的id 
//			printf("\nWithout this node, press any key to re-enter\n");
//			getch();
//			continue;
			printf("\nInput error, press any key to exit\n");
			getch();
			return 0;
		}
		break;
	}	
	Dijkstra(pointer_graph, fir_index, sec_index);		//迪杰斯特拉算法 
	drawgraph(pointer_Path,pointer_Node);	//画出minerva上提供的图 
	return 0;
}


