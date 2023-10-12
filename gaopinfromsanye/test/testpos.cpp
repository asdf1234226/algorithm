#include <iostream>
#include <chrono>

// 定义一个加法函数
int add(int a, int b) {
    return a + b;
}

int main() {
    // 获取开始时间
    auto start = std::chrono::high_resolution_clock::now();

    // 调用加法函数
    int result = add(5, 3);

    // 获取结束时间
    auto end = std::chrono::high_resolution_clock::now();

    // 计算并打印执行时间
    std::chrono::duration<double> diff = end - start;
    std::cout << "Time to run function add: " << diff.count() << " s\n";

    return 0;
}
