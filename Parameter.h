#ifndef PARAMETER__H 
#define PARAMETER__H

#define INF         (~(0x1<<31)) 
#define MAX     5000

typedef struct NODE
{
    double node_lat;
    double node_lgt;
    int node_id;
    struct NODE* Nextnode;
} Node;


typedef struct PATH
{
	double length;
    int first_node;
    int second_node;
    int path_id;
    struct PATH* Nextpath;
} Path;

typedef struct MyGraph		/* �ڽӱ�洢�ṹ */
{
     int edges[MAX][MAX];
     int node_number;  //node number
	 int edge_number;  //edge number
} MyGraph;

typedef PATH* pPATH; 
typedef NODE* pNODE;
typedef MyGraph* pMyGraph; 

#endif
 
