
#include <GL/gl.h>
#include <gmp.h>


#ifdef COBANI_DEBUG
    #include <iostream>
    #include <assert.h>
#endif


#include "Dust.hh"


namespace cobani::core
{
#if COBANI_DIMENSION >= 2
Dust::Dust(const Vector& v) : Atom(v)
{
}
#endif
#if COBANI_DIMENSION >= 3
Dust::Dust(const Vector& v) : Atom(v)
{
}
#endif
#if COBANI_DIMENSION == 2
Dust::Dust()
{
    Point o(0.0,0.0);
    Point d(2.0,2.0);
    d.normalize();
    position.setOrigin(o);
    position.setDirection(d);
}
#elif COBANI_DIMENSION == 3
Dust::Dust()
{

}
#endif

Dust::~Dust()
{
    //dtor
}




bool Dust::generate()
{
    COBANI_TYPE_DECIMAL lm = 0.86602;

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
        glBegin(GL_TRIANGLES);
            //
            glColor3f(0.0f, 0.0f, 1.0f);
            Point v1(0,0);
            v1.rotate(position.getDirection());
            glVertex2d(position.getOrigin()[COBANI_PX] + v1[COBANI_PX],  position.getOrigin()[COBANI_PY] + v1[COBANI_PY]);
            //
            glColor3f(0.0f, 1.0f, 0.0f);
            Point v2(0.5,lm);
            v2.rotate(position.getDirection());
            glVertex2d(position.getOrigin()[COBANI_PX] + v2[COBANI_PX],  position.getOrigin()[COBANI_PY] + v2[COBANI_PY]);
            //
            glColor3f(1.0f, 0.0f, 0.0f);
            Point v3(1.0,0.0);
            v3.rotate(position.getDirection());
            glVertex2d(position.getOrigin()[COBANI_PX] + v3[COBANI_PX],  position.getOrigin()[COBANI_PY] + v3[COBANI_PY]);
        glEnd();
    glPopMatrix();
    //position.rotate(theta);
    return true;
}
bool Dust::rotate(const Point& u)
{
    return position.rotate(u);
}
bool Dust::rotate(COBANI_TYPE_DECIMAL theta)
{
    return position.rotate(theta);
}
bool Dust::move(const Point& v)
{
    return true;
}
bool Dust::move(COBANI_TYPE_DECIMAL length)
{
    return true;
}

}
