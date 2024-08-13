#include <iostream>
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

int main() {

    hanoi(3, 'A', 'B', 'C');

    return 0;
}
