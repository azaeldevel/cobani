#ifndef COMMUNITY_HH
#define COMMUNITY_HH

#include <exception>
#include <string>
#include <iostream>


#include <contexts.hh>


namespace cobani
{

class Community : public core::Community
{
public:
    Community( Uint32 flags = 0 );
    virtual ~Community();
};


}
#endif // FIRSTPERONS_HH
