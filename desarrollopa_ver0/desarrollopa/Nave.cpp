#include "Nave.h"
#include <GL/glut.h>
#include <algorithm>

Nave::Nave() : speed(0.05f), friction(0.98f), velocityX(0.0f), velocityY(0.0f)
{
}

void Nave::ProcessKeyPressed(unsigned char key, int px, int py)
{
    switch (key)
    {
    case 'w':
    case 'W':
        velocityY += speed;
        break;
    case 's':
    case 'S':
        velocityY -= speed;
        break;
    case 'a':
    case 'A':
        velocityX -= speed;
        break;
    case 'd':
    case 'D':
        velocityX += speed;
        break;
    case ' ':
        // Crea un nuevo proyectil y añádelo a la lista de proyectiles
        projectiles.push_back(new Projectile(GetPosition()));
        break;
    default:
        break;
    }
}

void Nave::Update()
{
    // Aplica fricción
    velocityX *= friction;
    velocityY *= friction;

    // Calcula la nueva posición
    float newX = GetPosition().GetX() + velocityX;
    float newY = GetPosition().GetY() + velocityY;

    // Considera el tamaño del cubo
    float CSize = GetSize();

    // Verifica los límites considerando el tamaño del cubo
    if (newX - CSize < LEFT_LIMIT) newX = LEFT_LIMIT + CSize;
    if (newX + CSize > RIGHT_LIMIT) newX = RIGHT_LIMIT - CSize;
    if (newY - CSize < BOTTOM_LIMIT) newY = BOTTOM_LIMIT + CSize;
    if (newY + CSize > TOP_LIMIT) newY = TOP_LIMIT - CSize;

    // Actualiza la posición
    SetPosition(Vector3D(newX, newY, GetPosition().GetZ()));

    // Actualiza los proyectiles
    for (auto& projectile : projectiles)
    {
        projectile->Update();
    }
}

void Nave::Render()
{
    Cube::Render();

    // Renderiza los proyectiles
    for (auto& projectile : projectiles)
    {
        projectile->Render();
    }
}