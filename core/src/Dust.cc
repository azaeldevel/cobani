
#include <gl/gl.h>
#include <gmp.h>


#ifdef DEBUG
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
Dust::Dust() : Atom(Vector(Point(21,23),Point(2.0,2.0)))
{
    position.getDirection().normalize();
}
#elif COBANI_DIMENSION == 3
Dust::Dust() : Atom(Vector(Point(21,23,11),Point(2.0,2.0,6.3)))
{
    position.getOrigin().normalize();
}
#endif

Dust::~Dust()
{
    //dtor
}




bool Dust::generate()
{
    COBANI_TYPE_DECIMAL lm = 0.86602;
    COBANI_TYPE_DECIMAL lm2 = lm/2;

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);


    std::cout << "Original : " << (std::string)position.getDirection() << "\n";
    if(fabs(dir.lengthTo(Point::O) - 1.0) >= COBANI_EPSILON) position.getDirection().normalize();
    std::cout << "Normalizado : " << (std::string)position.getDirection() << "\n";
    std::cout << "Longitud : " << position.getDirection().lengthTo(Point::O) << "\n";
    //position.rotate(theta);
    //std::cout << "Rotado : " << (std::string)dir << "\n";

    std::cout << "u " << (std::string)dir << "\n";

    glPushMatrix();
        glBegin(GL_LINES);
            glColor3f(1.0f, 1.0f, 1.0f);
            glLineWidth(50.0);
            glVertex2d(0 , 0);
            glVertex2d(dir[COBANI_PX],  dir[COBANI_PY] );
        glEnd();
        glBegin(GL_TRIANGLES);
            //
            glColor3f(0.0f, 0.0f, 1.0f);
            Point v1(0,0);
            //COBANI_TYPE_DECIMAL v1xNew = (position.getDirection()[COBANI_PX] * v1xInit) - (position.getDirection()[COBANI_PY] * v1yInit);
            //COBANI_TYPE_DECIMAL v1yNew = (position.getDirection()[COBANI_PY] * v1xInit) + (position.getDirection()[COBANI_PX] * v1yInit);
            v1.rotate(position.getDirection());
            glVertex2d(position.getOrigin()[COBANI_PX] + v1[COBANI_PX],  position.getOrigin()[COBANI_PY] + v1[COBANI_PY]);

            //
            glColor3f(0.0f, 1.0f, 0.0f);
            Point v2(0.5,lm);
            /*const COBANI_TYPE_DECIMAL v2xInit = 0.5;
            const COBANI_TYPE_DECIMAL v2yInit = lm;
            COBANI_TYPE_DECIMAL v2xNew = (position.getDirection()[COBANI_PX] * v2xInit) - (position.getDirection()[COBANI_PY] * v2yInit);
            COBANI_TYPE_DECIMAL v2yNew = (position.getDirection()[COBANI_PY] * v2xInit) + (position.getDirection()[COBANI_PX] * v2yInit);*/
            v2.rotate(position.getDirection());
            glVertex2d(position.getOrigin()[COBANI_PX] + v2[COBANI_PX],  position.getOrigin()[COBANI_PY] + v2[COBANI_PY]);

            //
            glColor3f(1.0f, 0.0f, 0.0f);
            Point v3(1.0,0.0);
            /*const COBANI_TYPE_DECIMAL v3xInit = 1.0;
            const COBANI_TYPE_DECIMAL v3yInit = 0.0;
            COBANI_TYPE_DECIMAL v3xNew = (position.getDirection()[COBANI_PX] * v3xInit) - (position.getDirection()[COBANI_PY] * v3yInit);
            COBANI_TYPE_DECIMAL v3yNew = (position.getDirection()[COBANI_PY] * v3xInit) + (position.getDirection()[COBANI_PX] * v3yInit);*/
            v3.rotate(position.getDirection());
            glVertex2d(position.getOrigin()[COBANI_PX] + v3[COBANI_PX],  position.getOrigin()[COBANI_PY] + v3[COBANI_PY]);
        glEnd();

    glPopMatrix();

    //theta += 0.05;
    position.rotate(theta);

    return true;
}
bool Dust::move(const Vector& v)
{
    return true;
}
bool Dust::rotate(const Point& u)
{
    //

    //
    return true;
}

}
