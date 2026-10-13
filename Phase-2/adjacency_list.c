#include "adjacency_list.h"

CampusGraph* createCampusGraph(int vertices) {
    CampusGraph* graph = (CampusGraph*)malloc(sizeof(CampusGraph));
    graph->numVertices = vertices;
    
    // Allocate memory for array of adjacency list heads (DS Unit 1 & 2)
    graph->headLists = (AdjNode**)malloc(vertices * sizeof(AdjNode*));
    for (int i = 0; i < vertices; i++) {
        graph->headLists[i] = NULL;
    }
    return graph;
}

void addRoadEdge(CampusGraph* graph, int src, int dest, const char* name) {
    // Add edge from src to dest (Undirected graph mapping 12 campus junctions)
    AdjNode* newNodeSrc = (AdjNode*)malloc(sizeof(AdjNode));
    newNodeSrc->destVertex = dest;
    strcpy(newNodeSrc->junctionName, name);
    newNodeSrc->next = graph->headLists[src];
    graph->headLists[src] = newNodeSrc;

    // Add edge from dest to src
    AdjNode* newNodeDest = (AdjNode*)malloc(sizeof(AdjNode));
    newNodeDest->destVertex = src;
    strcpy(newNodeDest->junctionName, name);
    newNodeDest->next = graph->headLists[dest];
    graph->headLists[dest] = newNodeDest;
}

void printCampusGraph(CampusGraph* graph, const char* landmarkNames[]) {
    printf("\n=== CAMPUS STREET NETWORK (12 JUNCTIONS & HOSTEL GATES) ===\n");
    for (int i = 0; i < graph->numVertices; i++) {
        AdjNode* temp = graph->headLists[i];
        printf("Junction %d [%s] -> ", i, landmarkNames[i]);
        while (temp) {
            printf("Node %d (%s) ", temp->destVertex, temp->junctionName);
            temp = temp->next;
        }
        printf("\n");
    }
}

void freeCampusGraph(CampusGraph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        AdjNode* temp = graph->headLists[i];
        while (temp) {
            AdjNode* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph->headLists);
    free(graph);
}