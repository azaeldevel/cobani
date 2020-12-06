#ifndef FIRSTPERON_HH
#define FIRSTPERON_HH

#include <exception>
#include <string>
#include <iostream>


#include <contexts.hh>


namespace cobani
{

class FirstPerson : public cobani::core::FirstPerson
{
public:
    FirstPerson( Uint32 flags = 0 );
    virtual ~FirstPerson();
};


}
#endif // FIRSTPERONS_HH
