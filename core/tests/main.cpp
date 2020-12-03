
#include <Entities.hh>
#include <iostream>

int main()
{
    cobani::core::Point p1;
    cobani::core::Point p2;
    p1[COBANI_PX] = 12;
    p1[COBANI_PY] = 23;
    p1[COBANI_PZ] = 9;
    p2[COBANI_PX] = 95;
    p2[COBANI_PY] = 39;
    p2[COBANI_PZ] = 26;

    COBANI_TYPE_DECIMAL lp1p2 = p1.lengthTo(p2);
    if(lp1p2 > 86.2207 and lp1p2 < 86.2205)
    {
        std::cout << "p1.lengthTo(p2) != " << lp1p2 << std::endl;
    }

    cobani::core::Vector vec1(p1,p2);
    COBANI_TYPE_DECIMAL lenvec1 = vec1.length();
    if(lenvec1 > 86.2207 and lenvec1 < 86.2205)
    {
        std::cout << "vec1.length() != " << lenvec1 << std::endl;
    }

    vec1.normalize();
    COBANI_TYPE_DECIMAL lenveca = vec1.length();
    if(lenveca != 1.0)
    {
        std::cout << "|a| = " << lenveca << std::endl;
    }

    cobani::core::Point p3;
    cobani::core::Point p4;
    p3[COBANI_PX] = 0;
    p3[COBANI_PY] = 0;
    p3[COBANI_PZ] = 0;
    p4[COBANI_PX] = 1;
    p4[COBANI_PY] = 0;
    p4[COBANI_PZ] = 0;
    cobani::core::Vector vec2(p3,p4);
    COBANI_TYPE_DECIMAL lenvecu = vec1.length();
    if(lenvecu > 1.1 and lenvecu < 0.9)
    {
        std::cout << "|u| = " << lenvecu << std::endl;
    }







    return 0;
}
