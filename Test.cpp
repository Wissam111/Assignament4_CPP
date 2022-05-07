#include "Player.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
#include "Game.hpp"
#include "doctest.h"
#include <string>
#include <iostream>
using namespace std;
using namespace coup;
#include <algorithm>
#include <time.h>

TEST_CASE("not valid  input test case")
{
    Game game_1{};
    Duke duke{game_1, "Moshe"};
    Assassin assassin{game_1, "Yossi"};
    Ambassador ambassador{game_1, "Meirav"};
    Captain captain{game_1, "Reut"};
    Contessa contessa{game_1, "Gilad"};

    duke.income();

    CHECK_THROWS(duke.income());
    CHECK_THROWS(ambassador.income());
    CHECK_THROWS(captain.income());
    CHECK_THROWS(contessa.coup(assassin));
    CHECK_THROWS(captain.coup(assassin));
    CHECK_THROWS(ambassador.coup(assassin));
    CHECK_THROWS(contessa.coup(duke));

    CHECK_THROWS(assassin.coup(duke));
    assassin.income();
    CHECK_THROWS(ambassador.coup(duke));
    ambassador.income();
    CHECK_THROWS(captain.coup(duke));
    captain.income();
    CHECK_THROWS(contessa.coup(duke));
    contessa.income();
    duke.income();
    assassin.setCoins(3);
    assassin.coup(ambassador);
    CHECK_THROWS(ambassador.income());

    captain.setCoins(10);
    CHECK_THROWS(captain.income());
}

TEST_CASE("valid input")
{
    Game game_2{};

    Duke duke{game_2, "Moshe"};
    Assassin assassin{game_2, "Yossi"};
    Ambassador ambassador{game_2, "Meirav"};
    Captain captain{game_2, "Reut"};
    Contessa contessa{game_2, "Gilad"};

    // duke.income();

    CHECK_NOTHROW(duke.income());
    CHECK_NOTHROW(assassin.income());
    CHECK_NOTHROW(ambassador.income());
    CHECK_NOTHROW(captain.income());
    CHECK_NOTHROW(contessa.income());

    CHECK(duke.coins() == 1);
    CHECK(assassin.coins() == 1);
    CHECK(ambassador.coins() == 1);
    CHECK(captain.coins() == 1);
    CHECK(contessa.coins() == 1);
    CHECK_NOTHROW(duke.foreign_aid());
    CHECK(duke.coins() == 3);
    assassin.income();
    ambassador.income();
    captain.steal(duke);
    CHECK(duke.coins() == 1);
    CHECK(captain.coins() == 3);
    contessa.income();
    duke.tax();
    CHECK(duke.coins() == 4);
    assassin.foreign_aid();
    ambassador.transfer(duke, captain);
    CHECK(duke.coins() == 3);
    CHECK(captain.coins() == 4);
}
