#ifndef ENTITIES_HH_INCLUDED
#define ENTITIES_HH_INCLUDED

#if defined BUILDING_DLL && WINDOWS_MINGW
    #define DLL_SPEC __declspec(dllexport)
#elif WINDOWS_MINGW && !TESTING && !defined BUILDING_DLL
    #define DLL_SPEC __declspec(dllimport)
#else
    #define DLL_SPEC
#endif


#define COBANI_TYPE_INTEGER long
#define COBANI_TYPE_DECIMAL double

#define COBANI_EPSILON 1.0e-4
#define COBANI_PX 0
#define COBANI_PY 1
#define COBANI_PZ 2
#define COBANI_DIMENSION 2
// 0 Subatomo,5 atomo, 10 obejtos
#define COBANI_LEVEL 10



#include <math.h>
#include <string>
#include <vector>
#include <map>
#include <exception>


namespace cobani::core
{
class DLL_SPEC Point;


class DLL_SPEC Matter
{
public:
    virtual bool rotate(const Point& u) = 0;
    virtual bool rotate(COBANI_TYPE_DECIMAL theta) = 0;
    virtual bool move(const Point& v) = 0;
    virtual bool move(COBANI_TYPE_DECIMAL length) = 0;
};

class DLL_SPEC Exception : public std::exception
{
private:
    int line;
    const char* filename;
    std::string message;
public:
    Exception(const char* fn,int line, const std::string& msg);
    virtual const char* what () const throw ();
};


class DLL_SPEC Point : public std::vector<COBANI_TYPE_DECIMAL>
{
public:
    static Point O;

public:
    //constructores
    Point();
    Point(const Point&);
    #if COBANI_DIMENSION >= 2
    Point(COBANI_TYPE_DECIMAL x,COBANI_TYPE_DECIMAL y);
    #endif
    #if COBANI_DIMENSION >= 2
    Point(COBANI_TYPE_DECIMAL x,COBANI_TYPE_DECIMAL y, COBANI_TYPE_DECIMAL z);
    #endif
    //operadores
    operator std::string() const;
    const Point& operator =(const Point&);
    const Point& operator +(const Point&);

    //getters
    COBANI_TYPE_DECIMAL getX()const;
    #if COBANI_DIMENSION >= 2
    COBANI_TYPE_DECIMAL getY()const;
    #endif
    #if COBANI_DIMENSION >= 3
    COBANI_TYPE_DECIMAL getZ()const;
    #endif
    //setter
    void setX(COBANI_TYPE_DECIMAL);
    #if COBANI_DIMENSION >= 2
    void setY(COBANI_TYPE_DECIMAL);
    #endif
    #if COBANI_DIMENSION >= 3
    void setZ(COBANI_TYPE_DECIMAL);
    #endif

    //funtions
    COBANI_TYPE_DECIMAL lengthTo(const Point&)const;
    bool normalize();
    bool rotate(const Point& u);
    bool rotate(COBANI_TYPE_DECIMAL theta);
    bool move(const Point& v);
};

class DLL_SPEC Vector
{
private:
    Point origin;
    Point direction;

public:
    //contructores
    Vector(const Point& o, const Point& d);
    Vector(const Vector&);
    Vector();
    //settet
    void setOrigin(const Point&);
    void setDirection(const Point&);
    //getter
    Point& getOrigin();
    Point& getDirection();

    //operator
    const Vector& operator +(const Vector&);
    const Vector& operator *(COBANI_TYPE_DECIMAL);
    const Vector& operator =(const Vector&);

    //funtions
    COBANI_TYPE_DECIMAL length()const;
    bool rotate(const Point& u);
    bool rotate(COBANI_TYPE_DECIMAL theta);
    bool move(const Point& v);
};





class DLL_SPEC Entity
{
private:
    std::string id;

public:
    Entity();
    ~Entity();
    const std::string& getID() const;
};


class DLL_SPEC Atom : public Entity, public Matter
{
private:


protected:
    Vector position;

public:
    Atom();
    Atom(const Vector& p);
    ~Atom();

    //gettter
    const Vector& getPosition()const;

    //setter
    void setPosition(const Vector& v);

    //funtions
    virtual bool generate() = 0;
};


class DLL_SPEC Object : public Entity
{
private:
    std::vector<Atom*> atoms;

public:
    /**
    *
    *\param count la cantidad de atomos que conforman el objeto
    */
    Object(int count);
    Object();
    Object(const Object& obj);
    ~Object();

    //gettter
    const std::vector<Atom*>& getAtoms()const;

    //funtion
    bool interior();
    bool exterior();
};


class DLL_SPEC World : public Object
{
private:
    std::map<std::string,Object> objects;

public:
    //constructor

};





}

#endif // ENTITIES_HH_INCLUDED
