#ifndef _TEMPLATEBLOBPTR_H__
#define _TEMPLATEBLOBPTR_H__

template <typename> class Blob;

template <typename T> 
class BlobPtr
{
friend class Blob<T>;
public:
    BlobPtr():curr(0) {}
    BlobPtr(Blob<T> &a, std::size_t sz = 0):wptr(a.data),curr(sz) {}

    T& operator*() const {auto p = check(curr, "dereference past end."); return (*p)[curr];}
    BlobPtr& operator++();  /** 前置运算符 */
    BlobPtr& operator--();
    BlobPtr operator++(int);
    BlobPtr operator--(int);


protected:
private:
    std::shared_ptr<std::vector<T>> check(std::size_t, const std::string &) const;
    std::weak_ptr<std::vector<T>> wptr;
    std::size_t curr;
};

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator++()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator++(int)
{
    BlobPtr ret = *this;
    ++*this;
    return this;
}

#endif