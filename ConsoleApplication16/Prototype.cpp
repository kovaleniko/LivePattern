#include <iostream>
#include <string>
using namespace std;
//1. ���������� ��� ������ ��������� �������, ������ �� ���� ��
//�� ������, ��� � ���, ����� ������ ��� ��������.
//2. ������ ����������� �������� ������������ �� ����� 
//����������(��������, ��� ������������ ��������).
//3. ���������� ������ ����� ��������� ��� ����� �������
//���������� ���������, ������� ����� ��������� ����������� 
//������� ������� ��������� ���������� � ����������� �� ������
//������� �������� ���������� ������.

/*  * ��� ����������� ������� ����� Device.
* �� ���������� ������� Clone, ������� ����������
* ������ �������� Prototype */
class Device {
private: //�������� ���������� 
	string name;
public:
	//������������ 
	Device() : Device("Unknown device") {}
	Device(string dname) { SetName(dname); }
	//��������������� ������� 
	string GetName() const { return name; }
	void SetName(string dname) { name = dname; }
	//����� ����������� �������
	//��� ����� �������������� ��� �������� ����� 
	virtual Device* Clone() const = 0;
	//����������� ������
	void Show() const {
		cout << "\nName is\n" << GetName() << "\n";
	}
};
/* * ���������� ������� ���������� ����� Car */
class Car : public Device {
private:
	//�������� ������ 
	string manufacturer;
	string description;
	string color;
	int year;
public: //������������
	Car() :Car("No information", "No description", "No color", 0)
	{
		SetName("Car");
	}
	Car(string cmanufacturer, string cdescription, string ccolor, int cyear);
public:
	//��������������� ������� 
	int GetYear()const { return year; }
	string GetManufacturer()const { return manufacturer; }
	string GetDescription()const { return description; }
	string GetColor()const { return manufacturer; }
	void SetYear(int cyear) { year = cyear; }
	void SetManufacturer(string cmanufacturer) { manufacturer = cmanufacturer; }
	void SetColor(string ccolor) { color = ccolor; }
	void SetDescription(string cdescription) { description = cdescription; }
	//���������� ����������� ������� � �������
	Device* Clone()const;
	void Show() const;
};
//���������� ������������
Car::Car(string cmanufacturer, string cdescription, string ccolor, int cyear) {
	SetName("Car");
	SetManufacturer(cmanufacturer);
	SetDescription(cdescription);
	SetColor(ccolor); SetYear(cyear);
}
//������� ������������
Device* Car::Clone() const {
	Car* tempCar = new Car();
	/* �������� ��������!
	* ��� ��� ������ � ������������ ������� �����
	* ���������� ����������� �����������, �����������
	* �������� � ����������� �������� =   */
	*tempCar = *this;
	return tempCar;
}
//����������� �� ����� ������ 
void Car::Show() const {
	Device::Show();
	cout << "\nDescription of car is\n" <<GetDescription() << "\n"; 
	cout << "\nManufacturer of car is\n";
	cout << GetManufacturer() << "\n";
	cout << "\nYear of car is\n" << GetYear() << "\n";
	cout << "\nColor of car is\n" << GetColor() << "\n";
}
int main2() {
	//������ ������ 
	string manufacturer; 
	cout << endl << "Input manufacturer of car:" << endl; 
	std::getline(std::cin, manufacturer); 
	string description; 
	cout << "Input description of car:" << endl;
	std::getline(std::cin, description); 
	string color;
	cout << "Input color of car:" << endl;
	std::getline(std::cin, color);
	int year;
	cout << "Input year of car:" << endl;
	cin >> year;
	//�������� ������ 
	Car c(manufacturer, description, color, year); 

	c.Show(); cout << "Let's clone!\nLet's prototype!" << endl; 
	//��������� ������
	Car* copy = (Car*)c.Clone(); 
	copy->Show(); 
	
	Car* copy2 = new Car(c);//����� ������������ �����������
	//������� ������������� ������
	delete copy;
	return 0;
}

