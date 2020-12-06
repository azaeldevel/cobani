

#include "FirstPerons.hh"


int main( int argc, char * argv[] )
{
    try
    {
        cobani::FirstPerson sdl( SDL_INIT_VIDEO | SDL_INIT_TIMER );
        sdl.draw();

        return 0;
    }
    catch(const cobani::core::Exception& ex)
    {
        std::cerr << "Error while initializing SDL:  "
                  << ex.what()
                  << std::endl;
    }
    catch(const std::exception& ex2)
    {
        std::cerr << "Error while initializing SDL:  "
                  << ex2.what()
                  << std::endl;
    }

    return 1;
}
