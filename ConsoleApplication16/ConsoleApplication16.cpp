// ConsoleApplication16.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <iostream>
#include "AbstractFab.cpp"
#include "Builder.cpp"
#include "Fabrika.cpp"
#include "Prototype.cpp"
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
