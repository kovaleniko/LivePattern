﻿// ConsoleApplication16.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <iostream>
#include "AbstractFab.h"
#include "Builder.h"
#include "Fabrika.h"
#include "Prototype.h"
using namespace std;

class Single {
	static Single* ptr;
protected:
	Single() {};
	//Single(const Single&) {}
	Single(const Single&) = delete;//after c++11
public:
	static Single* get() { return ptr; }

};
Single* Single::ptr = new Single;
//http - 80


int main()
{
	AbstractWeapon* Gun = new Shotgun();
	AbstractBullet* Shuter= Gun->Shoot();
	PcConfigurator MyPC;
	MyPC.SetPCFactory(new HomePcFactory());
	PC pc;
	MyPC.Configure(&pc);
}
