#pragma once
#include <GL/glut.h>
#include "Cube.h"
#include "Projectile.h"
#include <vector>

class Nave : public Cube
{
private:
    float speed;
    float friction;
    float velocityX;
    float velocityY;
    std::vector<Projectile*> projectiles;

public:
    Nave();
    void ProcessKeyPressed(unsigned char key, int px, int py) override;
    void Update() override;
    void Render() override;
    std::vector<Projectile*>& GetProjectiles() { return projectiles; }
};