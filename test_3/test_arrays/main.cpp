#include <QCoreApplication>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(NULL));

//    const int array_size;
    int arr[] = {0,0,0,0,0,0,0};
    int* parr = arr;

    const size_t array_size = sizeof(arr)/sizeof(arr[0]);

    cout << "Number of elements in array = " << sizeof(arr)/sizeof(arr[0]) << endl;
    cout << "\nAdress " << "\t\tValue " << "\tDistance (bytes)" << endl;
    for (uint i = 0; i < array_size; ++i)
        cout << arr + i << "\t" << (*(arr + i) = rand()) << "\t" << (arr + i) - arr << endl;

    cout << "\nAdress " << "\t\tNew Value " << "\tOld Value " << "\tDistance" << endl;

    // перебірка елементів масиву, використовуючи вказівник
    //вивід на екран відбувається справа-наліво!!!!!!!
    for (; (uint)(parr - arr) < array_size; ++parr)
        //Диво-дивне!!! Чому спершу виводиться, а потім +?
        cout << parr << "\t" << (++*parr) << "\t\t" << *parr << "\t\t" << (parr - arr) << endl;
        //Диво-дивне!!! Чому спершу +, а потім виводиться?
//        cout << parr << "\t" << *parr << "\t\t" << (++*parr) << "\t\t" << (parr - arr) << endl;



    cout << endl;
    return 0;
}
