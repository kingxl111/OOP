#include "bandit.hpp"
#include "elf.hpp"
#include "knight.hpp"

Bandit::Bandit(int x, int y) : NPC(BanditType, x, y) {}
Bandit::Bandit(std::istream &is) : NPC(BanditType, is) {}

void Bandit::print() {
    std::cout << *this;
}

void Bandit::print(std::ostream &outfs) {
    outfs << *this;
}

void Bandit::save(std::ostream &os) {
    os << BanditType << std::endl;
    NPC::save(os);
}
// bool Bandit::is_bandit() const {
//     return true;
// }

bool Bandit::accept(std::shared_ptr<NPC> visitor) {
    std::shared_ptr<Bandit> This = std::make_shared<Bandit>(*this);
    return visitor->visit(This);
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

std::ostream &operator<<(std::ostream &os, Bandit &bandit) {
    os << "bandit: " << *static_cast<NPC *>(&bandit) << std::endl;
    return os;
}