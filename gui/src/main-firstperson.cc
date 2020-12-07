
#include "SDL.h"

#include "FirstPerons.hh"


int main( int argc, char * argv[] )
{
    cobani::FirstPerson* fperson = NULL;
    try
    {
        fperson = new cobani::FirstPerson( SDL_INIT_VIDEO | SDL_INIT_TIMER );
        fperson->displayPregress();
    }
    catch(const cobani::core::Exception& ex)
    {
        std::string msg = "Error while initializing SDL:  ";
        msg += ex.what();
        msg += "\n";
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,"Error detectado.", msg.c_str(),NULL);
    }
    catch(const std::exception& ex)
    {
        std::string msg = "Error while initializing SDL:  ";
        msg += ex.what();
        msg += "\n";
        const SDL_MessageBoxButtonData buttons[] = {
        { /* .flags, .buttonid, .text */        0, 0, "no" },
        { SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, 1, "yes" },
        { SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT, 2, "cancel" },
        };
        const SDL_MessageBoxColorScheme colorScheme = {
            { /* .colors (.r, .g, .b) */
                /* [SDL_MESSAGEBOX_COLOR_BACKGROUND] */
                { 255,   0,   0 },
                /* [SDL_MESSAGEBOX_COLOR_TEXT] */
                {   0, 255,   0 },
                /* [SDL_MESSAGEBOX_COLOR_BUTTON_BORDER] */
                { 255, 255,   0 },
                /* [SDL_MESSAGEBOX_COLOR_BUTTON_BACKGROUND] */
                {   0,   0, 255 },
                /* [SDL_MESSAGEBOX_COLOR_BUTTON_SELECTED] */
                { 255,   0, 255 }
            }
        };
        const SDL_MessageBoxData messageboxdata = {
            SDL_MESSAGEBOX_INFORMATION, /* .flags */
            NULL, /* .window */
            "Error detectado.", /* .title */
            msg.c_str(), /* .message */
            SDL_arraysize(buttons), /* .numbuttons */
            buttons, /* .buttons */
            &colorScheme /* .colorScheme */
        };
        int buttonid;
        if (SDL_ShowMessageBox(&messageboxdata, &buttonid) < 0) {
            SDL_Log("error displaying message box");
            return 1;
        }
        if (buttonid == -1) {
            SDL_Log("no selection");
        } else {
            SDL_Log("selection was %s", buttons[buttonid].text);
        }
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
                std::cout << "Cerrando..\n";
                break;
            }
        }
        SDL_RenderClear(fperson->getRenderer());
        SDL_RenderPresent(fperson->getRenderer());
    }

    delete fperson;

    return 0;
}
