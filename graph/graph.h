#ifndef _INCLUDE_GRAPH_
#define _INCLUDE_GRAPH_
#define MAX 30
#define TRUE 1
#define FALSE 0
#include <stdint.h>

uint32_t visited[MAX];
typedef struct _node_ Node;
typedef struct _graph_ Graph;
struct _node_ {
    int32_t node_id;
    Node *next;
};

struct _graph_{
    uint32_t size;
    Node ** neighbours;
};

Graph graph_new(uint32_t size);
Graph* graph_adjacency_list(Graph *gp);
Graph* graph_dfs(Graph *gp,int32_t vertex);
Graph* graph_bfs(Graph *gp,int32_t vertex);


#endif