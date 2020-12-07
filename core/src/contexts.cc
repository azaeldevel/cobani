#include "contexts.hh"


namespace cobani::core
{

Community::Community( Uint32 flags ) : Context(flags)
{

}

Community::~Community()
{

}












FirstPerson::FirstPerson( Uint32 flags ) : Context(flags)
{

}

FirstPerson::~FirstPerson()
{

}



















Context::Context( Uint32 flags )
{
    if ( SDL_Init( SDL_INIT_EVERYTHING ) != 0 )
    {
        throw core::Exception(__FILE__,__LINE__,"Fallo la inicializacion de la venta.");
    }
    if ( TTF_Init() < 0 )
    {
        std::string msg = "Error initializing SDL_ttf: ";
        msg += TTF_GetError();
        msg +=  "\n";
        throw core::Exception(__FILE__,__LINE__,msg);
    }
    if ( SDL_CreateWindowAndRenderer( 640, 480, SDL_WINDOW_SHOWN, &m_window, &m_renderer ) != 0 )
    {
        throw core::Exception(__FILE__,__LINE__,"Renderizacion fallida.");
    }
}

Context::~Context()
{
    SDL_DestroyWindow( m_window );
    SDL_DestroyRenderer( m_renderer );
    SDL_Quit();
}
void Context::displayLoading()
{
    TTF_Font* font;

    #ifdef WINDWOWS_MINGW
    font = TTF_OpenFont("DejaVuSans.ttf", 60);
    #else
    font = TTF_OpenFont("DejaVuSans.ttf", 60);///usr/share/fonts/TTF/
    #endif
    if ( !font )
    {
        std::string msg = "Failed to load font : ";
        msg += TTF_GetError();
        msg +=  "\n";
        throw core::Exception(__FILE__,__LINE__,msg);
    }
    SDL_Surface* text;
    // Set color to black
    SDL_Color color = { 0, 0, 0 };

    text = TTF_RenderText_Solid( font, "Cargando componentes!...", color );
    if ( !text )
    {
        std::string msg = "Failed to render text:";
        msg += TTF_GetError();
        msg +=  "\n";
    }
    SDL_Texture* text_texture;
    text_texture = SDL_CreateTextureFromSurface( m_renderer, text );
    SDL_Rect dest = { 0, text->h / 2, text->w / 2, text->h /3 };
    SDL_RenderCopy( m_renderer, text_texture, NULL, &dest );
    SDL_DestroyTexture( text_texture );
    SDL_FreeSurface( text );
}

//getter
SDL_Renderer* Context::getRenderer()
{
    return m_renderer;
}

void Context::displayPregress2()
{
    SDL_SetRenderDrawColor( m_renderer, 0, 0, 0, 255 );
    SDL_RenderClear( m_renderer );
}
void Context::displayPregress()
{
    // Clear the window with a black background
    SDL_SetRenderDrawColor( m_renderer, 0, 0, 0, 255 );
    SDL_RenderClear( m_renderer );

    // Show the window
    SDL_RenderPresent( m_renderer );

    int rgb[] = { 203, 203, 203, // Gray
                  254, 254,  31, // Yellow
                    0, 255, 255, // Cyan
                    0, 254,  30, // Green
                  255,  16, 253, // Magenta
                  253,   3,   2, // Red
                   18,  14, 252, // Blue
                    0,   0,   0  // Black
                };

    SDL_Rect colorBar;
    colorBar.x = 0; colorBar.y = 0; colorBar.w = 90; colorBar.h = 480;

    // Render a new color bar every 0.5 seconds
    for ( int i = 0; i != sizeof rgb / sizeof *rgb; i += 3, colorBar.x += 90 )
    {
        SDL_SetRenderDrawColor( m_renderer, rgb[i], rgb[i + 1], rgb[i + 2], 255 );
        SDL_RenderFillRect( m_renderer, &colorBar );
        SDL_RenderPresent( m_renderer );
        displayLoading();
        SDL_Delay( 500 );
    }
}


}
