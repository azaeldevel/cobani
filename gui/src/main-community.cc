

#include "Community.hh"


int main( int argc, char * argv[] )
{
    cobani::Community* community = NULL;
    try
    {
        community = new cobani::Community( SDL_INIT_VIDEO | SDL_INIT_TIMER );
        community->displayPregress();
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


    SDL_Event e;
    bool quit = false;
    while (!quit)
    {
        while (SDL_PollEvent(&e))
        {
            switch(e.type)
            {
            case SDL_QUIT:
            case SDL_KEYDOWN:
                quit = true;
                std::cout << "Cerrando ...\n";
                break;
            }
        }
        SDL_RenderClear(community->getRenderer());
        SDL_RenderPresent(community->getRenderer());
    }

    delete community;

    return 0;
}
