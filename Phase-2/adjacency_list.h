#ifndef ADJACENCY_LIST_H
#define ADJACENCY_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for graph node in adjacency list (DS Unit 2)
typedef struct AdjNode {
    int destVertex;
    char junctionName[30];
    struct AdjNode* next;
} AdjNode;

// Struct for Graph containing array of pointers to adjacency lists
typedef struct CampusGraph {
    int numVertices;
    AdjNode** headLists;
} CampusGraph;

CampusGraph* createCampusGraph(int vertices);
void addRoadEdge(CampusGraph* graph, int src, int dest, const char* name);
void printCampusGraph(CampusGraph* graph, const char* landmarkNames[]);
void freeCampusGraph(CampusGraph* graph);

#endif