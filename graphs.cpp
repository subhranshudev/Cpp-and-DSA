#include<iostream>
#include<list>
#include<queue>
#include<vector>
using namespace std;

class Graph{
    int V;
    list<int>* l;
    list<pair<int, int>>* li;
public:
    Graph(int V){
        this->V = V;
        l = new list<int> [V];  // Dynamic array of type lists
        li = new list<pair<int, int>> [V];  // For undirected-weighted graph
    }

    void addEdge(int u, int v){ // u---v
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void print(){
        for(int u = 0; u < V; u++){
            list<int> neighbours = l[u];
            cout<< u<< " : ";
            for(int v : neighbours){
                cout<< v << " ";
            }
            cout<< endl;
        }
    }

    void addEdgeWeighted(int u, int v, int wt){ // u---v
        li[u].push_back(make_pair(v, wt));
        li[v].push_back(make_pair(u,  wt));
    }

    void printWeighted(){
        for(int u = 0; u < V; u++){
            list<pair<int, int>> neighbours = li[u];
            cout<< u<< " : ";
            for(pair<int, int> v : neighbours){
                cout<< '('<< v.first<< ", "<< v.second<< ')' << " ";
            }
            cout<< endl;
        }
    }

    void BFS(){ // O(v + E)
        queue<int> q;
        vector<bool> vis(V, false);
        q.push(0);
        vis[0] = true;

        while(!q.empty()){
            int u = q.front();  // current vertex
            q.pop();
            cout<< u << " ";

            list<int> neighbours = l[u];
            for(int v : neighbours){
                if(!vis[v]){
                    q.push(v);
                    vis[v] = true;
                }
            }
        }

        cout<< endl;
    }

};

int main(){
//    Graph graph(5);

/*    // undirected graph
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);
    graph.addEdge(2, 4);

    graph.print();
*/

/*    // undirected weighted
    graph.addEdgeWeighted(0, 1, 5); // (u, v, weight)
    graph.addEdgeWeighted(1, 2, 1);
    graph.addEdgeWeighted(1, 3, 3);
    graph.addEdgeWeighted(2, 3, 1);
    graph.addEdgeWeighted(2, 4, 2);

    graph.printWeighted();
*/

    // Breadth First Search (BFS)
    Graph graph(7);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 4);
    graph.addEdge(3, 5);
    graph.addEdge(4, 5);
    graph.addEdge(5, 6);

    graph.BFS();

    return 0;
}