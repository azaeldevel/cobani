#ifndef DUST_HH
#define DUST_HH

#include "entities.hh"

namespace cobani::core
{

class DLL_SPEC Dust : public Atom
{
public:
    //
    const double theta = 0.01;

    //
    Dust();
    Dust(const Vector& p);
    virtual ~Dust();

    //matter
    virtual bool rotate(const Point& u);
    virtual bool rotate(COBANI_TYPE_DECIMAL theta);
    virtual bool move(const Point& v);
    virtual bool move(COBANI_TYPE_DECIMAL length);
    virtual bool generate();
protected:

private:
    Point dir;
};


}

#endif // DUST_HH
