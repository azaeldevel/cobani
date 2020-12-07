#ifndef CONTEXTS_HH
#define CONTEXTS_HH

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>


#include "entities.hh"


namespace cobani::core
{


class DLL_SPEC Context
{
private:
    SDL_Window * m_window;
    SDL_Renderer * m_renderer;

    //funciones
    void displayLoading();
public:
    Context( Uint32 flags = 0 );
    virtual ~Context();

    //
    SDL_Renderer* getRenderer();
    //funciones
    void displayPregress();
    void displayPregress2();
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

    //funciones

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
