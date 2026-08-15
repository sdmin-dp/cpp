#include <bits/stdc++.h>
using namespace std;

const int MAXN = 310;
const int LOG = 9;  // 2⁹=512 > 300

int n, m, q;
int mat[MAXN][MAXN];
int st[MAXN][MAXN][LOG][LOG];
int lg[MAXN];

// 预处理对数表
void init_log() {
    lg[1] = 0;
    for (int i = 2; i < MAXN; i++) {
        lg[i] = lg[i / 2] + 1;
    }
}

// 预处理ST表
void init_st() {
    // 初始化：1×1的矩形
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            st[i][j][0][0] = mat[i][j];
        }
    }
    
    // 处理高度为2的幂次的矩形（行方向）
    for (int p = 1; p < LOG; p++) {
        for (int i = 0; i + (1 << p) - 1 < n; i++) {
            for (int j = 0; j < m; j++) {
                st[i][j][p][0] = min(
                    st[i][j][p - 1][0],
                    st[i + (1 << (p - 1))][j][p - 1][0]
                );
            }
        }
    }
    
    // 处理宽度为2的幂次的矩形（列方向）
    for (int q = 1; q < LOG; q++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j + (1 << q) - 1 < m; j++) {
                st[i][j][0][q] = min(
                    st[i][j][0][q - 1],
                    st[i][j + (1 << (q - 1))][0][q - 1]
                );
            }
        }
    }
    
    // 处理2ᵖ×2ᵖ的矩形
    for (int p = 1; p < LOG; p++) {
        for (int q = 1; q < LOG; q++) {
            for (int i = 0; i + (1 << p) - 1 < n; i++) {
                for (int j = 0; j + (1 << q) - 1 < m; j++) {
                    st[i][j][p][q] = min(
                        min(
                            st[i][j][p - 1][q - 1],
                            st[i][j + (1 << (q - 1))][p - 1][q - 1]
                        ),
                        min(
                            st[i + (1 << (p - 1))][j][p - 1][q - 1],
                            st[i + (1 << (p - 1))][j + (1 << (q - 1))][p - 1][q - 1]
                        )
                    );
                }
            }
        }
    }
}

// 查询子矩阵最小值
int query(int x1, int y1, int x2, int y2) {
    int k = lg[x2 - x1 + 1];
    int l = lg[y2 - y1 + 1];
    
    // 四个子矩形
    int a = st[x1][y1][k][l];
    int b = st[x1][y2 - (1 << l) + 1][k][l];
    int c = st[x2 - (1 << k) + 1][y1][k][l];
    int d = st[x2 - (1 << k) + 1][y2 - (1 << l) + 1][k][l];
    
    return min(min(a, b), min(c, d));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m >> q;
    
    // 读入矩阵（1-based转换为0-based）
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }
    
    // 预处理
    init_log();
    init_st();
    
    // 处理查询
    for (int i = 0; i < q; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        // 转换为0-based索引
        x1--; y1--; x2--; y2--;
        
        cout << query(x1, y1, x2, y2) << "\n";
    }
    
    return 0;
}
