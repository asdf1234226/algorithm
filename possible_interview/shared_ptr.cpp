template<typename T>
class my_shared_ptr {
public:
    // 构造函数
    my_shared_ptr(T* ptr) : ptr_(ptr), count_(new int(1)) {}

    //拷贝构造函数是创建新对象，赋值是作用于另一个已经存在的对象；所以拷贝只需要复制并引用计数+1
    //赋值运算符需要减少当前对象的引用（如果0要delete），还要判断是否自引用

    // 复制(拷贝)构造函数
    // my_shared_ptr(const my_shared_ptr& other){
    //     ptr_=other.ptr_;
    //     count_=other.count_;
    //     (*count_)++;
    // }
    my_shared_ptr(const my_shared_ptr& other) : ptr_(other.ptr_), count_(other.count_) {
        (*count_)++;
    }

    // 赋值运算符,一般返回指向当前对象的引用（避免不必要的）
    my_shared_ptr& operator=(const my_shared_ptr& other) {
        // 自赋值检查
        if (this != &other) {
            //在my_shared_ptr指向另一个对象之前，要减少当前对象的引用计数，如果计数0,
            //没有my_shared_ptr实例管理这个对象，应该删除，避免内存泄露
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
