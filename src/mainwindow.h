#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QList>
#include <QDesktopWidget>
#include <QTimer>
#include <Box2D/Box2D.h>
#include <QMouseEvent>
#include <iostream>
#include <gameitem.h>
#include <land.h>
#include <bird.h>
#include <QGraphicsTextItem>
using namespace std;

namespace Ui {
class MainWindow;
}
class MyContactListener : public b2ContactListener
  {
public:
    MyContactListener(piggy* Pig):pig(Pig){}
    void BeginContact(b2Contact* contact) {
      //check if fixture A was a bird
      bodyUserData* body1 = (bodyUserData*)contact->GetFixtureA()->GetBody()->GetUserData();
      bodyUserData* body2 = (bodyUserData*)contact->GetFixtureB()->GetBody()->GetUserData();
     if ( (body1->label == 0  && body2->label ==1)||(body1->label == 1  && body2->label == 0 ) )
          pig->startContact();
    }
    void EndContact(b2Contact* contact) {
          //check if fixture A was a bird
          bodyUserData* body1 = (bodyUserData*)contact->GetFixtureA()->GetBody()->GetUserData();
          bodyUserData* body2 = (bodyUserData*)contact->GetFixtureB()->GetBody()->GetUserData();
         if ( (body1->label == 0  && body2->label ==1)||(body1->label == 1  && body2->label == 0 ) )
              pig->endContact();
    }
private:
    piggy * pig ;
};
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void showEvent(QShowEvent *);
    bool eventFilter(QObject *,QEvent *event);
    void keyPressEvent(QKeyEvent* event);
    void closeEvent(QCloseEvent *);
signals:
    // Signal for closing the game
    void quitGame();

private slots:
    void tick();
    // For debug slot
    void QUITSLOT();
private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    b2World *world;
    QList<GameItem *> itemList;
    QTimer timer;
    Bird * current;
    thing * thingPtr;
    shooter* shootPtr;
    bool keyP;
    piggy  * pig;
    b2Fixture* GetFixtureA();
    b2Fixture* GetFixtureB();
    MyContactListener *myContactListenerInstance;
    QGraphicsTextItem *word;
    bool control;
    void hold(double x, double y){
         current ->g_body ->SetTransform(b2Vec2(x,y),0);
    }
    double x1,y1;
};

#endif // MAINWINDOW_H
