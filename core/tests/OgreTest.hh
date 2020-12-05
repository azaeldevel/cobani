#ifndef OGRETEST_HH
#define OGRETEST_HH

#include <Ogre.h>
#include <Bites/OgreApplicationContext.h>
#include <Bites/OgreInput.h>
#include <RTShaderSystem/OgreRTShaderSystem.h>
#include <iostream>


using namespace Ogre;
using namespace OgreBites;

class BasicTutorial1
        : public ApplicationContext
        , public InputListener
{
public:
    BasicTutorial1();
    virtual ~BasicTutorial1() {}

    void setup();
    bool keyPressed(const KeyboardEvent& evt);
};


class MyTestApp : public OgreBites::ApplicationContext, public OgreBites::InputListener
{
public:
    MyTestApp();
    void setup();
    bool keyPressed(const OgreBites::KeyboardEvent& evt);
};



#endif // OGRETEST_HH
