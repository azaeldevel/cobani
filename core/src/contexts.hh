#ifndef CONTEXTS_HH
#define CONTEXTS_HH

#include "entities.hh"


namespace cobani::core
{


class DLL_SPEC Context
{
private:
    SDL_Window * m_window;
    SDL_Renderer * m_renderer;

public:
    Context( Uint32 flags = 0 );
    virtual ~Context();
    void draw();
    void displayLoading();
};

class DLL_SPEC Community : public Context
{
public:
    Community( Uint32 flags = 0 );
    virtual ~Community();
};

class DLL_SPEC FirstPerson : public Context
{
public:
    FirstPerson( Uint32 flags = 0 );
    virtual ~FirstPerson();
};

class DLL_SPEC Room : public Context
{

};

class DLL_SPEC School : public Context
{


};

class DLL_SPEC Social : public Context
{

};


}

#endif // CONTEXTS_HH
