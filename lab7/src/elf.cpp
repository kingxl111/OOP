#include "elf.hpp"
#include "bandit.hpp"
#include "knight.hpp"

Elf::Elf(int x, int y) : NPC(ElfType, x, y) {}
Elf::Elf(std::istream &is) : NPC(ElfType, is) {}

void Elf::print() {
    std::cout << *this;
}

bool Elf::accept(std::shared_ptr<NPC> visitor) {
    return visitor->fight(std::shared_ptr<Elf>(this,[](Elf*){}));
}

void Elf::save(std::ostream &os) {
    os << ElfType << std::endl;
    NPC::save(os);
}


bool Elf::fight(std::shared_ptr<Elf> other) {
    fight_notify(other, false);
    return false;
}

bool Elf::fight(std::shared_ptr<Knight> other) {
    fight_notify(other, true);
    return true;
}

bool Elf::fight(std::shared_ptr<Bandit> other) {
    fight_notify(other, false);
    return false;
}

std::ostream &operator<<(std::ostream &os, Elf &Elf) {
    os << "Elf: " << *static_cast<NPC *>(&Elf) << std::endl;
    return os;
}