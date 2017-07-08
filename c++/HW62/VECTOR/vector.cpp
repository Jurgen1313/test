#include "vector.h"



//template <typename T>
//Vector<T>::Vector(const Vector& copy)
//{
//    lenght = copy.lenght;
//    ++allObjCount;
//    ++currentObjCount;
//    vector = new T [copy.lenght];
//    for (size_t i = 0; i < copy.lenght; ++i)
//        vector[i] = copy.vector[i];
//}

//template <typename T>
//Vector<T>& Vector<T>::operator= (const Vector& copy)
//{
//    delete [] vector;
//    lenght = copy.lenght;
//    vector = new T [copy.lenght];
//    for (size_t i = 0; i < copy.lenght; ++i)
//        vector[i] = copy.vector[i];
//}

//template <typename T>
//bool Vector<T>::operator== (const Vector& copy)
//{
//    if (this->lenght != copy.lenght)
//        return false;
//    for (size_t i = 0; i < lenght; ++i)
//    {
//        if (vector[i] != copy.lenght[i])
//            return false;
//    }
//    return true;
//}

//template<typename T>
//void Vector<T>::swap(Vector& first, Vector& second)
//{
//    Vector *tmp;
//    tmp = &first;
//    &first = &second;
//    &second = tmp;
//}




