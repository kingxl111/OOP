#include "bandit.hpp"
#include "elf.hpp"
#include "knight.hpp"

Elf::Elf(int x, int y) : NPC(ElfType, x, y) {}
Elf::Elf(std::istream &is) : NPC(ElfType, is) {}

void Elf::print() {
    std::cout << *this;
}

void Elf::save(std::ostream &os) {
    os << ElfType << std::endl;
    NPC::save(os);
}

// bool Elf::is_elf() const {
//     return true;
// }

bool Elf::accept(std::shared_ptr<NPC> visitor) {
    std::shared_ptr<Elf> This = std::make_shared<Elf>(*this);
    return visitor->visit(This);
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