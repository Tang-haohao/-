#ifndef LOAD_DATA_H
#define LOAD_DATA_H

pNODE loadNode(char filename[]);
pPATH loadPath(char filename[]);
pMyGraph produceGraph(pPATH path_head,pNODE node_head);

#endif

