#include <iostream>
#include <string>

#include "base.h"

int main(int, char**){
    ticket winningTicket {};

    std::vector<ticket> games1 {
        ticket {7,9,13,24,33,40},
        ticket {16, 19, 22, 29, 31, 39},
        ticket {1, 7, 18, 22, 30, 36}
    };
    std::vector<ticket> games2 {
        ticket { 2, 22, 13, 24, 32, 39},
        ticket { 7, 22, 24, 31, 33, 40},
        ticket {3, 7, 18, 21, 37, 38}
    };

    std::vector<User> seedUsr {
        User("Mary", games2), 
        User("John", games1)
    };

    std::vector<Winners*> won {};
    
    LottoUtil::GetWinners(seedUsr, won, ticket {7, 22, 24, 31, 33, 40});

    LottoUtil::PrintWinners(won, ticket {7, 22, 24, 31, 33, 40});
}

