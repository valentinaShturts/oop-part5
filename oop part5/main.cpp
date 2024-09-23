#include <iostream>
using namespace std;


class Engine
{
	char* name;
public:
	Engine(const char* n)
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
	}
	Engine(const Engine& obj)
	{
		name = new char[strlen(obj.name) + 1];
		strcpy_s(name, strlen(obj.name) + 1, obj.name);
		cout << "ENGINE COPY" << endl;
	}
	~Engine()
	{
		delete[]  name;
	}
	void PrintEngine() const
	{
		cout << "Engine name: " << name << endl;
	}
	char* GetName()
	{
		return name;
	}
	void SetName(const char* n)
	{
		if (name != nullptr) delete[] name;
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
	}
};

class Car
{
	char* model;
	int year;
	Engine eng;
	//Cond cond;
public:

	Car(const char* n, int y, const char* e) : year(y), eng(e)
	{
		model = new char[strlen(n) + 1];
		strcpy_s(model, strlen(n) + 1, n);
	}
	Car(const Car& other) : year(other.year), eng(other.eng)
	{
		this->model = new char(strlen(other.model) + 1);
		strcpy_s(this->model, strlen(other.model) + 1, other.model);
		cout << "COPY" << endl;
	}
	~Car()
	{
		cout << "Destructor" << endl;
		delete[]model;
	}
	void Print() const
	{
		cout << "Model: " << model << endl <<"Year: " << year << endl;
		eng.PrintEngine();
	}
};

int main()
{
	Car car("Toyota", 2000, "Engine24");
	car.Print();
	Car car2 = car;
	car2.Print();
}