Question: Castle on the Grid

You are given a square grid with some cells open (.) and some blocked (X). Your playing piece can move along any row or column until it reaches the edge of the grid or a blocked cell. Given a grid, a start and a goal, determine the minimum number of moves to get to the goal.

Solution:

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int x, y, dist;
} Point;

typedef struct Node {
    Point pt;
    struct Node* next;
} Node;

typedef struct {
    Node *front, *rear;
} Queue;

void enqueue(Queue* q, Point p) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->pt = p;
    node->next = NULL;
    if(q->rear) q->rear->next = node;
    q->rear = node;
    if(!q->front) q->front = node;
}

Point dequeue(Queue* q) {
    Node* temp = q->front;
    Point p = temp->pt;
    q->front = q->front->next;
    if(!q->front) q->rear = NULL;
    free(temp);
    return p;
}

int isEmpty(Queue* q) {
    return q->front == NULL;
}

int minimumMoves(char grid[MAX][MAX], int n, int startX, int startY, int goalX, int goalY) {
    int visited[MAX][MAX] = {0};
    Queue q = {NULL, NULL};
    Point start = {startX, startY, 0};
    enqueue(&q, start);
    visited[startX][startY] = 1;

    int dirX[] = {-1, 1, 0, 0};
    int dirY[] = {0, 0, -1, 1};

    while(!isEmpty(&q)) {
        Point cur = dequeue(&q);
        if(cur.x == goalX && cur.y == goalY) return cur.dist;

        for(int d = 0; d < 4; d++) {
            int nx = cur.x;
            int ny = cur.y;
            while(1) {
                nx += dirX[d];
                ny += dirY[d];
                if(nx < 0 || ny < 0 || nx >= n || ny >= n || grid[nx][ny] == 'X') break;
                if(!visited[nx][ny]) {
                    visited[nx][ny] = 1;
                    Point next = {nx, ny, cur.dist + 1};
                    enqueue(&q, next);
                }
            }
        }
    }
    return -1;
}

int main() {
    int n;
    scanf("%d", &n);
    char grid[MAX][MAX];
    for(int i = 0; i < n; i++) scanf("%s", grid[i]);
    int sx, sy, gx, gy;
    scanf("%d %d %d %d", &sx, &sy, &gx, &gy);
    printf("%d\n", minimumMoves(grid, n, sx, sy, gx, gy));
    return 0;
}
