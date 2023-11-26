#include "elf.hpp"

Elf::Elf(int x, int y) : NPC(KnightType, x, y) {}
Elf::Elf(std::istream &is) : NPC(KnightType, is) {}

void Elf::print() {
    std::cout << *this;
}

void Elf::save(std::ostream &os) {
    os << KnightType << std::endl;
    NPC::save(os);
}
bool Elf::is_elf() const {
    return true;
}

bool Elf::fight(std::shared_ptr<Bandit> other) {
    fight_notify(other, false);
    return false;
}

bool Elf::fight(std::shared_ptr<Knight> other) {
    fight_notify(other, true);
    return true;
}

bool Elf::fight(std::shared_ptr<Elf> other) {
    fight_notify(other, false);
    return false;
}

std::ostream &operator<<(std::ostream &os, Elf &elf) {
    os << "elf: " << *static_cast<NPC *>(&elf) << std::endl;
    return os;
}