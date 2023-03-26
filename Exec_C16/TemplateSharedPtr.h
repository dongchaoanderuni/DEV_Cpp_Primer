#ifndef __TEMPLATE_SHAREDPTR_H__
#define __TEMPLATE_SHAREDPTR_H__

template <typename T>
class tSharedPtr
{
public:
    tSharedPtr():ptr(nullptr), ref_count(new size_t(0)), deleter(nullptr) {}
    explicit tSharedPtr(T* p): ptr(p), ref_count(new size_t(1)), deleter(nullptr) {}
    tSharedPtr(T* p, void (*d)(T*)): ptr(p), ref_count(new size_t(1)), deleter(d) {}
    tSharedPtr(const tSharedPtr<T>& other):ptr(other.ptr), ref_count(other.ref_count) {++(*ref_count);}
    void reset() noexcept {free(); ptr = nullptr; ref_count = nullptr;}
    void reset(T* p) {free(); ptr = p; ref_count = new size_t(1); deleter = nullptr;}
    void reset(T* p, void (*d)(T*)){free(); ptr = p; ref_count = new size_t(1); deleter = d;}
    ~tSharedPtr() {free();}
    
    tSharedPtr &operator=(const tSharedPtr&);
    T& operator*() const {return *ptr;}
    T* operator->() const {return ptr;}

protected:

private:
    void free();
    T* ptr;
    size_t* ref_count;
    void (*deleter)(T*);
};

template <typename T>
tSharedPtr<T>& tSharedPtr<T>::operator=(const tSharedPtr<T>& other)
{
    if(this != &other)
    {
        free();
        ptr = other.ptr;
        ref_count = other.ref_count;
        deleter = other.deleter;
        ++(*ref_count);
    }
    return *this;
}

template <typename T>
void tSharedPtr<T>::free()
{
    if(--(*ref_count)==0)
    {   
        if (deleter)
        {   
            deleter(ptr);
        }
        else
        {
            delete ptr;
        }
        delete ref_count;

        ptr = nullptr;
        ref_count = nullptr;
        deleter = nullptr;
    }
}

#endif