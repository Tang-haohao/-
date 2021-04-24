#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Parameter.h"
#include "load_data.h"
int findindex(int id_node){
	pNODE pnode_head=loadNode("Final_Map.map");
    pNODE anode=pnode_head;
    int counter=0;
    while (anode->Nextnode!=NULL) {
        if (anode->node_id==id_node)
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
