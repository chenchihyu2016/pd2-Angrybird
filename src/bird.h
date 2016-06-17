#ifndef BIRD_H
#define BIRD_H
#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>
#include <iostream>
using namespace std;
#define BIRD_DENSITY 10.0f
#define BIRD_FRICTION 0.2f
#define BIRD_RESTITUTION 0.5f
class Bird : public GameItem
{
public:
    Bird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene,int input);
    void setLinearVelocity(b2Vec2 velocity);
    virtual void specialFunc()=0;
    double getPositionX();
    double getPositionY();
    double  getVelocityX();
    double  getVelocityY();
    void setShot(){ shot = true; }
    bool isStop(){
        double x2= this->getPositionX();
        double y2= this->getPositionY();
        if ( (x2 != 5.0 && y2 != 6.05) && (shot == true) && (x2 == previousX)&&(y2== previousY))
                return true;
        if( x2 != previousX ) previousX = x2;
        if( y2 != previousY ) previousY = y2;
        return false;
    }
     virtual void clean();
private:
    bool shot;
    double previousX;
    double previousY;
};
class piggy : public Bird{
public:
    piggy(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene,int input):
        Bird(x,y,radius,timer,pixmap,world,scene,input){
            m_contacting = false;
            score = 0;
    }
    virtual void specialFunc();
    void  startContact(){
        if(m_contacting == false){
            score +=100;
            m_contacting = true;
         }
    }
    bool m_contacting ;
    int score;
};
class redBird : public Bird{
public:
    redBird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene,int input):
        Bird(x,y,radius,timer,pixmap,world,scene,input){}
    virtual void specialFunc();
};
class whiteBird : public Bird{
public:
    whiteBird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene,int input):
        Bird(x,y,radius,timer,pixmap,world,scene,input){}
    virtual void specialFunc();
};
class blueBird : public Bird{
public:
    blueBird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene,int input):
        Bird(x,y,radius,timer,pixmap,world,scene,input){              
            timer2 = timer;
            world2 = world ;
            scene2 = scene;
    }
    virtual void specialFunc();
    virtual void clean();
private:
    blueBird *copyOne;
    blueBird *copyTwo;
    QTimer  *timer2 ;
    b2World *world2  ;
    QGraphicsScene *scene2 ;
};
class blackBird : public Bird{
public:
    blackBird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene,int input):
        Bird(x,y,radius,timer,pixmap,world,scene,input){}
    virtual void specialFunc();
};
#endif // BIRD_H
#ifndef BOX_H
#define BOX_H
#define BOX_DENSITY 10.0f
#define BOX_FRICTION 0.1f
#define BOX_RESTITUTION 0.35f
class thing : public GameItem
{
public:
    thing(float x, float y, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene,int input);
};
#endif // BIRD_H

