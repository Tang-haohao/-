#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Parameter.h"
#include "load_data.h"
#include "auxiliary_function.h"
#include "Compute.h"
#include "drawgraph.h"

void drawgraph(pPATH head_path,pNODE node_head){
	pPATH headpath=head_path;
	pNODE pnode_head=node_head;
	FILE *file = fopen("graph.out","w");
	pPATH a_path=headpath;
	while(a_path!=NULL){
		int fir_nodeid=a_path->first_node;
		int sec_nodeid=a_path->second_node;
		int first_i=findindex(fir_nodeid,pnode_head);
		int second_i=findindex(sec_nodeid,pnode_head);
		pNODE fir_node=findnode(first_i,pnode_head);
		pNODE sec_node=findnode(second_i,pnode_head);
		double fir_lat=fir_node->node_lat;
		double sec_lat=sec_node->node_lat;
		double fir_lgt=fir_node->node_lgt;
		double sec_lgt=sec_node->node_lgt;
		fprintf(file," %lf %lf\n",fir_lat,fir_lgt);
		fprintf(file," %lf %lf\n\n",sec_lat,sec_lgt);
		a_path=a_path->Nextpath;
	}
	fclose(file);
}


