#ifndef BOXANDSHOOTER_H
#define BOXANDSHOOTER_H
#include <land.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>
class Wall : public Land{
public:
    Wall(float x, float y, float w, float h, QPixmap pixmap, b2World *world, QGraphicsScene *scene,int input):
        Land(x,y,w,h,pixmap,world,scene,input){}
};
class shooter : public Land{
public:
    shooter(float x, float y, float w, float h, QPixmap pixmap, b2World *world, QGraphicsScene *scene,int input):
        Land(x,y,w,h,pixmap,world,scene,input){}
};
#endif // BOXANDSHOOTER_H
