

#include <gl/gl.h>

#include "Entities.hh"

#ifdef DEBUG
    #include <iostream>
#endif // DEBUG

namespace cobani::core
{


    /**
    **      World
    **/

    //funtions





    /**
    **      Object
    **/
    Object::Object(const Object& obj)
    {
        atoms = obj.atoms;
    }
    Object::Object()
    {

    }
    Object::Object(int sizepoly) : atoms(sizepoly)
    {

    }
    Object::~Object()
    {

    }
    const std::vector<Atom*>& Object::getAtoms()const
    {
        return atoms;
    }


    /**
    **      Atom
    **/
    Atom::Atom()
    {

    }
    Atom::Atom(const Vector& p)
    {
        position = p;
        position.getDirection().normalize();
    }
    Atom::~Atom()
    {

    }

    //getter
    const Vector& Atom::getPosition()const
    {
        return position;
    }

    //setter
    void Atom::setPosition(const Vector& v)
    {
        position = v;
        position.getDirection().normalize();
    }

    //funtions



    /**
    **      Matter
    **/







    /**
    **      Entity
    **/

    Entity::~Entity()
    {
    }
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
    Vector::Vector()
    {
    }
    Vector::Vector(const Vector& obj)
    {
        origin = obj.origin;
        direction = obj.direction;
    }
    Vector::Vector(const Point& o, const Point& d)
    {
        origin = o;
        direction = d;
    }

    //getter
    Point& Vector::getOrigin()
    {
        return origin;
    }
    Point& Vector::getDirection()
    {
        return direction;
    }
    //operator
    const Vector& Vector::operator +(const Vector& v)
    {
        #if COBANI_DIMENSION >= 2
        origin[COBANI_PX] = v.origin[COBANI_PX] + v.origin[COBANI_PX];
        origin[COBANI_PY] = v.origin[COBANI_PY] + v.origin[COBANI_PY];
        direction[COBANI_PX] = v.direction[COBANI_PX] + v.direction[COBANI_PX];
        direction[COBANI_PY] = v.direction[COBANI_PY] + v.direction[COBANI_PY];
        #endif


        return *this;
    }
    const Vector& Vector::operator *(COBANI_TYPE_DECIMAL v)
    {
        #if COBANI_DIMENSION >= 2
        origin[COBANI_PX] = origin[COBANI_PX] * v;
        origin[COBANI_PY] = origin[COBANI_PY] * v;
        direction[COBANI_PX] = direction[COBANI_PX] * v;
        direction[COBANI_PY] = direction[COBANI_PY] * v;
        #endif

        return *this;
    }
    const Vector& Vector::operator =(const Vector& v)
    {
        #if COBANI_DIMENSION >= 2
        origin = v.origin;
        direction = v.direction;
        #endif


        return *this;
    }

    //funtions
    COBANI_TYPE_DECIMAL Vector::length()const
    {
        return origin.lengthTo(direction);
    }
    bool Vector::rotate(const Point& eje,COBANI_TYPE_DECIMAL theta)
    {
        COBANI_TYPE_DECIMAL lengPen = eje.lengthTo(Point::O);
        if(fabs(lengPen - 1.0) >= COBANI_EPSILON)
        {
            std::string msg = "El vector usado para la rotacion deve tener longitud unitaria, ahora tiene '";
            msg = msg + std::to_string(lengPen) + "'";
            throw Exception(__FILE__,__LINE__,msg);
        }
        Point orthoeje;
        orthoeje.setX(-1.0 * eje.getY());
        orthoeje.setY(eje.getX());
        #if COBANI_DIMENSION >= 2
        //X'
        direction[COBANI_PX] = eje[COBANI_PX] * direction[COBANI_PX] - eje[COBANI_PY] * direction[COBANI_PY];
        //Y'
        direction[COBANI_PY] = eje[COBANI_PY] * direction[COBANI_PX] + eje[COBANI_PX] * direction[COBANI_PY];
        #endif

        return true;
    }













    /**
    **      Point
    **/
    #if COBANI_DIMENSION >= 2
    Point Point::O(0,0);
    #endif
    #if COBANI_DIMENSION >= 3
    Point Point::O(0,0,0);
    #endif

    #if COBANI_DIMENSION >= 2
    Point::Point(COBANI_TYPE_DECIMAL x, COBANI_TYPE_DECIMAL y) : std::vector<COBANI_TYPE_DECIMAL>(COBANI_DIMENSION)
    {
        at(COBANI_PX) = x;
        at(COBANI_PY) = y;
    }
    #endif
    #if COBANI_DIMENSION >= 3
    Point::Point(COBANI_TYPE_DECIMAL x, COBANI_TYPE_DECIMAL y, COBANI_TYPE_DECIMAL z) : std::vector<COBANI_TYPE_DECIMAL>(COBANI_DIMENSION)
    {
        at(COBANI_PX) = x;
        at(COBANI_PY) = y;
        at(COBANI_PZ) = z;
    }
    #endif
    COBANI_TYPE_DECIMAL Point::lengthTo(const Point& to)const
    {
        COBANI_TYPE_DECIMAL lengx = to[COBANI_PX] - at(COBANI_PX);
        #if COBANI_DIMENSION >= 2
        COBANI_TYPE_DECIMAL lengy = to[COBANI_PY] - at(COBANI_PY);
        #endif
        #if COBANI_DIMENSION >= 3
        COBANI_TYPE_DECIMAL lengz = to[COBANI_PZ] - at(COBANI_PZ);
        #endif
        //std::cout << "lengx = " << lengx << "\n";
        //std::cout << "lengy = " << lengy << "\n";
        //std::cout << "lengz = " << lengz << "\n";
        #if COBANI_DIMENSION == 2
        COBANI_TYPE_DECIMAL leng = pow(lengx,2) + pow(lengy,2);
        #elif COBANI_DIMENSION == 3
        COBANI_TYPE_DECIMAL leng = pow(lengx,2) + pow(lengy,2) + pow(lengz,2);
        #endif
        //std::cout << "leng = " << leng << "\n";
        leng = sqrt(leng);
        //std::cout << "leng = " << leng << "\n";
        return leng;
    }
    Point::Point(const Point& obj) : std::vector<COBANI_TYPE_DECIMAL>(COBANI_DIMENSION)
    {

    }
    void Point::setX(COBANI_TYPE_DECIMAL v)
    {
        at(COBANI_PX) = v;
    }
    #if COBANI_DIMENSION >= 2
    void Point::setY(COBANI_TYPE_DECIMAL v)
    {
        std::cout << "COBANI_TYPE_DECIMAL v =  " << v << "\n";
        at(COBANI_PY) = v;
    }
    #endif
    #if COBANI_DIMENSION >= 3
    void Point::setZ(COBANI_TYPE_DECIMAL v)
    {
        at(COBANI_PZ) = v;
    }
    #endif
    COBANI_TYPE_DECIMAL Point::getX()const
    {
        return at(COBANI_PX);
    }
    #if COBANI_DIMENSION >= 2
    COBANI_TYPE_DECIMAL Point::getY()const
    {
        return at(COBANI_PY);
    }
    #endif
    #if COBANI_DIMENSION >= 3
    COBANI_TYPE_DECIMAL Point::getZ()const
    {
        return at(COBANI_PZ);
    }
    #endif
    Point::Point() : std::vector<COBANI_TYPE_DECIMAL>(COBANI_DIMENSION)
    {

    }
    bool Point::normalize()
    {
        COBANI_TYPE_DECIMAL lenvect = lengthTo(Point::O);
        if(fabs(lenvect - COBANI_EPSILON) >= lenvect)
        {
            std::string msg = "El vector a normalizar deve ser diferente de 0. ahora es de '";
            msg = msg + std::to_string(lenvect) + "'";
            throw Exception(__FILE__,__LINE__,msg.c_str());
        }
        at(COBANI_PX) = at(COBANI_PX)/lenvect;
        //std::cout << "direction[COBANI_PX] = " << direction[COBANI_PX] << "\n";
        #if COBANI_DIMENSION >= 2
        at(COBANI_PY) = at(COBANI_PY)/lenvect;
        //std::cout << "direction[COBANI_PY] = " << direction[COBANI_PY] << "\n";
        #endif
        #if COBANI_DIMENSION >= 3
        at(COBANI_PZ) = (at(COBANI_PZ)/lenvect);
        //std::cout << "direction[COBANI_PZ] = " << direction[COBANI_PZ] << "\n";
        #endif

        lenvect = lengthTo(Point::O);
        if(fabs(lenvect - 1.0) >= COBANI_EPSILON)
        {
            std::string msg = "Despues de normalizar un vetor deveria tener longitud unitaria, ahora tiene '";
            msg = msg + std::to_string(lenvect) + "'";
            throw Exception(__FILE__,__LINE__,msg);
        }

        return true;
    }
    Point::operator std::string() const
    {
        std::string str = "(";
        str += std::to_string(at(COBANI_PX)) ;
        #if COBANI_DIMENSION >= 2
        str = str + "," + std::to_string(at(COBANI_PY));
        #endif
        #if COBANI_DIMENSION >= 3
        str = str + "," + std::to_string(at(COBANI_PZ)) + ;
        #endif
        str += ")";
        return str;
    }
    const Point& Point::operator =(const Point& p)
    {
        at(COBANI_PX) = p[COBANI_PX];
        #if COBANI_DIMENSION >= 2
        at(COBANI_PY) = p[COBANI_PY];
        #endif
        #if COBANI_DIMENSION >= 3
        at(COBANI_PZ) = p[COBANI_PZ];
        #endif

        return *this;
    }






    Exception::Exception(const char* fn,int l, const std::string& msg)
    {
        filename = fn;
        line = l;
        message = filename;
        message = message + " : "+ std::to_string(line) + " -> " + msg;
    }
    const char* Exception::what () const throw ()
    {
        return message.c_str();
    }
}
