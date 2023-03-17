#include <iostream>
using namespace std;
//1. ����� �� ������ �������� �� ����������� ���� 
//������������ ��������.
//2. ������ �� �������� ���������� ��� ��������, ������� ��� 
//���� ���������.
//3. ���������� ���� ����������� ��������� ����� / ������ 
//������������ �����������.
/*
* ����� � ���������� ������������.
* ������������ ��� ����������� ���������. */
struct Point3D {
	int X; int Y; int Z;
};
/* * ������ � ���������� ������������.
* ������������ ��� ����������� �����������. */
struct Vector3D {
	int X; int Y; int Z;
};
/* * ����� ����������� ����. */
class AbstractBullet {
private:
	Point3D location;
	Vector3D direction;
	double caliber;
public:
	/* * ������� ��������� ���� */
	Point3D GetLocation() { return location; }
	void SetLocation(const Point3D& newLocation)
	{
		location = newLocation;
	}
	/* * ����������� ���� */
	Vector3D GetDirection() { return direction; }
	void SetDirection(const Vector3D& newDirection) {
		direction = newDirection;
	}
	/* * ������ ���� */
	double GetCaliber() { return caliber; }
	void SetCaliber(double newCaliber) { caliber = newCaliber; }
	/* * ������ �������� ����. */
	void StartMovement() {
		// ���������� ������ �������� 
	}
	/* * ����� ��������� ����.
	* ��� ��� ������ ���� ���� �������� ���� ���������,
	* �� ����� ������ ���� ���������� � ����������. */
	virtual void HitTarget(void* target) = 0;
	/* * �����, ����������� �������� ����.
	* ��� ��� ������ ���� ���� ����� ������ ����������
	* ��������, �� ����� ������ ���� ����������
	* � ����������. */
	virtual void Movement() = 0;
};
/* * ����� ���� ��� ��������������� ������. */
class AutomaticBullet : public AbstractBullet {
public:
	void HitTarget(void* target) {
		//���������� ��������� ���� target 
		cout << "Hit by automatic bullet\n";
	}
	void Movement() {
		//���������� ��������� �������� ���� 
	}
};
/* * ����� ���� ��� ���������. */
class ShotgunBullet : public AbstractBullet {
public:
	void HitTarget(void* target) {
		//���������� ��������� ���� target 
		cout << "Hit by shotgun bullet\n";
	}
	void Movement() {
		//���������� ��������� �������� ���� 
	}
};
/* * ����� ������������ ������ */
class AbstractWeapon {
protected:
	/*  * ��������� ����� ��� �������� ����.  */
	virtual AbstractBullet* CreateBullet() = 0;
private:
	Point3D location;
	Vector3D direction;
	double caliber;
public:
	/*  * ������� ��������� ������  */
	Point3D GetLocation() { return location; }
	void SetLocation(const Point3D& newLocation) {
		location = newLocation;
	}
	/*  * ����������� ������  */
	Vector3D GetDirection() { return direction; }
	void SetDirection(const Vector3D& newDirection) {
		direction = newDirection;
	}
	/*  * ������ ������  */
	double GetCaliber() { return caliber; }
	void SetCaliber(double newCaliber) { caliber = newCaliber; }  /*  * �����, ������������ �������.  * ���������� ��������� ��������� ����.  */
	AbstractBullet* Shoot() {
		//�������� ������� ���� � ������� ���������� ������
		AbstractBullet* bullet = CreateBullet();
		//��������� ���� �� ������� ��������� ������ 
		bullet->SetCaliber(this->GetCaliber());
		bullet->SetLocation(this->GetLocation());
		bullet->SetDirection(this->GetDirection());
		//������ �������� ����  
		bullet->StartMovement();
		//���������� ��������� ����  
		return bullet;
	}
};
/* * ����� ��������������� ������. */
class AutomaticWeapon : public AbstractWeapon {
public:
	AutomaticWeapon() { this->SetCaliber(20); }
protected:
	/*  * ���������� ���������� ������.
	* ������� ��������� ����,
	* ������������� ��� �������� ���� ������.  */
	AbstractBullet* CreateBullet() {
		return new AutomaticBullet();
	}
};
/* * ����� ���������. */
class Shotgun :public AbstractWeapon
{
public:
	Shotgun() { this->SetCaliber(50); }
protected:
	/*  * ���������� ���������� ������.
	* ������� ��������� ����,
	* ������������� ��� �������� ���� ������.  */
	AbstractBullet* CreateBullet() { return new ShotgunBullet(); }
};




