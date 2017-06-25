#include <iostream>
#include "uvector_h.h"

using namespace std;

int main()
{
    uVector V1 = {1,2,3};
    uVector V2 = {2,3,4};
    uVector V3 = {1,1,1};
    cout << "V1 : " << V1 << endl;
    cout << "V2 : " << V2 << endl;
    cout << "V3 : " << V3 << endl;
    V3 = V1;
    cout << "V3=V1 : " << V3 << endl;
    V3 = V1 + V2;
    cout << "V3=V1+V2 : " << V3 << endl;
    V3 = V2 + V1;
    cout << "V3=V2+V1 : " << V3 << endl;
    V3 = V1 - V2;
    cout << "V3=V1-V2 : " << V3 << endl;
    V3 = V1 * 2;
    cout << "V3=V1*2 : " << V3 << endl;
    V3 = 2 * V1;
    cout << "V3=2*V1 : " << V3 << endl;
    return 0;
}
