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
struct bodyUserData{
    int label;
};

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
private:
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
    void  endContact(){
        if(m_contacting == true )
            m_contacting = false;
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

