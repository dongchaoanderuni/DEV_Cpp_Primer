#ifndef __TEMPLATE_UNIQUEPR_H__
#define __TEMPLATE_UNIQUEPR_H__

using namespace std;

template <typename T, typename D = std::default_delete<T>>

class tUniquePtr
{
public:
    explicit tUniquePtr(T* p=nullptr, D d = D{}):ptr(p),deleter(d) {};
    ~tUniquePtr() {reset();}

    tUniquePtr(D d)  {deleter = d;}
    tUniquePtr(tUniquePtr&) = delete;
    tUniquePtr(const tUniquePtr&) = delete;
    tUniquePtr& operator=(tUniquePtr&) = delete;

    tUniquePtr(tUniquePtr&& rhs) noexcept : ptr(rhs.ptr), deleter(std::move(rhs.deleter)){rhs.reset();}
    tUniquePtr& operator=(tUniquePtr&&);

    tUniquePtr& operator=(nullptr_t) {reset();}
    tUniquePtr& operator=(const tUniquePtr&) = delete;

    void  reset(T* rhs = nullptr) noexcept {if(ptr != rhs){if(ptr) {deleter(ptr);} ptr = rhs;}}
    T*    release();

    T& operator*() const {return *ptr;}
    T* operator->() const {return ptr;}
    explicit operator bool() const {return (ptr != nullptr);}

protected:
private:
    T* ptr;
    D deleter;

};

template <typename T, typename D>
tUniquePtr<T,D>& tUniquePtr<T,D>::operator=(tUniquePtr<T,D>&& rhs)
{
    reset(rhs.release());
    deleter = std::move(rhs.deleter);
    return *this;
}

template <typename T, typename D>
T* tUniquePtr<T,D>::release()
{
    T* ret = ptr;
    ptr = nullptr;
    return ret;
}

#endif
