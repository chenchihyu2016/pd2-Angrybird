#include "land.h"
Land::Land(float x, float y, float w, float h, QPixmap pixmap, b2World *world, QGraphicsScene *scene,int input):GameItem(world)
{
    // Set pixmap
    g_pixmap.setPixmap(pixmap);
    g_size = QSize(w,h);
    // Create body
    b2BodyDef bodyDef;
    bodyUserData* myStruct = new bodyUserData;
    myStruct->label = input;
    bodyDef.userData = myStruct;
    bodyDef.position.Set(x,y);
    g_body = world->CreateBody(&bodyDef);
    b2PolygonShape bodyBox;
    bodyBox.SetAsBox(w,h);
    g_body->CreateFixture(&bodyBox,9.0f);
    scene->addItem(&g_pixmap);
    paint();
}
