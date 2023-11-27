#include <iostream>

using namespace std;

class RedSquare;
class SparrowHills;

class Visitor {
public:
    virtual void visit(RedSquare& ref) = 0;
    virtual void visit(SparrowHills& ref) = 0; 
};

class Place {
public:
    virtual void accept(Visitor &v) = 0;
};

class RedSquare : public Place {
public:
    void accept(Visitor &v) override {
        v.visit(*this);
    }
};

class SparrowHills : public Place {
public:
    void accept(Visitor &v) override {
        v.visit(*this);
    }
};

class HolidayMaker : public Visitor {
public:
    void visit(RedSquare& ref) override {
        cout << "Welcome to Red Square!" << endl;
    }
    void visit(SparrowHills& ref) {
        cout << "Welcome to Sparrow Hills!" << endl;
    }
};


auto main() -> int {

    RedSquare rs;
    SparrowHills sh;
    Place* places[] = {&rs, &sh};

    HolidayMaker hm;

    for (size_t i = 0; i < 2; i++) {
        places[i]->accept(hm);
    }

    return 0;
}