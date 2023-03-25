#ifndef __TEMPLATEBLOB_H__
#define __TEMPLATEBLOB_H__

#include "TemplateBlobPtr.h"

using namespace std;

template <typename>     class BlobPtr;
template <typename>     class Blob;
template <typename T>   bool operator==(const Blob<T> &, const Blob<T>&);

template <typename T> 
class Blob
{
friend BlobPtr<T>;
template <typename U> friend void print(const Blob<U> &);
template <typename U> friend void print(Blob<U> &);
// friend bool operator==<T> (const Blob<T> &, const Blob<T> &);
public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;

    /** 构造函数 */
    Blob();
    template <typename IT> Blob(IT, IT);
    Blob(std::initializer_list<T> il);

    /** Blob中元素数目 */
    size_type size()  const {return data->size();}
    bool empty() const {return data->empty();}
    
    /** 添加和删除元素 */
    void push_back(const  T  &t) {data->push_back(t);}
    /** 移动版本 */
    void push_back(T &&t) {data->push_back(std::move(t));}
    void pop_back();

    /** 元素访问 */
    T& front();
    T& back();
    const T& front() const;
    const T& back() const;
    T& operator[](size_type i);
    const T& operator[](size_type i) const;

protected:

private:
    std::shared_ptr<std::vector<T>> data;
    void check(size_type i, const std::string &msg) const;
};

template <typename T> 
Blob<T>::Blob():data(std::make_shared<std::vector<T>>()) {}
template <typename T> 
Blob<T>::Blob(std::initializer_list<T> il):data(std::make_shared<std::vector<T>>(il)) {}
template <typename T>
template <typename IT>
Blob<T>::Blob(IT begin, IT end):data(std::make_shared<std::vector<T>>(begin, end)){}


template <typename T>
void  Blob<T>::pop_back()
{
    check(0,"pop back on empty Blob.");
    return data->pop_back();
}
template <typename T>
T& Blob<T>::front()
{
    check(0, "front on empty Blob.");

    return data->front();
}

template <typename T> 
T& Blob<T>::back()
{
    return data->back();
}

template <typename T> 
const T& Blob<T>::front() const
{
    check(0, "front on empty Blob.");
    return data->front();
}

template <typename T> 
const T& Blob<T>::back() const
{
    check(0,"back on empty Blob.");
    return data->back();
}

template <typename T> 
T& Blob<T>::operator[](size_type n)
{
    check(n,"allocate Blob.");
    return (*data)[n];
}

template <typename T> 
const T& Blob<T>::operator[](size_type n) const
{
    check(n,"allocate Blob.");
    return (*data)[n];
}

template <typename T> 
void Blob<T>::check(size_type i, const std::string &msg) const
{
    if(i >= data->size())
    {
        cout << i << " " << data->size() << endl;
        throw std::out_of_range(msg);
    }
}

template <typename T>
void print(const Blob<T> &obj)
{
    for(size_t i = 0; i < obj.size(); i++ )
    {
        cout << obj[i] << " ";
    }
    cout << endl;
}

template <typename U>
void print(Blob<U> &obj)
{
    for(size_t i = 0; i < obj.size(); i++ )
    {
        cout << obj[i] << " ";
    }
    cout << endl;
}

template <typename T>
bool operator==(const Blob<T> &lhs, const Blob<T> &rhs)
{
    return (lhs.data == rhs.data);
}


#endif