#ifndef WINDOW_H
#define WINDOW_H

#include <windows.h>
#include <Dust.hh>

#include "Console.hh"

namespace cobani::core
{

class Window : public Console
{
public:
    Window(HINSTANCE hInstance);
    virtual ~Window();
    const HDC& getHDC()const;

    //getter

    //funtions
    BOOL show(int  nCmdShow);
    static LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);
    void EnableOpenGL();
    void DisableOpenGL();

    bool triangle();
    bool world();

protected:

private:
    WNDCLASSEX wcex;
    HWND hwnd;
    HDC hDC;
    HGLRC hRC;
    float theta = 0.0f;
    cobani::core::Dust dust;
};

}

#endif // WINDOW_H
