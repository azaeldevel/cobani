

#include "OgreTest.hh"
#include "Window.hh"

namespace cobani::core
{
    bool Window::ogreWorld()
    {
        /*try
        {
            BasicTutorial1 app;
            app.initApp();
            app.getRoot()->startRendering();
            app.closeApp();
        }
        catch (const std::exception& e)
        {
            std::cerr << "Error occurred during execution: " << e.what() << '\n';
            return 1;
        }*/

        MyTestApp app;
        app.initApp();
        app.getRoot()->startRendering();
        app.closeApp();

        return true;
    }
}

BasicTutorial1::BasicTutorial1() : ApplicationContext("OgreTutorialApp")
{
}


void BasicTutorial1::setup()
{
    // do not forget to call the base first
    ApplicationContext::setup();
    addInputListener(this);

    // get a pointer to the already created root
    Root* root = getRoot();
    SceneManager* scnMgr = root->createSceneManager();

    // register our scene with the RTSS
    RTShader::ShaderGenerator* shadergen = RTShader::ShaderGenerator::getSingletonPtr();
    shadergen->addSceneManager(scnMgr);

    // -- tutorial section start --
    //! [turnlights]
    scnMgr->setAmbientLight(ColourValue(0.5, 0.5, 0.5));
    //! [turnlights]

    //! [newlight]
    Light* light = scnMgr->createLight("MainLight");
    SceneNode* lightNode = scnMgr->getRootSceneNode()->createChildSceneNode();
    lightNode->attachObject(light);
    //! [newlight]

    //! [lightpos]
    lightNode->setPosition(20, 80, 50);
    //! [lightpos]

    //! [camera]
    SceneNode* camNode = scnMgr->getRootSceneNode()->createChildSceneNode();

    // create the camera
    Camera* cam = scnMgr->createCamera("myCam");
    cam->setNearClipDistance(5); // specific to this sample
    cam->setAutoAspectRatio(true);
    camNode->attachObject(cam);
    camNode->setPosition(0, 0, 140);

    // and tell it to render into the main window
    getRenderWindow()->addViewport(cam);
    //! [camera]

    //! [entity1]
    Entity* ogreEntity = scnMgr->createEntity("ogrehead.mesh");
    //! [entity1]

    //! [entity1node]
    SceneNode* ogreNode = scnMgr->getRootSceneNode()->createChildSceneNode();
    //! [entity1node]

    //! [entity1nodeattach]
    ogreNode->attachObject(ogreEntity);
    //! [entity1nodeattach]

    //! [cameramove]
    camNode->setPosition(0, 47, 222);
    //! [cameramove]

    //! [entity2]
    Entity* ogreEntity2 = scnMgr->createEntity("ogrehead.mesh");
    SceneNode* ogreNode2 = scnMgr->getRootSceneNode()->createChildSceneNode(Vector3(84, 48, 0));
    ogreNode2->attachObject(ogreEntity2);
    //! [entity2]

    //! [entity3]
    Entity* ogreEntity3 = scnMgr->createEntity("ogrehead.mesh");
    SceneNode* ogreNode3 = scnMgr->getRootSceneNode()->createChildSceneNode();
    ogreNode3->setPosition(0, 104, 0);
    ogreNode3->setScale(2, 1.2, 1);
    ogreNode3->attachObject(ogreEntity3);
    //! [entity3]

    //! [entity4]
    Entity* ogreEntity4 = scnMgr->createEntity("ogrehead.mesh");
    SceneNode* ogreNode4 = scnMgr->getRootSceneNode()->createChildSceneNode();
    ogreNode4->setPosition(-84, 48, 0);
    ogreNode4->roll(Degree(-90));
    ogreNode4->attachObject(ogreEntity4);
    //! [entity4]

    // -- tutorial section end --
}


bool BasicTutorial1::keyPressed(const KeyboardEvent& evt)
{
    if (evt.keysym.sym == SDLK_ESCAPE)
    {
        getRoot()->queueEndRendering();
    }
    return true;
}


//! [constructor]
MyTestApp::MyTestApp() : OgreBites::ApplicationContext("OgreTutorialApp")
{
}
//! [constructor]

//! [key_handler]
bool MyTestApp::keyPressed(const OgreBites::KeyboardEvent& evt)
{
    if (evt.keysym.sym == OgreBites::SDLK_ESCAPE)
    {
        getRoot()->queueEndRendering();
    }
    return true;
}
//! [key_handler]

//! [setup]
void MyTestApp::setup(void)
{
    // do not forget to call the base first
    OgreBites::ApplicationContext::setup();

    // register for input events
    addInputListener(this);

    // get a pointer to the already created root
    Ogre::Root* root = getRoot();
    Ogre::SceneManager* scnMgr = root->createSceneManager();

    // register our scene with the RTSS
    Ogre::RTShader::ShaderGenerator* shadergen = Ogre::RTShader::ShaderGenerator::getSingletonPtr();
    shadergen->addSceneManager(scnMgr);

    // without light we would just get a black screen
    Ogre::Light* light = scnMgr->createLight("MainLight");
    Ogre::SceneNode* lightNode = scnMgr->getRootSceneNode()->createChildSceneNode();
    lightNode->setPosition(0, 10, 15);
    lightNode->attachObject(light);

    // also need to tell where we are
    Ogre::SceneNode* camNode = scnMgr->getRootSceneNode()->createChildSceneNode();
    camNode->setPosition(0, 0, 15);
    camNode->lookAt(Ogre::Vector3(0, 0, -1), Ogre::Node::TS_PARENT);

    // create the camera
    Ogre::Camera* cam = scnMgr->createCamera("myCam");
    cam->setNearClipDistance(5); // specific to this sample
    cam->setAutoAspectRatio(true);
    camNode->attachObject(cam);

    // and tell it to render into the main window
    getRenderWindow()->addViewport(cam);

    // finally something to render
    Ogre::Entity* ent = scnMgr->createEntity("Sinbad.mesh");
    Ogre::SceneNode* node = scnMgr->getRootSceneNode()->createChildSceneNode();
    node->attachObject(ent);
}






