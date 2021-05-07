#ifndef COMPUTE_H
#define COMPUTE_H

#include "Parameter.h"
#include "load_data.h"

double Dijkstra(pMyGraph mgraph, int v, int m); 
int Dispath(double dis[],int pre[],int selected[], int n, int v, int m);
void Ppath(int path[], int i, int v);
int inputpath (int pre[],int i,int v);

#endif








