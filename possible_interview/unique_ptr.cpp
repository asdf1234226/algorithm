template<typename T>
class my_unique_ptr {
public:
    // 构造函数
    explicit my_unique_ptr(T* ptr = nullptr) : ptr_(ptr) {}

    // 删除拷贝构造函数和拷贝赋值运算符，防止拷贝
    my_unique_ptr(const my_unique_ptr&) = delete;
    my_unique_ptr& operator=(const my_unique_ptr&) = delete;

    // 移动构造函数
    my_unique_ptr(my_unique_ptr&& other) noexcept : ptr_(other.ptr_) {
        other.ptr_ = nullptr;
    }

    // 移动赋值运算符
    my_unique_ptr& operator=(my_unique_ptr&& other) noexcept {
        if (this != &other) {
            delete ptr_;            // 释放当前对象持有的资源
            ptr_ = other.ptr_;     // 接管资源
            other.ptr_ = nullptr;  // 防止被移动对象析构时删除资源
        }
        return *this;
    }

    // 析构函数
    ~my_unique_ptr() {
        delete ptr_;
    }

    // 重载 * 和 -> 运算符
    T& operator*() const { return *ptr_; }
    T* operator->() const { return ptr_; }

private:
    T* ptr_; // 原始指针
};

