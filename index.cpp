#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

// 這是一個實現河內塔問題的遞迴函數
// n: 要移動的圓盤數量
// A: 起始柱子
// B: 輔助柱子
// C: 目標柱子
void hanoi(int n, char A, char B, char C) {
    // 基本情況：如果只有一個圓盤，直接從A移動到C
    if(n == 1) {
        cout << "將圓盤 1 從 " << A << " 移動到 " << C << endl;
    } else {
        // 遞迴情況：
        // 1. 將n-1個圓盤從A移動到B，以C為輔助
        hanoi(n - 1, A, C, B);
        // 2. 將最大的圓盤從A移動到C
        cout << "將圓盤 " << n << " 從 " << A << " 移動到 " << C << endl;
        // 3. 將n-1個圓盤從B移動到C，以A為輔助
        hanoi(n - 1, B, A, C);
    }
}

void DFS(int n) {
    if(n == 0) return;
    DFS(n - 1);
    cout << n << endl;
    DFS(n - 1);
}

void BFS(int n) {
    queue<int> q;
    q.push(n);
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        cout << x << endl;
        q.push(x - 1);
    }
}

void dijkstra(int n) {
    priority_queue<int> pq;
    pq.push(n);
    while(!pq.empty()) {
        int x = pq.top();
        pq.pop();
        cout << x << endl;
        pq.push(x - 1);
    }
}

void astar(int n) {
    priority_queue<int> pq;
    pq.push(n);
    while(!pq.empty()) {
        int x = pq.top();
        pq.pop();
        cout << x << endl;
        pq.push(x - 1);
    }
}

int main() {

    dijkstra(3);
    astar(3);

    return 0;
}
