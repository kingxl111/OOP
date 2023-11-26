#include "bandit.hpp"

Bandit::Bandit(int x, int y) : NPC(KnightType, x, y) {}
Bandit::Bandit(std::istream &is) : NPC(KnightType, is) {}

void Bandit::print() {
    std::cout << *this;
}

void Bandit::save(std::ostream &os) {
    os << KnightType << std::endl;
    NPC::save(os);
}
bool Bandit::is_bandit() const {
    return true;
}

bool Bandit::fight(std::shared_ptr<Knight> other) {
    fight_notify(other, false);
    return false;
}

bool Bandit::fight(std::shared_ptr<Bandit> other) {
    fight_notify(other, false);
    return false;
}

bool Bandit::fight(std::shared_ptr<Elf> other) {
    fight_notify(other, true);
    return true;
}

std::ostream &operator<<(std::ostream &os, Bandit &elf) {
    os << "elf: " << *static_cast<NPC *>(&elf) << std::endl;
    return os;
}