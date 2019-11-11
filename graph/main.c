#include <stdio.h>
#include <assert.h>
#include "./lib/graph.h"

/**
 * 
 *  To Compile : gcc -D DATA_TYPE_USED=int main.c ./lib/graph.c ../Queue/queue.c
**/
void check_create(){
    Graph g = graph_new(4);
    Graph *grp =  &g;
    assert(grp->size==4);
    for(int i =0;i<grp->size;i++){
        assert(grp->neighbours[i]==NULL);
    }
    printf("[+] Creation test case passed.\n");
}

void check_all(){
    int size;
    printf("Enter size : ");
    scanf("%d",&size);
    Graph g = graph_new(size);
    Graph *grp =  &g;
    grp = graph_adjacency_list(grp);
    printf("DFS : ");
    graph_dfs(grp,0);
    printf("\n");
    printf("BFS : ");
    graph_bfs(grp,0);
    printf("\n[+]Completed BFS and DFS.");
}
int main(int arcv,char **c){
    check_create();
    check_all();
}