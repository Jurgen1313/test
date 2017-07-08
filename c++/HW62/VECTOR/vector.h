#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

template <typename T>
class Vector
{
private:
    size_t lenght;
    T* vector;

    static size_t allObjCount;
    static size_t currentObjCount;
public:
    Vector();
    Vector(size_t );
    Vector(const Vector&);
    ~Vector();

    T getVectorElement (size_t) const;
    size_t getLenght () const;
    void printVector() const;
    void setElement(size_t, T);

    Vector& operator= (const Vector&);
    bool operator== (const Vector&);
    T operator[] (size_t);
    Vector& swap (Vector&);
    Vector& resize(Vector&);

    void popback();
    void pushback(T);
};

template <typename T>
size_t Vector<T>::allObjCount = 0;

template <typename T>
size_t Vector<T>::currentObjCount = 0;


template <typename T>
Vector<T>::Vector(): lenght(0)
{
    vector = new T [lenght] {0};
    ++allObjCount;
    ++currentObjCount;
//    std::cout << "\ndefault constructor";
}

template <typename T>
Vector<T>::Vector(size_t size)
{
    lenght = size;
    vector = new T [lenght] {0};
    ++allObjCount;
    ++currentObjCount;
//    std::cout << "\nconstructor";
}

template <typename T>
Vector<T>::~Vector()
{
    delete[] vector;
    --currentObjCount;
//    std::cout << "\ndestructor";
}


template <typename T>
Vector<T>::Vector(const Vector& copy)
{
    lenght = copy.lenght;
    ++allObjCount;
    ++currentObjCount;
    vector = new T [copy.lenght];
    for (size_t i = 0; i < copy.lenght; ++i)
        vector[i] = copy.vector[i];
}

template <typename T>
Vector<T>& Vector<T>::operator= (const Vector& copy)
{
//    std::cout << "\nold address vector : " << &vector;
    delete [] vector;
    lenght = copy.lenght;
    vector = new T [lenght] {0};
//    std::cout << "\nnew address vector : " << &vector;
    for (size_t i = 0; i < lenght; ++i)
        vector[i] = copy.vector[i];
    return *this;
}

template <typename T>
bool Vector<T>::operator== (const Vector& copy)
{
//    std::cout << "\nFNC compare\n";
    if (lenght != copy.lenght)
        return false;
    for (size_t i = 0; i < lenght; ++i)
        if (vector[i] != copy.vector[i])
            return false;
    return true;
}

template<typename T>
T Vector<T>::operator[] (size_t element)
{
    return vector[element];
}

template <typename T>
Vector<T>& Vector<T>::swap(Vector<T>& second)
{
    T* tmpVector = second.vector;
    size_t tmpLenght = second.lenght;
    second.vector = vector;
    second.lenght = lenght;
    vector = tmpVector;
    lenght = tmpLenght;

    return *this;
}

template<typename T>
T Vector<T>::getVectorElement (size_t element) const
{
    return vector[element];
}

template<typename T>
void Vector<T>::printVector() const
{
    for (size_t i = 0; i < lenght; ++i)
        std::cout << vector[i] << " ";
}

template<typename T>
size_t Vector<T>::getLenght () const
{
    return lenght;
}

template<typename T>
void Vector<T>::setElement(size_t number, T value)
{
    vector[number] = value;
}


#endif // VECTOR_H
