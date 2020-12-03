
#include <math.h>


#include "Entities.hh"

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
    bool Vector::makeUnit()
    {

    }
    COBANI_TYPE_DECIMAL Vector::length()const
    {
        return origin.lengthTo(direction);
    }










    COBANI_TYPE_DECIMAL Point::lengthTo(const Point& to)const
    {
        COBANI_TYPE_DECIMAL lengx = (at(COBANI_PX) - to[COBANI_PX]);
        COBANI_TYPE_DECIMAL lengy = (at(COBANI_PY) - to[COBANI_PY]);
        COBANI_TYPE_DECIMAL lengz = (at(COBANI_PZ) - to[COBANI_PZ]);

        COBANI_TYPE_DECIMAL leng = pow(lengx,2) + pow(lengy,2) + pow(lengz,2);
        leng = sqrt(leng);
        return leng;
    }
    /**
    **      Point
    **/
    void Point::setX(COBANI_TYPE_INT v)
    {
        at(COBANI_PX) = v;
    }
    void Point::setY(COBANI_TYPE_INT v)
    {
        at(COBANI_PY) = v;
    }
    void Point::setZ(COBANI_TYPE_INT v)
    {
        at(COBANI_PZ) = v;
    }
    COBANI_TYPE_INT Point::getX()const
    {
        return at(COBANI_PX);
    }
    COBANI_TYPE_INT Point::getY()const
    {
        return at(COBANI_PY);
    }
    COBANI_TYPE_INT Point::getZ()const
    {
        return at(COBANI_PZ);
    }
    Point::Point() : std::vector<COBANI_TYPE_INT>(COBANI_DIMENSION)
    {

    }
}
