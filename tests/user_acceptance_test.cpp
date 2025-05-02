#include "Player.h"
#include <catch2/catch.hpp>

TEST_CASE("User acceptance scenario: Player takes damage and heals") {
    Player p("TestUser", 100, 3);

    SECTION("Initial state") {
        REQUIRE(p.getName() == "TestUser");
        REQUIRE(p.getHealth() == 100);
    }

    SECTION("After taking 30 damage") {
        p.receiveDamage(30);
        REQUIRE(p.getHealth() == 70);
    }

    SECTION("After taking 30 damage and healing 20") {
        p.receiveDamage(30);
        p.heal(20);
        REQUIRE(p.getHealth() == 90);
    }
}