
#include <Entities.hh>
#include <iostream>

int main()
{
    cobani::core::Entity entity;

    //std::cout << entity.getID() << std::endl;

    cobani::core::Point p1;
    cobani::core::Point p2;
    p1[COBANI_PX] = 12;
    p1[COBANI_PY] = 23;
    p1[COBANI_PZ] = 9;
    p2[COBANI_PX] = 95;
    p2[COBANI_PY] = 39;
    p2[COBANI_PZ] = 26;

    //std::cout << "Puntos longitud : " << p1.lengthTo(p2) << std::endl;

    cobani::core::Vector vec1(p1,p2);
    //std::cout << "Vector longitud : " << vec1.length() << std::endl;

    vec1.normalize();
    std::cout << "|a| = " << vec1.length() << std::endl;


    cobani::core::Point p3;
    cobani::core::Point p4;

    p3[COBANI_PX] = 0;
    p3[COBANI_PY] = 0;
    p3[COBANI_PZ] = 0;
    p4[COBANI_PX] = 1;
    p4[COBANI_PY] = 0;
    p4[COBANI_PZ] = 0;
    cobani::core::Vector vec2(p3,p4);
    //std::cout << "|u| = " << vec2.length() << std::endl;





    return 0;
}
