#include <iostream>
#include <list>

using namespace std;

class IObserver {
public:
    virtual void update(int updatable1, int updatable2) = 0;
};

class IObservable {
public: 
    list<IObserver*> observers;

    virtual void add_observer(IObserver* obs) {
        observers.push_back(obs);
    };
    virtual void remove_observer(IObserver* obs) {
        observers.remove(obs);
    }
    virtual void notify() = 0;
};  

class Engine : public IObservable {
private:
    int oil_pressure;
    int antifreeze_temperature;
public:
    Engine(): oil_pressure(0), antifreeze_temperature(0) {}

    void set_parameters(int _oil_pressure, int _antifreeze_temperature) {
        this->oil_pressure = _oil_pressure;
        this->antifreeze_temperature = _antifreeze_temperature;
        notify();
    }

    void notify() override {
        for (auto obs : observers) {
            obs->update(oil_pressure, antifreeze_temperature);
        }
        
    }

};

class OilPressureSensor : public IObserver {
public:
    void update(int pressure, int _) override {
        std::cout << "Oil pressure has updated! Current pressure: " << pressure << std::endl;
    }
};

class AntifreezeTemperatureSensor : public IObserver {
public: 
    void update(int _, int temperature) override {
        std::cout << "Antifreeze temperature has updated! Current temperature: " << temperature << std::endl;
    } 
};

auto main() -> int {

    Engine engine;
    OilPressureSensor oil_s;
    AntifreezeTemperatureSensor antifreeze_s;

    engine.add_observer(&oil_s);
    engine.add_observer(&antifreeze_s);

    engine.set_parameters(2, 92);
    std::cout << std::endl;
    engine.set_parameters(3, 100);

    return 0;
}