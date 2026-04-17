#include <vector>

int main() {
    std::vector<long long*> v;
    while (true) {
        // 每次申请 100MB 左右的内存
        v.push_back(new long long[12500000]); 
    }
    return 0;
}
