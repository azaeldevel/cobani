
#include <Entities.hh>
#include <iostream>

int main()
{
    cobani::core::Entity entity;

    std::cout << entity.getID() << std::endl;

    cobani::core::Point p1;
    cobani::core::Point p2;
    p1[COBANI_PX] = 12;
    p1[COBANI_PX] = 23;
    p1[COBANI_PX] = 9;
    p2[COBANI_PX] = 95;
    p2[COBANI_PX] = 39;
    p2[COBANI_PX] = 26;

    std::cout << "Puntos longitud : " << p1.lengthTo(p2) << std::endl;

    cobani::core::Vector vec1(p1,p2);
    std::cout << "Vectoer longitud : " << vec1.length() << std::endl;

    return 0;
}
