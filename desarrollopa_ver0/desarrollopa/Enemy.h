#pragma once
#include "Sphere.h"

class Enemy : public Sphere
{

protected:
	
	Vector3D puntoA, puntoB;

public:
	
	Enemy() :puntoA(), puntoB(){}
	Enemy(Vector3D A, Vector3D B): puntoA(A), puntoB(B){}

	//void CreateEnemy() {
	//}

	void EnemyMovement();

	Vector3D GetPuntoA() { return this->puntoA; }
	Vector3D GetPuntoB() { return this->puntoB; }
	
	void SetPuntoA(Vector3D newPuntoA) {
		this->puntoA = newPuntoA;
	}

	void SetPuntoB(Vector3D newPuntoB) {
		this->puntoB = newPuntoB;
	}

};

