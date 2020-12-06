#ifndef FIRSTPERONS_HH
#define FIRSTPERONS_HH

#include <exception>
#include <string>
#include <iostream>

#include <SDL.h>
#include <Entities.hh>


namespace cobani
{

class FirstPerson : public core::FirstPerson
{
private:
    SDL_Window * m_window;
    SDL_Renderer * m_renderer;

public:
    FirstPerson( Uint32 flags = 0 );
    virtual ~FirstPerson();
    void draw();
};


}
#endif // FIRSTPERONS_HH
