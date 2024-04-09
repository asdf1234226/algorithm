template<typename T>
class my_shared_ptr {
public:
    // 构造函数
    my_shared_ptr(T* ptr) : ptr_(ptr), count_(new int(1)) {}

    // 复制构造函数
    my_shared_ptr(const my_shared_ptr& other) : ptr_(other.ptr_), count_(other.count_) {
        (*count_)++;
    }

    // 赋值运算符
    my_shared_ptr& operator=(const my_shared_ptr& other) {
        // 自赋值检查
        if (this != &other) {
            // 如果当前对象已经没有其他 shared_ptr 指向它，删除它
            if (--(*count_) == 0) {
                delete ptr_;
                delete count_;
            }
            ptr_ = other.ptr_;
            count_ = other.count_;
            (*count_)++;
        }
        return *this;
    }

    // 析构函数
    ~my_shared_ptr() {
        if (--(*count_) == 0) {
            delete ptr_;
            delete count_;
        }
    }

    // 重载 * 和 -> 运算符
    T& operator*() const { return *ptr_; }
    T* operator->() const { return ptr_; }

private:
    T* ptr_;
    int* count_;
};
