
#include <math.h>


#include "Entities.hh"

#ifdef DEBUG
    #include <iostream>
#endif // DEBUG

namespace cobani::core
{


    /**
    **      World
    **/







    /**
    **      Object
    **/

    Object::Object(int sizepoly) : points(sizepoly)
    {

    }
    const std::vector<Point>& Object::getPoints()const
    {
        return points;
    }
    bool Object::move(const Vector& v)
    {

        return true;
    }
    bool Object::rotate(const Point& u)
    {

        return true;
    }


    /**
    **      Atomo
    **/
    Atomo::Atomo(const Point& p)
    {
        point = p;
    }
    const Point& Atomo::getPoint()const
    {
        return point;
    }
    bool Atomo::move(const Vector& v)
    {

        return true;
    }
    bool Atomo::rotate(const Point& u)
    {

        return true;
    }




    /**
    **      Matter
    **/







    /**
    **      Entity
    **/


    Entity::Entity()
    {
        id = "Entidad";
    }
    const std::string& Entity::getID()const
    {
        return id;
    }






    /**
    **      Vector
    **/
    Vector::Vector(const Point& o, const Point& d)
    {
        origin = o;
        direction = d;
    }
    bool Vector::normalize()
    {
        COBANI_TYPE_DECIMAL lenvect = length();
        direction[COBANI_PX] = ((direction[COBANI_PX]/lenvect) + origin[COBANI_PX]);
        direction[COBANI_PY] = ((direction[COBANI_PY]/lenvect) + origin[COBANI_PY]);
        direction[COBANI_PZ] = ((direction[COBANI_PZ]/lenvect) + origin[COBANI_PZ]);

        return true;
    }
    COBANI_TYPE_DECIMAL Vector::length()const
    {
        return origin.lengthTo(direction);
    }










    COBANI_TYPE_DECIMAL Point::lengthTo(const Point& to)const
    {
        COBANI_TYPE_INTEGER lengx = to[COBANI_PX] - at(COBANI_PX);
        COBANI_TYPE_INTEGER lengy = to[COBANI_PY] - at(COBANI_PY);
        COBANI_TYPE_INTEGER lengz = to[COBANI_PZ] - at(COBANI_PZ);

        COBANI_TYPE_DECIMAL leng = pow(lengx,2) + pow(lengy,2) + pow(lengz,2);
        leng = sqrt(leng);
        return leng;
    }
    /**
    **      Point
    **/
    void Point::setX(COBANI_TYPE_DECIMAL v)
    {
        at(COBANI_PX) = v;
    }
    void Point::setY(COBANI_TYPE_DECIMAL v)
    {
        at(COBANI_PY) = v;
    }
    void Point::setZ(COBANI_TYPE_DECIMAL v)
    {
        at(COBANI_PZ) = v;
    }
    COBANI_TYPE_DECIMAL Point::getX()const
    {
        return at(COBANI_PX);
    }
    COBANI_TYPE_DECIMAL Point::getY()const
    {
        return at(COBANI_PY);
    }
    COBANI_TYPE_DECIMAL Point::getZ()const
    {
        return at(COBANI_PZ);
    }
    Point::Point() : std::vector<COBANI_TYPE_DECIMAL>(COBANI_DIMENSION)
    {

    }
}
