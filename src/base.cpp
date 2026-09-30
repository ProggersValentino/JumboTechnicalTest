#include <iostream>
#include <random>
#include <format>
#include "base.h"



ticket LottoUtil::GenerateLottoNumbers()
{
    ticket winningTicket {};

    std::random_device rd;  // a seed source for the random number engine
    std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(1, 40);

    //generate winning ticket
    for (int i = 0; i < winningTicket.size(); i++) 
    {
        winningTicket[i] = distrib(gen);
    }

    return winningTicket;
}

void LottoUtil::GetWinners(std::vector<User>& users, std::vector<Winners*>& ticketWinners, ticket ticketSeed)
{
    ticket winningTicket {};

    //we only generate the a winning ticket if we haven't been supplied a seed
    if(ticketSeed[0] == 0)
    {
        //generate winning ticket;
        ticketSeed = GenerateLottoNumbers();
    }
    

    for (int k = 0; k < users.size(); k++) 
    {
        //compare each number to winning ticket
        for (int i = 0; i < users[k].games.size(); i++) 
        {
            std::vector<int> matches {};
            for (int j = 0; j < users[k].games[i].size(); j++) 
            {
                //match found
                if(users[k].games[i][j] == ticketSeed[j])
                {
                    matches.push_back(users[k].games[i][j]);
                }
            }
            
            //find the division
            Division div = LottoUtil::FindDivisionType(matches.size());
            if(div == Division::NONE)
            {
                continue;
            }

            Winners* winer = new Winners(&users[k], i, matches, div);

            ticketWinners.push_back(winer);

        }
    }

}

std::string LottoUtil::ReturnDivisionString(Division div)
{
    switch (div) 
    {
        case Division::Div1:
            return "Division 1";
        case Division::Div2:
            return "Division 2";
        case Division::Div3:
            return "Division 3";
        case Division::Div4:
            return "Division 4";
        default:
            return "No match";
    }
}

std::string LottoUtil::ReturnTicketString(ticket ticketINP)
{
     std::string f = std::format("ticket: {}, {}, {}, {}, {}, {}\n", 
        ticketINP[0], ticketINP[1], ticketINP[2], ticketINP[3], ticketINP[4], ticketINP[5]);

    return f;
}

Division LottoUtil::FindDivisionType(int totalMatches)
{
    if(totalMatches >= 6)
    {
        return Division::Div1;
    }
    else if (totalMatches == 5)
    {
        return Division::Div2;
    }
    else if (totalMatches == 4)
    {
        return Division::Div3;
    }
    else if(totalMatches == 3)
    {
        return Division::Div4;
    }
    else
    {
        return Division::NONE;
    }
}

std::string LottoUtil::ReturnWinnerString(Winners winnerINP)
{
    std::string divConv = LottoUtil::ReturnDivisionString(winnerINP.divAllocated);
    std::string gameConv = LottoUtil::ReturnArrayElemString<int, 6>(winnerINP.userData->games[winnerINP.gameRef]);
    std::string matchesCov = LottoUtil::ReturnVectorElemString<int>(winnerINP.matches);

    std::string f = std::format("{} wins {}, with matches {} for game {}\n", 
        winnerINP.userData->name, 
        divConv,
        matchesCov, 
        gameConv
    );

    return f;
}

void LottoUtil::PrintWinners(std::vector<Winners*> winners, ticket winningTicket)
{
    std::string winningTicketStr = LottoUtil::ReturnTicketString(winningTicket);

    if(winners.size() == 0)
    {
        std::cout << "No winners for " << winningTicketStr << std::endl;
    }

    for(Winners *winner : winners)
    {
        std::cout << LottoUtil::ReturnWinnerString(*winner) << std::endl;
    }

}