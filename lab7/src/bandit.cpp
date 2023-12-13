#include "bandit.hpp"
#include "elf.hpp"
#include "knight.hpp"

Bandit::Bandit(int x, int y) : NPC(BanditType, x, y) {}
Bandit::Bandit(std::istream &is) : NPC(BanditType, is) {}

bool Bandit::accept(std::shared_ptr<NPC> visitor){
    return visitor->fight(std::shared_ptr<Bandit>(this,[](Bandit*){}));
}

void Bandit::print()
{
    std::cout << *this;
}

void Bandit::save(std::ostream &os)
{
    os << BanditType << std::endl;
    NPC::save(os);
}


bool Bandit::fight(std::shared_ptr<Elf> other)
{
    fight_notify(other, true);
    return true;
}

bool Bandit::fight(std::shared_ptr<Knight> other)
{
    fight_notify(other, false);
    return false;
}

bool Bandit::fight(std::shared_ptr<Bandit> other)
{
    fight_notify(other, false);
    return false;
}

std::ostream &operator<<(std::ostream &os, Bandit &bandit)
{
    os << "bandit: " << *static_cast<NPC *>(&bandit) << std::endl;
    return os;
}

