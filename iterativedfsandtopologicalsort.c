#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_VERTICES 100
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
typedef struct Stack {
    int data[MAX_VERTICES];
    int top;
} Stack;
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
void initializeStack(Stack* stack) {
    stack->top = -1;
}
void push(Stack* stack, int data) {
    stack->data[++stack->top] = data;
}
int pop(Stack* stack) {
    return stack->data[stack->top--];
}
bool isEmpty(Stack* stack) {
    return stack->top == -1;
}
node* createNode(int v)
{
    node* newNode =(node*)malloc(sizeof(node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}
void addEdge(Graph* graph, int src, int dest) {
    node* newVertex = createNode(dest);
    newVertex->next = graph->adjLists[src];
    graph->adjLists[src]=newVertex;
}
void addEdge1(Graph* graph, int src, int dest)
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
void nonRecursiveDFS(Graph* graph) {
    bool visited[MAX_VERTICES] = {false};
    int startTime[MAX_VERTICES];
    int endTime[MAX_VERTICES];
    char edgeType[MAX_VERTICES][MAX_VERTICES];
    int parent[MAX_VERTICES],i;
    Stack stack;
    initializeStack(&stack);
    parent[0]=0;
    int time = 0;
    for (i = 0; i < graph->numVertices; i++) {
        startTime[i] = -1;
        endTime[i] = -1;
    }
    i=1;
    for (int i = 0; i < graph->numVertices; i++) {
        if (!visited[i]) {
            push(&stack, i);
            while (!isEmpty(&stack)) {
                int currentVertex = pop(&stack);
                parent[i++]=currentVertex;
                if (!visited[currentVertex]) {
                    visited[currentVertex] = true;
                    startTime[currentVertex] = time++;
                    printf("Visited vertex %d\n", currentVertex);
                    for (node* neighbor = graph->adjLists[currentVertex]; neighbor != NULL; neighbor = neighbor->next) {
                        int neighborVertex = neighbor->vertex;
                        if (!visited[neighborVertex]) {
                            edgeType[currentVertex][neighborVertex] = 'T'; // Tree edge
                            push(&stack, neighborVertex);
                        } else {
                            if (startTime[currentVertex] < startTime[neighborVertex]) {
                                edgeType[currentVertex][neighborVertex] = 'F'; // Forward edge
                            } else if (endTime[neighborVertex] == -1) {
                                edgeType[currentVertex][neighborVertex] = 'B'; // Back edge
                            } else {
                                edgeType[currentVertex][neighborVertex] = 'C'; // Cross edge
                            }
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < graph->numVertices; i++) {
        if(i>=1){
            printf("Vertex %d: Start Time = %d,parent:%d ", i, startTime[i],parent[i-1]);
            for (int j = 0; j < graph->numVertices; j++) {
                if (edgeType[i][j] != '\0') {
                    printf("Edge (%d, %d) Type: %c\n", i, j, edgeType[i][j]);
                }
            }
        }
        else{
            printf("Vertex %d: Start Time = %d,parent:NULL", i, startTime[i]);
            for (int j = 0; j < graph->numVertices; j++) {
                if (edgeType[i][j] != '\0') {
                    printf("Edge (%d, %d) Type: %c\n", i, j, edgeType[i][j]);
                }
            }
        }
    }
    printf("\n");
}
void topologicalSortUtil(Graph* graph, int vertex, bool visited[], int stack[], int* stackIndex) {
    visited[vertex] = true;
    int neighborVertex;
    for (node* neighbor = graph->adjLists[vertex]; neighbor != NULL; neighbor = neighbor->next) {
        neighborVertex = neighbor->vertex;
        if (!visited[neighborVertex]) {
            topologicalSortUtil(graph, neighborVertex, visited, stack, stackIndex);
        }
    }
    stack[(*stackIndex)] = vertex;
    (*stackIndex)++;
}
void topologicalSort(Graph* graph) {
    int stack[MAX_VERTICES];
    int stackIndex = 0;
    bool visited[MAX_VERTICES];

    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = false;
    }

    for (int i = 0; i < graph->numVertices; i++) {
        if (!visited[i]) {
            topologicalSortUtil(graph, i, visited, stack, &stackIndex);
        }
    }
    printf("Topological Sort: ");
    for (int i = stackIndex - 1; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
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
int main() {
    int c,n,choice;
    int src,desti;
    Graph* graph;
    printf("Enter the no. of the vertices:");
    scanf("%d",&n);
    graph=createGraph(n);
    printf("Enter choice 1.Directed Graph, 2.Undirected Graph\n");
    scanf("%d",&choice);
    if(choice==1){printf("Enter the choice 1.add edge 2.print graph\n");
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
    printf("DFS Traversal:\n");
    nonRecursiveDFS(graph);
    topologicalSort(graph);}
    else{
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
                addEdge1(graph,src,desti);
                break;
            case 2:
                printGraph(graph);
        }
        printf("Enter the choice 1.add edge 2.print graph\n");
        scanf("%d",&c);
    }
    printf("DFS Traversal:\n");
    nonRecursiveDFS(graph);
    topologicalSort(graph);
    }
    return 0;
}
