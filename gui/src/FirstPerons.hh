#ifndef FIRSTPERONS_HH
#define FIRSTPERONS_HH

#include <exception>
#include <string>
#include <iostream>
#include <SDL.h>


class InitError : public std::exception
{
    std::string msg;
public:
    InitError();
    InitError( const std::string & );
    virtual ~InitError() throw();
    virtual const char * what() const throw();
};

class SDL
{
    SDL_Window * m_window;
    SDL_Renderer * m_renderer;
public:
    SDL( Uint32 flags = 0 );
    virtual ~SDL();
    void draw();
};


#endif // FIRSTPERONS_HH
