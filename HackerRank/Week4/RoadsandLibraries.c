Question: Roads and Libraries

Determine the minimum cost to provide library access to all citizens of HackerLand. There are  cities numbered from  to . Currently there are no libraries and the cities are not connected. Bidirectional roads may be built between any city pair listed in . A citizen has access to a library if:

Their city contains a library.
They can travel by road from their city to a city containing a library.

Solution:

#include <stdio.h>
#include <stdlib.h>

#define MAX 100005

typedef struct Node {
    int city;
    struct Node* next;
} Node;

Node* graph[MAX];
int visited[MAX];

void addEdge(int u, int v) {
    Node* nu = (Node*)malloc(sizeof(Node));
    nu->city = v;
    nu->next = graph[u];
    graph[u] = nu;

    Node* nv = (Node*)malloc(sizeof(Node));
    nv->city = u;
    nv->next = graph[v];
    graph[v] = nv;
}

int dfs(int u) {
    visited[u] = 1;
    int count = 1;
    Node* ptr = graph[u];
    while(ptr) {
        if(!visited[ptr->city]) count += dfs(ptr->city);
        ptr = ptr->next;
    }
    return count;
}

long long roadsAndLibraries(int n, int c_lib, int c_road) {
    if(c_road >= c_lib) return (long long)c_lib * n;

    for(int i=1;i<=n;i++) visited[i] = 0;

    long long cost = 0;
    for(int i=1;i<=n;i++) {
        if(!visited[i]) {
            int size = dfs(i);
            cost += (long long)c_lib + (long long)(size-1)*c_road;
        }
    }
    return cost;
}

int main() {
    int q;
    scanf("%d", &q);
    while(q--) {
        int n, m, clib, croad;
        scanf("%d %d %d %d", &n, &m, &clib, &croad);

        for(int i=1;i<=n;i++) graph[i] = NULL;

        for(int i=0;i<m;i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            addEdge(u, v);
        }

        printf("%lld\n", roadsAndLibraries(n, clib, croad));
    }
    return 0;
}
