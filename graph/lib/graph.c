#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include "./graph.h"
#include "../../Queue/queue.h"

static void __make_neighbours_null(Graph* gp){
    for(int32_t i=gp->size-1;i>=0;i--){
        gp->neighbours[i] = NULL;
    }
}
Graph graph_new(uint32_t size){
    Node** nds = (Node**) malloc(sizeof(Node*)*size);
    Graph g = {size,nds};
    __make_neighbours_null(&g);
    return g;
}

static Node* _create_node(int32_t vertex){
    Node* node = (Node*) malloc(sizeof(Node));
    node->node_id = vertex;
    node->next = NULL;
    return node;
}

static int32_t _get_nighbr_node(int32_t vertex){
    int32_t neighbor;
    printf("\nEnter neighbor of %d, no neighbor enter 9999:",vertex);
    scanf("%d",&neighbor);
    return neighbor;
}
Graph* graph_adjacency_list(Graph *gp){
    assert(gp!=NULL);
    Node* vrtx,*lst;
    printf("\nTango Bravo charle");
    for(int i=0;i<gp->size;i++){
        gp->neighbours[i] = _create_node(i);
        lst = gp->neighbours[i];
        int neighbour = _get_nighbr_node(i);
        while(neighbour!=9999){
            lst->next = _create_node(neighbour);
            lst = lst->next;
            neighbour = _get_nighbr_node(i);
        }
    }
    return gp;
}

void _dfs_subFunc(Graph *gp,Node* node,int16_t visited[]){
    while(node!=NULL){
        if(!visited[node->node_id]){
            printf("%d,",node->node_id);
            visited[node->node_id] =1;
            _dfs_subFunc(gp,gp->neighbours[node->node_id],visited);
        }
        node = node->next;
    }
}

Graph* graph_dfs(Graph *gp,int32_t vertex){
    Node* node  = gp->neighbours[vertex];
    int16_t visited[gp->size];
    for(int i =0;i<gp->size;i++){
        visited[i]=0;
    }
    _dfs_subFunc(gp,node,visited);
    return gp;
}

Graph* graph_bfs(Graph *gp,int32_t vertex){
    Queue* q = create_queue(gp->size);
    int16_t visited[gp->size];
    for(int i =0;i<gp->size;i++){
        visited[i]=0;
    }
    visited[vertex] = 1;
    add(q,vertex);
    while(q->length!=0){
        int ele = delete(q)->data;
        printf("%d,",ele);
        Node* node = gp->neighbours[ele];
        while(node!=NULL){
            if(!visited[node->node_id]){
                add(q,node->node_id);
                visited[node->node_id] = 1;
            }
            node = node->next;
        }

    }
}

// void print_graph(Graph *gp){
//     for(int i=0;i<gp->size;i++){

//     }
// }
