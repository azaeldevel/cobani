#ifndef ENTITIES_HH_INCLUDED
#define ENTITIES_HH_INCLUDED

#ifdef BUILDING_DLL && WINDOWS_MINGW
    #define DLL_SPEC __declspec(dllexport)
#elif WINDOWS_MINGW
    #define DLL_SPEC __declspec(dllimport)
#else
    #define DLL_SPEC
#endif


#define COBANI_TYPE_INT long
#define COBANI_TYPE_DECIMAL double


#define COBANI_PX 0
#define COBANI_PY 1
#define COBANI_PZ 2
#define COBANI_DIMENSION 3

#include <string>
#include <vector>

namespace cobani::core
{

class DLL_SPEC Point : public std::vector<COBANI_TYPE_INT>
{

public:
    //constructores
    Point();

    //operadores

    //getters
    COBANI_TYPE_INT getX()const;
    COBANI_TYPE_INT getY()const;
    COBANI_TYPE_INT getZ()const;
    //setter
    void setX(COBANI_TYPE_INT);
    void setY(COBANI_TYPE_INT);
    void setZ(COBANI_TYPE_INT);

    //funtions
    COBANI_TYPE_DECIMAL lengthTo(const Point&)const;
};

class DLL_SPEC Vector
{
private:
    Point origin;
    Point direction;

public:
    Vector(const Point& o, const Point& d);
    //settet

    //getter
    const Point& getOrigin()const;
    const Point& getDirectrion()const;

    //funtions
    bool makeUnit();
    COBANI_TYPE_DECIMAL length()const;

};

class DLL_SPEC Entity
{
private:
    std::string id;

public:
    Entity();
    const std::string& getID() const;
};


/**
*\brief Interface para aplicar operaciones a los objetos
*/
class DLL_SPEC Matter
{
public:
    virtual bool move(const Vector& v) = 0;
    /**
    *\brief Es la rotacion algebraica.
    *\param u es el vector unitario en el cual se realizara la rotacion.
    */
    virtual bool rotate(const Point& u) = 0;
};


class DLL_SPEC Atomo : public Entity, public Matter
{
private:
    Point point;
    Point direction;

public:
    Atomo(const Point& p);

    //gettter
    const Point& getPoint()const;

    //matter
    virtual bool move(const Vector& v);
    virtual bool rotate(const Point& u);
};




class Object : public Matter
{
private:
    Point point;
    std::vector<Point> points;

public:
    /**
    *
    *\param sizepoly la cantidad de puntos que definira el poligono
    */
    Object(int sizepoly);

    //gettter
    const std::vector<Point>& getPoints()const;

    //matter
    virtual bool move(const Vector& v);
    virtual bool rotate(const Point& u);
};




class World : public Object
{

public:
    //matter
    virtual bool move(const Vector& v);
    virtual bool rotate(const Point& u);
};



class Context
{

};

class Comunity : public Context
{

};

class Person : public Context
{

};

class Room : public Context
{

};

class School : public Context
{


};

class Social : public Context
{

};



}

#endif // ENTITIES_HH_INCLUDED
