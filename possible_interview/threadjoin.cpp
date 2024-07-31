#include <iostream>

class Widget {
    int a;
    double b;
};

int main() {
    Widget w;
    Widget& refW = w; // 创建引用

    std::cout << "Size of Widget: " << sizeof(Widget) << std::endl; // 显示 Widget 的大小
    std::cout << "Size of reference: " << sizeof(refW) << std::endl; // 显示引用的大小

    return 0;
}
