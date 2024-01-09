#include <iostream>
#include <regex>

int main() {
    std::string s = "/?0";
    std::regex e("/\\?0");  // 注意这里的转义字符

    // 使用 regex_match() 来检查字符串是否完全匹配正则表达式
    if (std::regex_match(s, e))
        std::cout << "String is a match.\n";
    else
        std::cout << "No match.\n";

    return 0;
}
