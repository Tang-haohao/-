#ifndef COMPUTE_H
#define COMPUTE_H

#include "Parameter.h"
#include "load_data.h"

void Dijkstra(MyGraph *mgraph, int v, int m); 
void Dispath(int dis[],int pre[],int selected[], int n, int v, int m);
void Ppath(int path[], int i, int v);

#endif








