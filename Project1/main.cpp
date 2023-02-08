//Функтор - это класс, в котором перегружем объект круглые скобки
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include "Printer.h"
using namespace Engine;
//Functor
class Incrementer {
public:
	Incrementer(int x): _x(x){ }
	int operator()(int y) {
		return _x + y;
	}
	int myFunc(int y) {
		const auto add = [this,y](int a) {
			return _x+y + a;
		};
		return add(5);
	}
private:
	int _x;
};
class IVehicle {
public:
	virtual int getSpeed() const = 0;
	virtual void PrintType() const = 0;
	virtual ~IVehicle(){ }
};
#include <memory>
class Car :public IVehicle {
public:
	Car(int speed): _speed(speed){ }
	int getSpeed()const override {
		return _speed;
	}
	void PrintType() const override{
		std::cout << "Car" << std::endl;
	}
private:
	int _speed;
};
class Van :public IVehicle {
public:
	Van(int Speed):_Speed(Speed){ }
	int getSpeed()const override {
		return _Speed;
	}
	void PrintType()const override {
		std::cout << "Van" << std::endl;
	}
private:
	int _Speed;
};
class Moto :public IVehicle {
public:
	Moto(int Speed) :_Speed(Speed) { }
	int getSpeed()const override {
		return _Speed;
	}
	void PrintType()const override {
		std::cout << "Moto" << std::endl;
	}
private:
	int _Speed;
};
int main() {
	Engine::Printer h;
	h.Function();



	std::shared_ptr<IVehicle> v = std::make_shared<Car>(50);
	std::cout << "Vehicle speed: " << v->getSpeed() << std::endl;
	v->PrintType();
	Incrementer inc(50);
	int a = inc(5);
	std::cout << a << std::endl;
	//capture clause
	const auto myinc = [a](int number) {//если вместо а написать = то тогда а захватит все что находится сверху в мейне
		return a + 5+number;
	};
	//const auto myinc = [&,a](int number)//здесь берем все элементы по ссылке, а а без ссылки
	//const auto myinc = [a](int number)-> int - подсказка для лямбды , какой тип возвращаем
	std::cout << myinc(6) << std::endl;

	std::cout << inc.myFunc(3) << std::endl;
	std::cout << "================" << std::endl;
	
	std::vector <int> vec{ 1,-4,3,-2 };
	for (const auto el : vec) {
		std::cout << el << " ";
	}
	std::cout << std::endl;
	std::sort(vec.begin(), vec.end());//сортировка для вектора от меньшего к большему
	for (const auto el : vec) {
		std::cout << el << " ";
	}
	std::cout << std::endl;
	int tt = 1;
	std::sort(vec.begin(), vec.end(), [](int a, int b) {
		return std::abs(a) > std::abs(b);
		});

	for (const auto el : vec) {
		std::cout << el << " ";
	}
	std::cout << std::endl;


	Engine::Printer p;
	p.printDefault();
	return 0;
}