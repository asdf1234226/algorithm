#include<iostream>
#include <string>
#include <algorithm>
using namespace std;

struct IPRange {
    int start;
    int end;

    IPRange() : start(-1), end(-1) {}
};

bool parseNumber(const std::string& str, IPRange& range) {
    int num = std::stoi(str);
    if (num >= 0 && num <= 255) {
        range.start = range.end = num;
        return true;
    }
    return false;
}

bool parseRange(const std::string& str, IPRange& range) {
    int dashPos = str.find('-');
    if (dashPos == std::string::npos || dashPos == 0 || dashPos == str.size() - 1) {
        return false;
    }

    int start = std::stoi(str.substr(0, dashPos));
    int end = std::stoi(str.substr(dashPos + 1));

    if (start >= 0 && start < end && end <= 255) {
        range.start = start;
        range.end = end;
        return true;
    }
    return false;
}

bool parseSegment(const std::string& segment, IPRange& range) {
    if (segment.front() == '[' && segment.back() == ']') {
        return parseRange(segment.substr(1, segment.size() - 2), range);
    } else {
        return parseNumber(segment, range);
    }
}

bool isValidIP(const std::string& ip, IPRange ranges[4]) {
    size_t startPos = 0;
    size_t dotPos;
    int segmentCount = 0;

    while ((dotPos = ip.find('.', startPos)) != std::string::npos) {
        if (!parseSegment(ip.substr(startPos, dotPos - startPos), ranges[segmentCount])) {
            return false;
        }
        startPos = dotPos + 1;
        ++segmentCount;
    }

    // Check the last segment
    if (!parseSegment(ip.substr(startPos), ranges[segmentCount])) {
        return false;
    }
    ++segmentCount;

    return segmentCount == 4;
}

bool isIPInRange(const std::string& ip, const IPRange ranges[4]) {
    size_t startPos = 0;
    size_t dotPos;
    int segmentCount = 0;

    while ((dotPos = ip.find('.', startPos)) != std::string::npos) {
        int num = std::stoi(ip.substr(startPos, dotPos - startPos));
        if (num < ranges[segmentCount].start || num > ranges[segmentCount].end) {
            return false;
        }
        startPos = dotPos + 1;
        ++segmentCount;
    }

    // Check the last segment
    int num = std::stoi(ip.substr(startPos));
    if (num < ranges[segmentCount].start || num > ranges[segmentCount].end) {
        return false;
    }
    ++segmentCount;

    return segmentCount == 4;
}
int main(){
    IPRange ranges[4];
    if (isValidIP("1.2.3.4", ranges))
    {
        cout << "valid" << endl;
        for (int i = 0; i < 4; ++i) {
            cout << "Segment " << i + 1 << ": " << ranges[i].start << "-" << ranges[i].end << endl;
        }
        if (isIPInRange("150.33.30.120", ranges)) {
            cout << "IP is in range" << endl;
        } else {
            cout << "IP is not in range" << endl;
        }
    }else{
        cout << "invalid" << endl;
        for (int i = 0; i < 4; ++i) {
            cout << "Segment " << i + 1 << ": " << ranges[i].start << "-" << ranges[i].end << endl;
        }
    }
    
    return 0;
}