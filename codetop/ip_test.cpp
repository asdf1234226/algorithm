#include<iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isValidNumber(const std::string& str) {
    int num = std::stoi(str);
    return num >= 0 && num <= 255;
}

bool isValidRange(const std::string& str) {
    int dashPos = str.find('-');
    if (dashPos == std::string::npos || dashPos == 0 || dashPos == str.size() - 1) {
        return false;
    }

    int start = std::stoi(str.substr(0, dashPos));
    int end = std::stoi(str.substr(dashPos + 1));

    return start >= 0 && start < end && end <= 255;
}

bool isValidSegment(const std::string& segment) {
    if (segment.front() == '[' && segment.back() == ']') {
        return isValidRange(segment.substr(1, segment.size() - 2));
    } else {
        return isValidNumber(segment);
    }
}

bool isValidIP(const std::string& ip) {
    size_t startPos = 0;
    size_t dotPos;
    int segmentCount = 0;

    while ((dotPos = ip.find('.', startPos)) != std::string::npos) {
        if (!isValidSegment(ip.substr(startPos, dotPos - startPos))) {
            return false;
        }
        startPos = dotPos + 1;
        ++segmentCount;
    }

    // Check the last segment
    if (!isValidSegment(ip.substr(startPos))) {
        return false;
    }
    ++segmentCount;

    return segmentCount == 4;
}

int main(){
    if (isValidIP("1.[22-255].[22-44].[111-255]"))
    {
        cout << "valid";
    }else{
        cout << "invalid";
    }
    
    return 0;
}