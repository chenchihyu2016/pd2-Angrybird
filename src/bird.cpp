#include "bird.h"
#include <iostream>
using namespace std;
Bird::Bird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene, int input):GameItem(world)
{
    // Set pixmap
    g_pixmap.setPixmap(pixmap);
    g_pixmap.setTransformOriginPoint(g_pixmap.boundingRect().width()/2,g_pixmap.boundingRect().height()/2);
    g_size = QSize(radius*2,radius*2);
    // Create Body
    b2BodyDef bodydef;
    bodydef.type = b2_dynamicBody;
    bodydef.bullet = true;
    bodydef.position.Set(x,y);
    bodyUserData* myStruct = new bodyUserData;
        myStruct->label = input;
    bodydef.userData = myStruct;
    g_body = world->CreateBody(&bodydef);
    b2CircleShape bodyshape;
    bodyshape.m_radius = radius;
    b2FixtureDef fixturedef;
    fixturedef.shape = &bodyshape;
    fixturedef.density = BIRD_DENSITY;
    fixturedef.friction = BIRD_FRICTION;
    fixturedef.restitution = BIRD_RESTITUTION;
    g_body->SetAngularDamping(3);
    g_body->CreateFixture(&fixturedef);
    // Bound timer
    connect(timer, SIGNAL(timeout()), this,SLOT(paint()));
    scene->addItem(&g_pixmap);
}
void Bird::setLinearVelocity(b2Vec2 velocity)
{
    g_body->SetLinearVelocity(velocity);
}
double Bird::getPositionX(){
    b2Vec2 position =g_body->GetPosition();
   return position.x;
}
double Bird::getPositionY(){
    b2Vec2 position =g_body->GetPosition();
    return position.y;
}
double Bird::getVelocityX(){
    b2Vec2 vel = g_body->GetLinearVelocity();
    return vel.x;
}
double Bird::getVelocityY(){
    b2Vec2 vel = g_body->GetLinearVelocity();
    return vel.y;
}
void piggy::specialFunc(){}
void redBird::specialFunc(){}
void whiteBird::specialFunc(){
    this->setLinearVelocity(b2Vec2(40,0));
}
void blueBird::specialFunc(){
    double x =  this->getPositionX();
    double y = this->getPositionY();
    copyOne = new blueBird(x+1,y+1.5,0.25f,timer2,QPixmap(":/blueBird.png").scaled(g_pixmap.boundingRect().width(),g_pixmap.boundingRect().height()),world2,scene2,1);
    copyTwo = new blueBird(x+1,y-1.5,0.25f,timer2,QPixmap(":/blueBird.png").scaled(g_pixmap.boundingRect().width(),g_pixmap.boundingRect().height()),world2,scene2,1);
    double currentVelocityX = this->getVelocityX();
    double currentVelocityY = this->getVelocityY();
    copyOne->setLinearVelocity(b2Vec2(currentVelocityX,currentVelocityY+3));
    copyTwo->setLinearVelocity(b2Vec2(currentVelocityX,currentVelocityY-3));
}
void blackBird::specialFunc(){


}
thing::thing(float x, float y, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene,int input):GameItem(world)
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
