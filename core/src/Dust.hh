#ifndef DUST_HH
#define DUST_HH

#include "Entities.hh"

namespace cobani::core
{

class DLL_SPEC Dust : public Atom
{
public:
    Dust();
    Dust(const Vector& p);
    virtual ~Dust();

    //matter
    virtual bool move(const Vector& v);
    virtual bool rotate(const Point& u);
    virtual bool generate();
protected:

private:
    double theta = 0.25;
    Point dir;
};


}

#endif // DUST_HH
