#include <iostream>

using namespace std;

class Gift { // Product
public:
    string ribbon_colour; // цвет ленточки
    string box_size; // размер коробки подарка
    string gift; // подарок внутри
};

class IGiftMaker { // ConcreteBuilder
public:
    virtual void add_ribbon(string colour) = 0;
    virtual void add_box(string size) = 0;
    virtual void put_gift(string gift) = 0;

    virtual Gift* get_gift() = 0; // get Product
};

class Elf: public IGiftMaker {
private:
    Gift* gift;
public:
    Elf() {
        gift = new Gift;
        gift->ribbon_colour = "";
        gift->box_size = "";
        gift->gift = "";
    }
    void add_ribbon(string colour) override {
        cout << "Elf added ribbon" << endl;
        gift->ribbon_colour = colour;
    }

    void add_box(string size) override {
        cout << "Elf added box" << endl;
        gift->box_size = size;
    }

    void put_gift(string gft) override {
        cout << "Elf added gift" << endl;
        gift->gift = gft;
    }

    Gift* get_gift() override {
        cout << "Elf returned gift" << endl;
        return this->gift;
    }

    ~Elf() {
        delete gift;
    }

};

class Snowman: public IGiftMaker { // Another ConcreteBuilder
private:
    Gift* gift;
public:
    Snowman() {
        gift = new Gift;
        gift->ribbon_colour = "";
        gift->box_size = "";
        gift->gift = "";
    }
    void add_ribbon(string colour) override {
        cout << "Snowman added ribbon" << endl;
        gift->ribbon_colour = colour;
    }

    void add_box(string size) override {
        cout << "Snowman added box" << endl;
        gift->box_size = size;
    }

    void put_gift(string gft) override {
        cout << "Snowman added gift" << endl;
        gift->gift = gft;
    }

    Gift* get_gift() override {
        cout << "Snowman returned gift" << endl;
        return this->gift;
    }

    ~Snowman() {
        delete gift;
    }
};

class SantaClaus {
private:
    IGiftMaker* gift_maker;
public:
    SantaClaus(IGiftMaker* _gift_maker): gift_maker(_gift_maker) {}

    void set_gift_maker(IGiftMaker* _gift_maker) {
        this->gift_maker = _gift_maker;
    }  

    Gift* create_full_gift() {
        gift_maker->add_box("big");
        gift_maker->put_gift("toy car");
        gift_maker->add_ribbon("orange");
        return gift_maker->get_gift();
    }

    Gift* create_almost_full_gift() {
        gift_maker->add_box("small");
        gift_maker->put_gift("rainbow");
        return gift_maker->get_gift();
    }

    ~SantaClaus() = default;
};

auto main() -> int {

    IGiftMaker* snowman = new Snowman();
    SantaClaus santa(snowman);

    Gift* gift1 = santa.create_full_gift();

    IGiftMaker* elf = new Elf();
    santa.set_gift_maker(elf);

    Gift* gift2 = santa.create_almost_full_gift();

    delete snowman;
    delete elf;

    return 0;
}