#define CATCH_CONFIG_MAIN

#include <catch2/catch_test_macros.hpp>
#include <cstdint>
#include <iostream>

#include "../src/base.h"

TEST_CASE("base cases", "[lotto winners]")
{
    std::vector<ticket> games {ticket {7, 22, 24, 31, 33, 40}};

    ticket seed {7, 22, 24, 31, 33, 40};

    std::vector<User> seedUsr {User("Mary", games)};

    std::vector<Winners*> win {};

    LottoUtil::GetWinners(seedUsr, win);

    std::string strWinner = LottoUtil::ReturnWinnerString(*win[0]);
    std::string testCase = "Mary wins Division 1, with matches 7, 22, 24, 31, 33, 40 for game 7, 22, 24, 31, 33, 40";

    REQUIRE(strWinner == testCase);
}

TEST_CASE("Generate a winning ticket", "[Lotto Ticket]")
{
    ticket winningTicket {};

    winningTicket = LottoUtil::GenerateLottoNumbers();

    for (auto num : winningTicket) 
    {
        REQUIRE(num > 0);
    }

    std::cout << LottoUtil::ReturnTicketString(winningTicket) << std::endl;
}