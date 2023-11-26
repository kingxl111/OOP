#pragma once
#include "npc.hpp"

struct Elf : public NPC {
    Elf(int x, int y);
    Elf(std::istream &is);
    void print() override;
    void save(std::ostream &os) override;
    bool is_elf() const override;
    bool fight(std::shared_ptr<Knight> other) override;
    bool fight(std::shared_ptr<Bandit> other) override;
    bool fight(std::shared_ptr<Elf> other) override;
    friend std::ostream &operator<<(std::ostream &os, Elf &elf);
};