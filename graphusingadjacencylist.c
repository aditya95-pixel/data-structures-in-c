#include <stdio.h>
#include <stdlib.h>
struct node
{
    int vertex;
    struct node* next;
};
struct Graph{
    int numVertices;
    struct node** adjLists;
};
typedef struct node node;
typedef struct Graph Graph;
node* createNode(int v)
{
    node* newNode =(node*)malloc(sizeof(node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}
Graph* createGraph(int vertices)
{
    Graph* graph =(Graph*) malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->adjLists =(node**)malloc(vertices * sizeof(node*));
    int i;
    for (i = 0; i < vertices; i++)
    graph->adjLists[i] = NULL;
    return graph;
}
void addEdge(Graph* graph, int src, int dest)
{
// Add edge from src to dest
    node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
// Add edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}
void printGraph(Graph* graph)
{
    int v;
    for (v = 0; v < graph->numVertices; v++)
    {
        node* temp = graph->adjLists[v];
        printf("\n Adjacency list of vertex %d\n ", v);
        while (temp)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}
int main()
{
    int c,n;
    int src,desti;
    Graph* graph;
    printf("Enter the no. of the vertices:");
    scanf("%d",&n);
    graph=createGraph(n);
    printf("Enter the choice 1.add edge 2.print graph\n");
    scanf("%d",&c);
    while(c!=-1)
    {
        switch(c){
            case 1:
                printf("Enter the source:");
                scanf("%d",&src);
                printf("Enter the destination:");
                scanf("%d",&desti);
                addEdge(graph,src,desti);
                break;
            case 2:
                printGraph(graph);
        }
        printf("Enter the choice 1.add edge 2.print graph\n");
        scanf("%d",&c);
    }
    return 0;
}