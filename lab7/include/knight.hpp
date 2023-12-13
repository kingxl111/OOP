#pragma once
#include "npc.hpp"

struct Knight : public NPC {
    Knight(int x, int y);
    Knight(std::istream &is);
    void print() override;
    void save(std::ostream &os) override;
    bool fight(std::shared_ptr<Elf> other) override;
    bool fight(std::shared_ptr<Knight> other) override;
    bool fight(std::shared_ptr<Bandit> other) override;
    friend std::ostream &operator<<(std::ostream &os, Knight &knight);

    bool accept(std::shared_ptr<NPC> visitor) override;
};