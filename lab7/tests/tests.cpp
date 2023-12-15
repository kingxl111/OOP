#include <gtest/gtest.h>
#include "npc.hpp"
#include "bandit.hpp"
#include "elf.hpp"
#include "knight.hpp"

TEST(NPCInteractions, test1) {
    std::shared_ptr<NPC> bandit = std::make_shared<Bandit>(0, 0);
    std::shared_ptr<NPC> knight = std::make_shared<Knight>(1, 1);

    bool murder = bandit->accept(knight);
    ASSERT_TRUE(murder);
}

TEST(NPCInteractions, test2) {
    std::shared_ptr<NPC> bandit = std::make_shared<Bandit>(0, 0);
    std::shared_ptr<NPC> elf = std::make_shared<Elf>(1, 1);

    bool murder = bandit->accept(elf);
    ASSERT_FALSE(murder);
}

TEST(NPCInteractions, test3) {
    std::shared_ptr<NPC> bandit1 = std::make_shared<Bandit>(0, 0);
    std::shared_ptr<NPC> bandit2 = std::make_shared<Bandit>(1, 1);

    bool murder = bandit1->accept(bandit2);
    ASSERT_FALSE(murder);
}

TEST(NPCInteractions, test4) {
    std::shared_ptr<NPC> knight1 = std::make_shared<Knight>(0, 0);
    std::shared_ptr<NPC> knight2 = std::make_shared<Knight>(1, 1);

    bool murder = knight1->accept(knight2);
    ASSERT_FALSE(murder);
}

TEST(NPCInteractions, test5) {
    std::shared_ptr<NPC> knight = std::make_shared<Knight>(0, 0);
    std::shared_ptr<NPC> elf = std::make_shared<Elf>(1, 1);

    bool murder = knight->accept(elf);
    ASSERT_TRUE(murder);
}

TEST(NPCInteractions, test6) {
    std::shared_ptr<NPC> knight = std::make_shared<Knight>(0, 0);
    std::shared_ptr<NPC> bandit = std::make_shared<Bandit>(1, 1);

    bool murder = knight->accept(bandit);
    ASSERT_FALSE(murder);
}

TEST(NPCInteractions, test7) {
    std::shared_ptr<NPC> elf = std::make_shared<Elf>(0, 0);
    std::shared_ptr<NPC> knight = std::make_shared<Knight>(1, 1);

    bool murder = elf->accept(knight);
    ASSERT_FALSE(murder);
}

TEST(NPCInteractions, test8) {
    std::shared_ptr<NPC> elf1 = std::make_shared<Elf>(0, 0);
    std::shared_ptr<NPC> elf2 = std::make_shared<Elf>(1, 1);

    bool murder = elf1->accept(elf2);
    ASSERT_FALSE(murder);
}

TEST(NPCInteractions, test9) {
    std::shared_ptr<NPC> elf = std::make_shared<Elf>(0, 0);
    std::shared_ptr<NPC> bandit = std::make_shared<Bandit>(1, 1);

    bool murder = elf->accept(bandit);
    ASSERT_TRUE(murder);
}


int main(int argc, char** argv) {

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}