#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include"vector.cpp"

template <typename T>
class Vector
{
private:
    size_t lenght;
    size_t capacity;
    T* vector;

    static size_t allObjCount;
    static size_t currentObjCount;
public:
    Vector();
    explicit Vector(size_t);
    Vector(const Vector&);
    ~Vector();

    T getVectorElement (size_t) const;
    size_t getLenght () const;
    void printVector() const;
    void setElement(size_t, T);

    Vector& operator= (const Vector&);
    bool operator== (const Vector&) const;
    T& operator[] (size_t) ;
    const T& operator[] (size_t) const;
    Vector& swap (Vector&);

    void resize(size_t);
};

template <typename T>
size_t Vector<T>::allObjCount = 0;

template <typename T>
size_t Vector<T>::currentObjCount = 0;

template <typename T>
Vector<T>::Vector(): lenght(0), capacity(0)
{
     vector = new T [lenght];
    ++allObjCount;
    ++currentObjCount;
}

template <typename T>
Vector<T>::Vector(size_t size): lenght(size), capacity(0)
{
    vector = new T [lenght];
    ++allObjCount;
    ++currentObjCount;
}

template <typename T>
Vector<T>::Vector(const Vector& copy)
{
    lenght = copy.lenght;
    capacity = copy.capacity;
    ++allObjCount;
    ++currentObjCount;
    vector = new T [copy.lenght];
    for (size_t i = 0; i < copy.lenght; ++i)
        vector[i] = copy.vector[i];
}

template <typename T>
Vector<T>::~Vector()
{
    delete[] vector;
    --currentObjCount;
 //    std::cout << "\ndestructor";
}

template<typename T>
T Vector<T>::getVectorElement (size_t element) const
{
    if (element <= capacity )
        return vector[element];
    return -1;
}

template<typename T>
size_t Vector<T>::getLenght () const
{
    return lenght;
}

template<typename T>
void Vector<T>::printVector() const
{
    for (size_t i = 0; i < lenght; ++i)
        std::cout << vector[i] << " ";
}

template<typename T>
void Vector<T>::setElement(size_t number, T value)
{
    vector[number] = value;
}

template <typename T>
Vector<T>& Vector<T>::operator= (const Vector& copy)
{
 //    std::cout << "\nold address vector : " << &vector;
    delete [] vector;
    lenght = copy.lenght;
    capacity = copy.capacity;
    vector = new T [lenght] {0};
 //    std::cout << "\nnew address vector : " << &vector;
    for (size_t i = 0; i < lenght; ++i)
        vector[i] = copy.vector[i];
    return *this;
}

template <typename T>
bool Vector<T>::operator== (const Vector& copy) const
{
 //    std::cout << "\nFNC compare\n";
    if (lenght != copy.lenght || capacity!= copy.capacity)
        return false;
    for (size_t i = 0; i < lenght; ++i)
        if (vector[i] != copy.vector[i])
            return false;
    return true;
}

template<typename T>
T& Vector<T>::operator[] (size_t element)
{
 //    if (element < capacity)
        return vector[element];
 //    else if (element == capacity)

}

template <typename T>
Vector<T>& Vector<T>::swap(Vector<T>& second)
{
    T* tmpVector = second.vector;
    size_t tmpLenght = second.lenght;
    size_t tmpCapacity = second.capacity;
    second.vector = vector;
    second.lenght = lenght;
    second.capacity = capacity;
    vector = tmpVector;
    lenght = tmpLenght;
    capacity = tmpCapacity;
    return *this;
}

template<typename T>
void Vector<T>::resize(size_t newSize)
{
    T* tmp = new T [newSize];
    for (size_t i = 0; i < newSize; ++i)
        tmp[i] = vector[i];
    if (newSize > lenght)
        for (size_t i = lenght; i < newSize; ++i)
            tmp[i] = 0;
    delete[] vector;
    vector = tmp;
    lenght = newSize;
}



#endif // VECTOR_H
