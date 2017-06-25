#include <iostream>
#include "uvector_h.h"

using namespace std;

int main()
{
    uVector V1 = {1,2,3};
    uVector V2 = {1,2,3};
    uVector V3 = {1,1,1};
    V3 = V1;
    cout << "Vector 3 : V3=V1 : " << V3.getX() << " , " << V3.getY() << " , " << V3.getZ() << endl;
    V3 = V1 + V2;
    cout << "Vector 3 : V3=V1+V2 : " << V3.getX() << " , " << V3.getY() << " , " << V3.getZ() << endl;
    V3 = V2 + V1;
    cout << "Vector 3 : V3=V2+V1 : " << V3.getX() << " , " << V3.getY() << " , " << V3.getZ() << endl;
    V3 = V1 - V2;
    cout << "Vector 3 : V3=V1-V2 : " << V3.getX() << " , " << V3.getY() << " , " << V3.getZ() << endl;
    return 0;
}
