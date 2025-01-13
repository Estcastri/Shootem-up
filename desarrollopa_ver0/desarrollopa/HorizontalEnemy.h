#pragma once
#include "Enemy.h"

class HorizontalEnemy : public Enemy
{
private:
    float speed;    
    bool movingRight;  

public:
    
    HorizontalEnemy() : Enemy(), speed(0.1f), movingRight(true) {}

    HorizontalEnemy(Vector3D A, Vector3D B, float speed)
        : Enemy(A, B), speed(speed), movingRight(true) {}

    void UpdatePosition()
    {
        Vector3D currentPosition = GetPosition();

        if (movingRight)
        {
            currentPosition.SetX(currentPosition.GetX() + speed);

            if (currentPosition.GetX() >= puntoB.GetX())
            {
                currentPosition.SetX(puntoB.GetX());
                movingRight = false;
            }
        }        else
        {
            currentPosition.SetX(currentPosition.GetX() - speed);

            if (currentPosition.GetX() <= puntoA.GetX())
            {
                currentPosition.SetX(puntoA.GetX()); 
                movingRight = true;
            }
        }

        SetPosition(currentPosition);
    }

    float GetSpeed() const { return speed; }
    void SetSpeed(float newSpeed) { speed = newSpeed; }
};
