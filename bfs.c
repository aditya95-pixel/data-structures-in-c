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
    int*visited;
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
    graph->visited=(int*)malloc(vertices*sizeof(int));
    int i;
    for (i = 0; i < vertices; i++){
    graph->adjLists[i] = NULL;
    graph->visited[i]=0;
    }
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
void bfs(Graph* graph, int v) {  
    // Create a queue for BFS  
    int front=-1,rear=-1;
    int *queue;
    queue=(int*)malloc(100*sizeof(int));
    // Mark the current node as visited and enqueue it  
    graph->visited[v] = 1;  
    queue[++rear]=v;
    // Loop to visit all the vertices in the graph  
    while (front!=rear) {  
        // Dequeue a vertex from the queue and print it  
        int current_vertex = queue[++front];
        printf("%d ", current_vertex);  
        // Get all the neighbors of the dequeued vertex  
        node* temp = graph->adjLists[current_vertex];  
        while (temp != NULL) {  
            int adj_vertex = temp->vertex;  
            // If the neighbor has not been visited, mark it as visited and enqueue it  
            if (graph->visited[adj_vertex] == 0) {  
                graph->visited[adj_vertex] = 1;  
                queue[++rear]=adj_vertex;
            }  
            temp = temp->next;  
        }  
    }  
    free(queue);
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
    bfs(graph,0);
    return 0;
}