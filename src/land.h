#ifndef LAND_H
#define LAND_H

#include <gameitem.h>
#include <QGraphicsScene>

class Land : public GameItem
{
public:
    Land(float x, float y, float w, float h, QPixmap pixmap, b2World *world, QGraphicsScene *scene,int input);
};
class Box : public Land{
public:
    Box(float x, float y, float w, float h, QPixmap pixmap, b2World *world, QGraphicsScene *scene,int input):
        Land(x,y,w,h,pixmap,world,scene,input){}
};
class shooter : public Land{
public:
    shooter(float x, float y, float w, float h, QPixmap pixmap, b2World *world, QGraphicsScene *scene,int input):
        Land(x,y,w,h,pixmap,world,scene,input){}
};

#endif // LAND_H
