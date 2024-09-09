#ifndef CIRCBUF_H
#define CIRCBUF_H

//#include </*something*/>

template<typename T>
class circular_buffer
{
private:
    T*  m_container;
    int m_size;
    int actualSize;
public:
    circular_buffer(T* container, int size) : m_container(container), m_size(size), actualSize(0) {}

    void insert(T element)
    {
        if(actualSize < m_size)
        {
            m_container[actualSize] = element;
            actualSize++;
        }
    }

    int size()
    {
        return actualSize;
    }
};

#endif // CIRCBUF_H
