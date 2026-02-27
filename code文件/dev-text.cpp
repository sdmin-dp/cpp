#include <iostream>
#include <vector>

int main() {
    int limit = 2026;
    int count = 0;
    std::vector<int> results;

    // 最小质因数为 5 的数一定是 5 的倍数
    // 我们直接以 5 为步长进行遍历
    for (int i = 5; i <= limit; i += 5) {
        // 最小质因数是 5，意味着它不能有比 5 更小的质因数（即 2 和 3）
        if (i % 2 != 0 && i % 3 != 0) {
            count++;
            results.push_back(i);
        }
    }

    std::cout << "2026以内最小质因数是5的数共有: " << count << " 个" << std::endl;

    // 打印前5个和最后5个作为验证
    if (!results.empty()) {
        std::cout << "部分数值示例: ";
        for (int i = 0; i < 5 && i < results.size(); ++i) {
            std::cout << results[i] << " ";
        }
        std::cout << "... ";
        for (int i = results.size() - 5; i < results.size(); ++i) {
            if (i >= 0) std::cout << results[i] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

