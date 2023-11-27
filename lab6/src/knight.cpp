#include "bandit.hpp"
#include "elf.hpp"
#include "knight.hpp"

Knight::Knight(int x, int y) : NPC(KnightType, x, y) {}
Knight::Knight(std::istream &is) : NPC(KnightType, is) {}

void Knight::print() {
    std::cout << *this;
}

void Knight::save(std::ostream &os) {
    os << KnightType << std::endl;
    NPC::save(os);
}

// bool Knight::is_knight() const {
//     return true;
// }

bool Knight::accept(std::shared_ptr<NPC> visitor) {
    std::shared_ptr<Knight> This = std::make_shared<Knight>(*this);
    return visitor->visit(This);
}

bool Knight::fight(std::shared_ptr<Bandit> other) {
    fight_notify(other, true);
    return true;
}

bool Knight::fight(std::shared_ptr<Knight> other) {
    fight_notify(other, false);
    return false;
}

bool Knight::fight(std::shared_ptr<Elf> other) {
    fight_notify(other, false);
    return false;
}

std::ostream &operator<<(std::ostream &os, Knight &knight) {
    os << "knight: " << *static_cast<NPC *>(&knight) << std::endl;
    return os;
}