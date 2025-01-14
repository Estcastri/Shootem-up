#include "Game.h"
#include <iostream>

void Game::Init()
{
    std::cout << "[GAME] Init..." << std::endl;

    Nave* nave1 = new Nave();
    nave1->SetPosition(Vector3D(0.0, 0.0, -3.0));
    nave1->SetColor(Color(0.8f, 0.7f, 0.6f, 0.4f));
    this->mainScene.AddGameObject(nave1);
}

void Game::Render()
{
    this->mainScene.Render();
}

void Game::Update()
{
    this->mainScene.Update();
}

void Game::ProcessKeyPressed(unsigned char key, int px, int py)
{
    mainScene.ProcessKeyPressed(key, px, py);
}

void Game::ProcessMouseClicked(int button, int state, int x, int y)
{
    std::cout << "[GAME] Click:" << button << std::endl;
}

void Game::ProcessMouseMovement(int x, int y)
{
    std::cout << "[GAME] Movement:" << x << ", " << y << std::endl;
}