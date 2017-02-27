#ifndef STACK_H
#define STACK_H
#include <cstring>
#include <iostream>
template <typename Type> class Stack
{
private :
    Type * data;
    unsigned int len;
    unsigned int capacity;
public:
    class StackException
    {
    public:
        const char * reason;
        StackException():
            reason("default reason")
        {}
        StackException(const char * reason_):
            reason(reason_)
        {}
        std :: ostream & operator << (std :: ostream & os) const
        {
            os << reason << std :: endl;
            return os;
        }
    };
    ~Stack()
    {
        delete [] data;
    }
    Stack(Stack & copy):
        data(new Type [copy.capacity]),
        len(copy.len),
        capacity(copy.capacity)
    {
        memset(data,0,sizeof(Type)*capacity);
        memcpy(data,copy.data,len*sizeof(Type));
    }
    Stack():
        data(new Type [10]),
        len(0),
        capacity(10)
    {}
    Stack(unsigned int capacity_):
        data(new Type(capacity_)),
        len(0),
        capacity(capacity_)
    {
        memset(data,0,sizeof(Type));
    }
    void freeMem()
    {
        Type * tmp = new Type[len];
        memcpy(tmp,data,len*sizeof(Type));
        delete [] data;
        data = tmp;
        capacity = len;
    }
    void setMemLen(unsigned int capacity_)
    {
        if(capacity_ < len)
            return ;
        Type * tmp = new Type [capacity_];
        memset(tmp,0,sizeof(Type)*capacity_);
        memcpy(tmp,data,sizeof(Type)*len);
        delete [] data;
        data = tmp;
        capacity = capacity_;
    }
    void push(Type & elm)
    {
        if(len == capacity)
            setMemLen(capacity * 1.4);
        data[len] = elm;
        len ++;
    }
    Type  pop() throw (StackException)
    {
        if(len == 0)
            throw StackException("pop exception");
        if(len < capacity*0.5 && capacity > 19)
            setMemLen(capacity*0.5);
        len --;
        return data[len];
    }
    void freeStack()
    {
        delete [] data;
        data = new Type [10];
        memset(data,0,sizeof(Type)*10);
        capacity = 10;
        len = 0;
    }
};
#endif // STACK_H
