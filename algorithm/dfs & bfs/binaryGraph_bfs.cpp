#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

bool isPossible(vector<int> *graph, int n){
    queue<int> q;
    int *colored = new int[n + 1];
    memset(colored, 0, sizeof(int)*(n + 1));

    q.push(1);
    colored[1] = 1;

    while (!q.empty()) {
        int front = q.front();
        q.pop();

        for (int i = 0; i < graph[front].size(); i++){
            if (colored[graph[front][i]] == colored[front]) {
               return false;
            }
            else if (colored[graph[front][i]] == 0){
                colored[graph[front][i]] = (colored[front] * -1);
                q.push(graph[front][i]);
            }
        }
    }

    return true;
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> *graph = new vector<int>[n + 1];

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    if(isPossible(graph, n)) cout << "Yes";
    else cout << "No";
}