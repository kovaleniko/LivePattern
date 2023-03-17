#include <iostream>
#include <string>
#include <map>
using namespace std;
//1.����� �������� ���������� �������� ������� �� ������ ��������
//�� ��������� ������� �� ��� �����.
//2. � ���������� ������ � ���� �� ��������� ��������������� ����
// �������� ��������� ��������.

//������� ����� ��� ���������� ����������
class Aircraft {
public:
	Aircraft(string);
	virtual ~Aircraft();
private:
	//��� ������������ ����������
	string aircraftType;
	//��������� ���������� �� ����������
	map<string, string> parts;
public:
	//��������� ���������� � ����������  ����� ���������� 
	string GetPart(const string& key) {
		if (!CheckForPart(key)) {
			throw "There is no such key!";
		}
		return parts[key];
	}
	//��������� �������� ��� ���������� ����� ���������� 
	void SetPart(const string& key, const string& value) {
		parts[key] = value;
	}
	//�������� �� ������� �����
	bool CheckForPart(const string& key)
	{
		return parts.find(key) != parts.end() ? true : false;
	}
	//����������� ���������� �� ����������� ���������� 
	void Show();
};
Aircraft::Aircraft(string type) { aircraftType = type; }
Aircraft::~Aircraft() { }
void Aircraft::Show() {
	cout << "\n====================\n";
	cout << "Aircraft Type:" << aircraftType << endl;
	cout << "Frame:" << parts["frame"] << endl;
	cout << "Engine:" << parts["engine"] << endl;
	cout << "Wheels:" << parts["wheels"] << endl;
	cout << "Doors:" << parts["doors"] << endl;
}

// ����������� ����� ��������� 
class AircraftBuilder {
public:
	AircraftBuilder() {};
	virtual ~AircraftBuilder() {};
protected:
	Aircraft* aircraft;
public:
	Aircraft* GetAircraft() { return aircraft; }
	virtual void BuildFrame() = 0;
	virtual void BuildEngine() = 0;
	virtual void BuildWheels() = 0;
	virtual void BuildDoors() = 0;
	virtual void BuildWings() = 0;
};

//����� ���������. ����� ��������� ����������� 
class HangGliderBuilder :public AircraftBuilder {
public:
	HangGliderBuilder();
	virtual ~HangGliderBuilder();
public:
	void BuildFrame();
	void BuildEngine();
	void BuildWheels();
	void BuildDoors();
	void BuildWings();
};
HangGliderBuilder::HangGliderBuilder() {
	aircraft = new Aircraft("Hang Glider");
}
HangGliderBuilder::~HangGliderBuilder() { delete aircraft; }
void HangGliderBuilder::BuildFrame() {
	aircraft->SetPart("frame", "Hang glider frame");
}
void HangGliderBuilder::BuildEngine() {
	aircraft->SetPart("engine", "no engine");
}
void HangGliderBuilder::BuildWheels() {
	aircraft->SetPart("wheels", "no wheels");
}
void HangGliderBuilder::BuildDoors() {
	aircraft->SetPart("doors", "no doors");
}
void HangGliderBuilder::BuildWings() {
	aircraft->SetPart("wings", "1");
}

//����� ���������. ����� ��������� ������� 
class GliderBuilder : public AircraftBuilder {
public:
	GliderBuilder();
	virtual ~GliderBuilder();
public:
	void BuildFrame();
	void BuildEngine();
	void BuildWheels();
	void BuildDoors();
	void BuildWings();
};
GliderBuilder::GliderBuilder()
{
	aircraft = new Aircraft("Glider");
}
GliderBuilder::~GliderBuilder() { delete aircraft; }
void GliderBuilder::BuildFrame() {
	aircraft->SetPart("frame", "Glider frame");
}
void GliderBuilder::BuildEngine() {
	aircraft->SetPart("engine", "no engine");
}
void GliderBuilder::BuildWheels() {
	aircraft->SetPart("wheels", "1");
}
void GliderBuilder::BuildDoors() {
	aircraft->SetPart("doors", "1");
}
void GliderBuilder::BuildWings() {
	aircraft->SetPart("wings", "2");
}

/* ����� ��������� ����� ��������� ���������� �������
� ������� ��������� */
class AircraftConstructor {
	AircraftBuilder* _build;
public:
	AircraftConstructor();
	virtual ~AircraftConstructor();
	void Construct(AircraftBuilder* aircraftBuilder);
};
AircraftConstructor::AircraftConstructor() { }
AircraftConstructor::~AircraftConstructor() { }
void AircraftConstructor::Construct(AircraftBuilder* aircraftBuilder)
{
	aircraftBuilder->BuildFrame();
	aircraftBuilder->BuildEngine();
	aircraftBuilder->BuildWheels();
	aircraftBuilder->BuildDoors();
}
int main1() {
	try {
		AircraftBuilder* builder;
		//������� ������ ������ ��������� 
		AircraftConstructor* shop = new AircraftConstructor();
		//������� ������ ������ ���������.  
		//���� ������ ����� ��������� ����������� 
		builder = new HangGliderBuilder();
		//��������� ����������
		shop->Construct(builder);
		//���������� ���������� � ����������� 
		builder->GetAircraft()->Show();
		//������� ������ ������ ���������.  
		//���� ������ ����� ��������� ������� 
		delete builder;
		builder = new GliderBuilder();
		//��������� ������  
		shop->Construct(builder);
		//���������� ���������� � �������
		builder->GetAircraft()->Show();
		delete builder;
		delete shop;
	}
	catch (char* str) { cout << endl << str << endl; }
	return 0;
}

