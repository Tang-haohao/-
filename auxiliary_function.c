#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Parameter.h"
#include "load_data.h"
#include "auxiliary_function.h"

//ͨ��node��idѰ��node�����
int findindex(int id_node,pNODE pnode_head){
    pNODE anode=pnode_head;
    if(anode==NULL){
    	return -1;
	}
    int counter=0;
    while (anode->Nextnode!=NULL) {
        if (anode->node_id==id_node)	//�������е�node���ҳ�nodeid��ͬ�ĵ� 
		{
			 return counter;
		}
        anode=anode->Nextnode;
        counter++;
    }
    if (anode->node_id==id_node){
        return counter;
    }
    return -1;
}
//ͨ��node�����Ѱ�Ҷ�Ӧ��node 
pNODE findnode(int index,pNODE pnode_head){		    
	pNODE anode=pnode_head;
	if(anode==NULL||index<0){
		return NULL;
	}
//	int num1,num2;
//    while(1){
//    	num1=anode->node_id;
//    	num2=findindex(num1,pnode_head);		//�������е�node���ҳ�node�������ͬ�ĵ�
//    	if(anode==NULL){
//    		break;
//		}
//		if(index==num2){
//    		break;
//		}
//		else{
//			anode=anode->Nextnode;
//		}
//	}
//    return anode;
    int i;
	for ( i=0; i<index; i++) {
        anode=anode->Nextnode;
    }
    return anode;

}


