template<typename T>
class shared_ptr{
public:
    shared_ptr(T* ptr=nullptr){//默认构造函数
        if(ptr){
            _ptr=ptr;
            _count=new size_t(1);
        }else
        {
            _ptr=nullptr;
            _count=nullptr;
        }
    }

    //拷贝构造函数
    shared_ptr(const shared_ptr& other){
        if(this != &other){
            this->_count=other->_count;
            this->_ptr=other->_ptr;
            *(this->_count)++;
        }
    }

    // 赋值运算符
    shared_ptr& operator=(const shared_ptr& other){
        if (this->_ptr == other->_ptr)
        {
            return *this;
        }
        if (this->_ptr)
        {
            *(this->_count)--;
            if (*(this->_count)==0)
            {
                delete this->_ptr;
                delete this->_count;
            }
        }
        this->_ptr=other->_ptr;
        this->_count=other->_count;
        *(this->_count)++;
        return *this;
    }
    //析构函数
    ~shared_ptr(){
        *(this->_count)--;
        if(*(this->_count)==0){
            delete this->_count;
            delete this->_ptr;
        }
    }

    //指针访问
    T* operator->(){
        return this->_ptr;
    }

    //解引用
    T& operator*(){
        return *(this->_ptr);
    }

private:
    T* _ptr; // 管理的对象
    int* _count; // 引用计数
};