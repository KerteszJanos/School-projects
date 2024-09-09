#ifndef CIRCBUF_H
#define CIRCBUF_H

#include <vector>

template<typename T>
class circular_buffer
{
private:
    T*  m_container;
    std::vector<T>& m_vec;
    int m_size;
    int actualSize;
    int fstInd;
    int endInd;
public:
    circular_buffer(T* container, int size) : m_container(container), m_size(size), actualSize(0), fstInd((0)), endInd((-1)), m_vec(NULL) {}
    template<int N>
    circular_buffer(int(&container)[N]) : m_container(container), m_size(N), actualSize(0), fstInd((0)), endInd((-1)) {}
    circular_buffer(std::vector<T>& vec) : m_vec(vec), m_size(vec.size()), actualSize(0), fstInd((0)), endInd((-1)){}

    void insert(T element)
    {
        if(actualSize < m_size)
        {
            if(endInd + 1 < m_size)
            {
                endInd++;
            }
            else
            {
                endInd = 0;
            }
            m_container[endInd] = element;
            actualSize++;
        }
    }

    int size()
    {
        return actualSize;
    }

    T read()
    {
        if(actualSize != 0)
        {
            T temp = m_container[fstInd];
            m_container[fstInd] = { NULL };
            actualSize--;
            if(fstInd + 1 < m_size)
            {
                fstInd++;
            }
            else
            {
                fstInd = 0;
            }
            return temp;
        }
        throw new std::exception();
    }

    int capacity()
    {
        return m_size;
    }
};

#endif // CIRCBUF_H
