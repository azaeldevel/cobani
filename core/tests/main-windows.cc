#include "Window.hh"

int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow)
{
    BOOL bQuit = FALSE;
    MSG msg;

    cobani::core::Window wind1(hInstance);
    wind1.show(nCmdShow);

    wind1.points();

    /* enable OpenGL for the window */
    wind1.EnableOpenGL();

    /* program main loop */
    while (!bQuit)
    {
        /* check for messages */
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            /* handle or dispatch messages */
            if (msg.message == WM_QUIT)
            {
                bQuit = TRUE;
            }
            else
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
        else
        {
            //wind1.triangle();
            wind1.world();
            //wind1.glfwWindow();
            Sleep (1);
        }
    }

    /* shutdown OpenGL */
    wind1.DisableOpenGL();


    return msg.wParam;
}
