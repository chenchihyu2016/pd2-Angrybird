#ifndef CONTACTLISTENER_H
#define CONTACTLISTENER_H
class MyContactListener : public b2ContactListener
  {
public:
    MyContactListener(piggy* Pig,piggy* Pig2):pig(Pig),pig2(Pig2){
        score = 0;
    }
    void BeginContact(b2Contact* contact) {
      bodyUserData* body1 = (bodyUserData*)contact->GetFixtureA()->GetBody()->GetUserData();
      bodyUserData* body2 = (bodyUserData*)contact->GetFixtureB()->GetBody()->GetUserData();
     if ( (body1->label == 0  && body2->label ==1)||(body1->label == 1  && body2->label == 0 ) ){
          pig->startContact();
          score+=100;
     }
     else if ( (body1->label == 1  && body2->label ==3)||(body1->label == 3  && body2->label ==1)){
         pig2->startContact();
         score+=100;
     }
    }
    int score;
private:
    piggy * pig,*pig2 ;
};

#endif // CONTACTLISTENER_H
