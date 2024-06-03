#include <iostream>
#include <ctime>

// 假设 m_syncTokenExpiresOn 已经被设置为一个特定的过期时间
time_t m_syncTokenExpiresOn; // 这应该在你的代码的某个地方被赋值

bool isTokenExpired() {
    // 获取当前时间
    time_t now = time(nullptr);

    // 比较当前时间和过期时间
    return now > m_syncTokenExpiresOn;
}

void printTokenExpirationTimestamp(time_t expirationTime) {
    // 打印时间戳
    std::cout << "Token will expire on (timestamp): " << expirationTime*100 << std::endl;
}

int main() {
    // 假设 m_syncTokenExpiresOn 在未来设置了一个时间
    m_syncTokenExpiresOn = time(nullptr) + 60; // 设置为当前时间之后的60秒

    // 打印 token 过期时间戳
    printTokenExpirationTimestamp(m_syncTokenExpiresOn);

    // 检查令牌是否过期
    if (isTokenExpired()) {
        std::cout << "Token is expired." << std::endl;
    } else {
        std::cout << "Token is still valid." << std::endl;
    }

    return 0;
}
