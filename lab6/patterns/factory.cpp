#include <iostream>

using namespace std;

enum class Automobil { car, truck };

class IProduction {
public:
    virtual void release() = 0;
};

class Car : public IProduction {
public: 
    void release() override {
        cout << "Car has been released!" << endl;
    }
};

class Truck : public IProduction {
public:
    void release() override {
        cout << "Truck has been released!" << endl;
    }
};

class Factory  {
public:
    IProduction* create(Automobil automobil) {
        switch (automobil) {
        case Automobil::car:
            return new Car;
            break;
        case Automobil::truck:
            return new Truck;
            break;
        default:
            return nullptr;
            break;
        }
    }
};


auto main() -> int {

    Factory f;
    IProduction* new_car = f.create(Automobil::car);
    new_car->release();

    new_car = f.create(Automobil::truck);
    new_car->release();

    return 0;
}