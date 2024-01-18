#include<iostream>
#include <sstream>
#include <iomanip>
#include <string>
using namespace std;

std::string percentEncode(const std::string &value) {
    std::ostringstream escaped;
    escaped.fill('0');
    escaped << std::hex;

    for (char c : value) {
        // 保留字母，数字和一些特殊字符不被编码
        if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~') {
            escaped << c;
            continue;
        }

        // 其他所有字符都被编码
        escaped << std::uppercase;
        escaped << '%' << std::setw(2) << int((unsigned char) c);
        escaped << std::nouppercase;
    }

    return escaped.str();
}

int main(){
    cout << percentEncode("cid:494f3601-2278-4af6-a00d-02756235fd27");
    return 0;
}