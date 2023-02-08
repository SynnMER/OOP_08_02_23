#pragma once
#include <vector>
#include <iostream>
#include <memory>
namespace Engine {
	class Printer{
	public:
		void printDefault();
		std::shared_ptr<IVehicle> v = std::make_shared<Car>(50);//���������� Shared_ptr ��� ��� ��� ��������� ���������� ����� ��������� , � ��� counter ���������� ����� 3 
		std::shared_ptr<IVehicle> v = std::make_shared<Van>(20);
		std::shared_ptr<IVehicle> v = std::make_shared<Moto>(100);
		void Function() {
			for (size_t i = 0; i < v; i++)
			{
				std::cout << "Vehical Speed: " << v->getSpeed() << std::endl;
				v->PrintType();

			}
		}
	};
}

