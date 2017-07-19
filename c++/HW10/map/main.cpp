#include <iostream>
#include <fstream>
#include <cstring>
#include <map>
#include <algorithm>
#include <cctype>

using namespace std;


template<typename A, typename B>
std::pair<B,A> flip_pair(const std::pair<A,B> &p)
{
    return std::pair<B,A>(p.second, p.first);
}

template<typename A, typename B>
std::multimap<B,A> flip_map(const std::map<A,B> &src)
{
    std::multimap<B,A> dst;

    std::transform(src.begin(), src.end(), std::inserter(dst, dst.begin()), flip_pair<A,B>);
    return dst;
}

int main()
{

    fstream inFile;
    fstream outFile;
    fstream outFile2;

    // Open file only for reading
//    inFile.open("../map/test.txt",  std::fstream::in);
    inFile.open("../map/big.txt",  std::fstream::in);

    //remove old file JUST FOR TESTING -----------///////
    remove("../map/NEWtest.txt");
    remove("../map/NEWtest22.txt");
    remove("../map/test123.txt");

    if (inFile.fail())
        cout << "Can't open file" << endl;


    outFile2.open("../map/test123.txt",  std::fstream::out | std::fstream::app);
    if (outFile.fail())
        cout << "Can't open test file " << endl;



    std::map <string, int> mapArr;
    std::map <string, int> mapArr2;
//    while (!inFile.eof())
        string item;
    while (inFile >> item)
    {
        for (std::string::iterator itr = item.begin(); itr < item.end(); ++itr)
            if ( !isalnum(*itr))
            {
                outFile2 << "\nitr: " << *itr << " item: " << item << " new item: ";
                item.erase(itr);
                outFile2 << item;
                --itr;
            }

//        outFile2 << " Last item: " << item << endl;
//                    *(tmp.) = *tmp;
//                *itr = ' ';
//                *itr = *(itr+1);
        mapArr[item]++;
//        string item;
//        inFile >> item;
//        mapArr2[item]++;
//        if (item[item.length() - 1] == ',' || item[item.length() - 1] == '.' ||
//                item[item.length() - 1] == '!' || item[item.length() - 1] == '?' ||
//                item[item.length() - 1] == '-' || item[item.length() - 1] == ':' ||
//                item[item.length() - 1] == '"' || item[item.length() - 1] == ')' ||
//                item[item.length() - 1] == '\'' || item[item.length() - 1] == ']')
//            item = item.substr(0,item.length() - 1);
//        if (item[0] == '"' || item[0] == '(' || item[0] == '#')
//            item = item.substr(1,item.length());
//        mapArr[item]++;
    }

            outFile2.close();
    inFile.close();

    //open file only for writing
    outFile.open("../map/NEWtest.txt",  std::fstream::out | std::fstream::app);

    if (outFile.fail())
        cout << "Can't open file 1" << endl;

    for (std::map <string, int>::iterator it = mapArr.begin(); it != mapArr.end(); ++it)
        outFile << it->first << "\t\t === " << it->second <<endl;
    outFile.close();

    std::multimap<int, string> dst = flip_map(mapArr);

    size_t sum = 0;

    //open file only for writing
    outFile.open("../map/NEWtest22.txt",  std::fstream::out | std::fstream::app);
    if (outFile.fail())
        cout << "Can't open file 2" << endl;
//    for (std::map <int, string>::iterator it2 = dst.begin(); it2 != dst.end(); ++it2)
    for (std::map <int, string>::iterator it2 = --dst.end(); it2 != --dst.begin(); --it2)
    {
        outFile << it2->second << "\t === " << it2->first <<endl;
        sum += it2->first;
    }
    outFile.close();

    cout << "\n Word number : " << sum << endl;

    return 0;
}
