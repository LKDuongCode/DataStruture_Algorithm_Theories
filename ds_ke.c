#include<stdio.h>
#include<stdlib.h>

// dinh nghia do thi
struct Node {
	int vertex;
	struct Node* next;
};

struct Graph {
	int numVertices;
	struct Node ** adjLists;
};


//ham tao moi node (dinh moi) trong ds ke
struct Node *createNode(int v){
	struct Node *newNode = malloc(sizeof(struct Node));
	newNode->vertex = v;
	newNode->next = NULL;
	return newNode;
}


//ham khoi tao do thi
struct Graph *createGraph(int vertices){
	struct Graph *graph = malloc(sizeof(struct Graph));
	graph->numVertices = vertices;
	
	graph->adjLists = malloc(vertices * sizeof(struct Node*));
	for(int i = 0; i < vertices; i++){
		grap->adjList[i] = NULL;
	}
	
	return graph;
}

//them canh vao danh sach ke
void addEdge(struct Graph * graph, int scr, int dest){
	struct Node *newNode = createGraph(dest);
	newNode->next = graph->adjLists[scr];
	graph->adjLists[scr] = newNode;
	
	newNode = createGraph(scr); // neu la do thi vo huong
	newNode->next = graph->adjLists[dest];
	graph->adjLists[dest] = newNode;
}

// in do thi duoi dang danh sach ke
void printGraph (struct Graph *graph){
	for (int v = 0; v < graph->numVertices; v++){
		struct Node *temp = graph->adjLists[v];
		printf("\n danh sach ke cua dinh %d \n",v);
		while(temp){
			printf("%d -> ", temp->vertex);
			temp = temp->next;
		}
		printf("NULL \n");
	}
}
int main(){
	struct Graph *graph = createGraph(4);
	
	addEdge(graph,0,1);
	addEdge(graph,0,2);
	addEdge(graph,1,2);
	addEdge(graph,2,3);
	
	printGraph(graph);
	return 0;
}



