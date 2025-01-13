#include "HorizontalEnemy.h"

  

    // Simula el movimiento del enemigo
    for (int i = 0; i < 50; ++i)
    {
        enemy.UpdatePosition();
        Vector3D currentPos = enemy.GetPosition();
        std::cout << "Enemy position: (" << currentPos.GetX() << ", "
            << currentPos.GetY() << ", " << currentPos.GetZ() << ")\n";
    }

