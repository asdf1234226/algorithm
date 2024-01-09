template<typename T>
class shared_ptr {
public:
    // 构造函数
    shared_ptr(){
        ptr_=nullptr;
        count_=new int(1);
    }
    shared_ptr(){
        
    }

    // 拷贝构造函数
    shared_ptr(const shared_ptr& other) {
        if (this != &other) {
            this->ptr_ = other.ptr_;
            this->count_ = other.count_;
            (*this->count_)++;
        }
    }

    // 赋值运算符
    shared_ptr& operator=(const shared_ptr& other) {
        if (this->ptr_ == other.ptr_) {
            return *this;
        }

        if (this->ptr_) {
            (*this->count_)--;
            if ((*this->count_) == 0) {
                delete this->ptr_;
                delete this->count_;
            }
        }

        this->ptr_ = other.ptr_;
        this->count_ = other.count_;
        (*this->count_)++;

        return *this;
    }

    // 析构函数
    ~shared_ptr() {
        (*this->count_)--;
        if ((*this->count_) == 0) {
            delete this->ptr_;
            delete this->count_;
        }
    }

    // 解引用操作符
    T& operator*() {
        return *(this->ptr_);
    }

    // 指针访问操作符
    T* operator->() {
        return this->ptr_;
    }

private:
    T* ptr_; // 管理的对象
    int* count_; // 引用计数
};
