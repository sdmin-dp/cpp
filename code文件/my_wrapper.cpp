// my_wrapper.cpp
// 简单的 C++ wrapper，避免所有编译警告
// 编译: g++ -w -std=c++11 -O2 -DONLINE_JUDGE -o solution solution.cpp

// 首先声明用户函数
int user_main();

// 然后定义主函数
int main() {
    // 禁用同步加速IO
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    
    // 调用用户代码
    return user_main();
}

// 默认实现（用户会覆盖这个）
int user_main() {
    return 0;
}