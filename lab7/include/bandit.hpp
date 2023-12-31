#pragma once
#include "npc.hpp"

struct Bandit : public NPC {
    Bandit(int x, int y);
    Bandit(std::istream &is);

    void print() override;
    void save(std::ostream &os) override;
    bool fight(std::shared_ptr<Elf> other) override;
    bool fight(std::shared_ptr<Knight> other) override;
    bool fight(std::shared_ptr<Bandit> other) override;
    bool accept(std::shared_ptr<NPC> visitor) override;

    friend std::ostream &operator<<(std::ostream &os, Bandit &bandit);
};