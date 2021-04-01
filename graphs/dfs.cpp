#include <bits/stdc++.h>

std::vector<int> graph[12];
bool visited[13];
void dfs(int);

int main(){
    int start;
    for (int i=0; i<13; i++) visited[i] = false;

    graph[0].push_back(1);
    graph[0].push_back(9);   
    graph[1].push_back(0);
    graph[9].push_back(0);
    graph[1].push_back(8);   
    graph[8].push_back(1);
    graph[8].push_back(9);
    graph[9].push_back(8);   
    graph[8].push_back(7);
    graph[7].push_back(8);
    graph[10].push_back(7);   
    graph[7].push_back(10);
    graph[7].push_back(11);
    graph[11].push_back(7);   
    graph[7].push_back(6);
    graph[7].push_back(3);
    graph[3].push_back(7);   
    graph[6].push_back(7);
    graph[6].push_back(5);
    graph[5].push_back(6);
    graph[5].push_back(3);   
    graph[3].push_back(5);
    graph[3].push_back(4);
    graph[4].push_back(3);
    graph[3].push_back(2);   
    graph[2].push_back(3);

    for(int i=0; i<12; i++){
        std::cout << "\nNode " << i << " connects : ";
        for(auto itr=graph[i].begin(); itr != graph[i].end(); itr++)
            std::cout << *itr << " ";
    }

    std::cout << "\n\n\tchoose starting node : ";
    std::cin >> start;
    std::cout << std::endl;
    dfs(start);

    std::cout << std::endl;
    return 0;
}

void dfs(int v){
    if(visited[v]) return;
    visited[v] = true;

    std::cout << v << " -> ";
    for(int i=0; i<graph[v].size(); i++)
        dfs(graph[v].at(i));
}