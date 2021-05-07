#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Parameter.h"
#include "load_data.h"
#include "auxiliary_function.h"

//通过node的id寻找node的序号
int findindex(int id_node,pNODE pnode_head){
    pNODE anode=pnode_head;
    if(anode==NULL){
    	return -1;
	}
    int counter=0;
    while (anode->Nextnode!=NULL) {
        if (anode->node_id==id_node)	//遍历所有的node，找出nodeid相同的点 
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
//通过node的序号寻找对应的node 
pNODE findnode(int index,pNODE pnode_head){		    
	pNODE anode=pnode_head;
	if(anode==NULL||index<0){
		return NULL;
	}
//	int num1,num2;
//    while(1){
//    	num1=anode->node_id;
//    	num2=findindex(num1,pnode_head);		//遍历所有的node，找出node的序号相同的点
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


