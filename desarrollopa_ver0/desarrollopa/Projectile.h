#pragma once
#include <GL/glut.h>
#include "Sphere.h"

// Define los límites de la pantalla
const float LEFT_LIMIT = -4.0f;
const float RIGHT_LIMIT = 4.0f;
const float TOP_LIMIT = 3.0f;
const float BOTTOM_LIMIT = -3.0f;

class Projectile : public Sphere
{
private:
    float speed;

public:
    Projectile(Vector3D position, float radius = 0.05f) : speed(0.001f) // Ajusta la velocidad según sea necesario
    {
        SetPosition(position);
        SetRadius(radius); // Establece el tamaño de la esfera
        SetColor(Color(1.0f, 0.0f, 0.0f, 1.0f)); // Color rojo para el proyectil
    }

    void Update() override
    {
        // Mueve el proyectil hacia arriba
        SetPosition(Vector3D(GetPosition().GetX(), GetPosition().GetY() + speed, GetPosition().GetZ()));
    }

    bool IsOutOfScreen()
    {
        return GetPosition().GetY() > TOP_LIMIT || GetPosition().GetY() < BOTTOM_LIMIT ||
            GetPosition().GetX() > RIGHT_LIMIT || GetPosition().GetX() < LEFT_LIMIT;
    }
};