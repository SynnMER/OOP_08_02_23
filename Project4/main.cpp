//#include <iostream>
//#include <vector>
//class IVehicle {
//public:
//	virtual void printName() const = 0;
//	virtual ~IVehicle() {}
//};
//class Car : public IVehicle {
//public:
//	void printName() const override {
//		std::cout << "Car class" << std::endl;
//	}
//};
//void foo(const std::vector<const IVehicle*>& vec) {
//	for (size_t i = 0; i < vec.size(); i++) {
//		vec[i]->printName();
//	}
//}
//int main() {
//	IVehicle* vehicle = new IVehicle();
//	IVehicle* vehicle2 = new Car();
//	std::vector<IVehicle*> vec{ vehicle2 };
//	foo(vec);
//}