#include<iostream>
#include<map>
#include<list>

class Graph
{
    private : 
    std::map<int, bool> visited ; 
    std::map<int, std::list<int> > AdjaList ; 

    public : 
    void addEdge(int v, int u) { AdjaList[v].push_back(u) ; }
    void DFS(int v)
    {
        visited[v] = true ; 
        std::cout << v << " " ; 
        std::list<int>::iterator i ; 
        for(i = AdjaList[v].begin() ; i != AdjaList[v].end() ; i++)
            if(!visited[*i]) DFS(*i) ; 
    }
};

int main()
{
    Graph g;
    g.addEdge(0, 1) ;
    g.addEdge(0, 2) ;
    g.addEdge(1, 2) ;
    g.addEdge(2, 0) ;
    g.addEdge(2, 3) ;
    g.addEdge(3, 3) ;
 
    std::cout << "Following is Depth First Traversal (starting from vertex 2) \n";
 
    // Function call
    g.DFS(2);
 
}
