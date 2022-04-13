// DFS algorithm in C++

#include <iostream>
#include <list>
#include<iterator>
using namespace std;

class Graph {
  int numVertices;
  list<int> *adjLists;
  bool *visited;

   public:
  Graph(int V);
  void addEdge(int src, int dest);
  void clearVisited();
  void DFS(int vertex);
  void DFS_ALL();
};

// Initialize graph
Graph::Graph(int vertices) {
  numVertices = vertices;
  adjLists = new list<int>[vertices+1];
  visited = new bool[vertices];
}

// set false all visited
void Graph::clearVisited(){
    for(int i = 1; i<=numVertices;i++){
        visited[i]=0;
    }
}

// Add edges
void Graph::addEdge(int src, int dest) {
  adjLists[src].push_front(dest);
  adjLists[dest].push_front(src);
}

// DFS algorithm
void Graph::DFS(int vertex) {
  visited[vertex] = true;

  list<int> adjList = adjLists[vertex];


  cout << vertex << " ";

  list<int>::iterator i;
  for (i = adjList.begin(); i != adjList.end(); ++i){
    if (visited[*i] == false){
        DFS(*i);
    }
  }
}

void Graph::DFS_ALL() {
    for(unsigned j = 1; j <= numVertices;j++){
        if(visited[j] == false)
            cout << j << " ";
        visited[j] = true;
        list<int> adjList = adjLists[j];
        //cout << *adjList.begin() << " ";
        if(*adjList.begin() == 0){
            cout << "\n";
        }
        list<int>::iterator i;
        for (i = adjList.begin(); i != adjList.end(); ++i){
            if (!visited[*i]){
                DFS(*i);
                cout << "\n";
            }
        }
    }

}

int main() {

  Graph g(10);
  g.clearVisited();
  g.addEdge(2, 9);
  g.addEdge(3, 8);
  g.addEdge(5, 7);
  g.addEdge(6, 9);
  g.addEdge(8, 10);
  g.DFS_ALL();


  return 0;
}
