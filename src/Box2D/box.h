#ifndef BOX_H
#define BOX_H

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>

#define BOX_DENSITY 5.0f
#define BOX_FRICTION 0.2f
#define BOX_RESTITUTION 0.5f

class thing : public GameItem
{
public:
    thing(float x, float y, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
};



#endif // BIRD_H
