#include "boxes.h"
Box::Box(float x, float y, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene,int input):GameItem(world)
{
    // Set pixmap
    g_pixmap.setPixmap(pixmap);
    g_pixmap.setTransformOriginPoint(g_pixmap.boundingRect().width()/2,g_pixmap.boundingRect().height()/2);
    // Create Body
    b2BodyDef bodydef;
    bodydef.type = b2_dynamicBody;
    bodydef.bullet = true;
    bodydef.position.Set(x,y);
    bodyUserData* myStruct = new bodyUserData;
    myStruct->label = input;
    bodydef.userData = myStruct;
    g_body = world->CreateBody(&bodydef);
    b2PolygonShape bodyshape;
    bodyshape.SetAsBox(0.95, 1.05);
    bodydef.position.Set(x,y);
    b2FixtureDef fixturedef;
    fixturedef.shape = &bodyshape;
    fixturedef.density = BOX_DENSITY;
    fixturedef.friction = BOX_FRICTION;
    fixturedef.restitution = BOX_RESTITUTION;
    g_body->SetAngularDamping(3);
    g_body->CreateFixture(&fixturedef);
    // Bound timer
    connect(timer, SIGNAL(timeout()), this,SLOT(paint()));
    scene->addItem(&g_pixmap);
}
