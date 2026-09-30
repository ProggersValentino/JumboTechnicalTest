#pragma once

#include <array>
#include <string>
#include <vector>
#include <format>

#define ticket std::array<int, 6>

enum class Division
{
    NONE,
    Div1,
    Div2,
    Div3,
    Div4,
};

class User
{
public:
    std::string name;

    std::vector<ticket> games;
public:
    User(std::string nameINP, std::vector<ticket> gamesINP) : name(nameINP), games(gamesINP)
    {

    }
};

struct Winners
{
public:
    User* userData;
    int gameRef;
    std::vector<int> matches;
    Division divAllocated;
    
    Winners(User* userINP, int gameINP, std::vector<int> matchesINP, Division divINP): 
        userData(userINP), gameRef(gameINP), divAllocated(divINP), matches(matchesINP) {}
};


namespace LottoUtil 
{
    //generate a random number of numbers from 1-40
    ticket GenerateLottoNumbers();

    void GetWinners(std::vector<User>& users, std::vector<Winners*>& winners, ticket ticketSeed = {});

    std::string ReturnDivisionString(Division div);

    std::string ReturnTicketString(ticket ticketINP);

    Division FindDivisionType(int totalMatches);

    std::string ReturnWinnerString(Winners winnerINP);

    void PrintWinners(std::vector<Winners*> winners, ticket winningTicket);

    template<typename T, int size>
    std::string ReturnArrayElemString(std::array<T, size> arrayToReturn)
    {
        std::string result {};
        for (int i = 0; i < arrayToReturn.size(); i++) 
        {
            std::string f;
            if(i == arrayToReturn.size() - 1)
            {
                f = std::format("{}", arrayToReturn[i]);
                result += f;
                continue;
            }
            f = std::format("{}, ", arrayToReturn[i]);
            result += f;
        }
        return result;
    };

    template<typename T>
    std::string ReturnVectorElemString(std::vector<T> vectorToReturn)
    {
         std::string result {};
        for (int i = 0; i < vectorToReturn.size(); i++) 
        {
            std::string f;
            if(i == vectorToReturn.size() - 1)
            {
                f = std::format("{}", vectorToReturn[i]); 
                result += f;
                continue;   
            }
            f = std::format("{}, ", vectorToReturn[i]);
            
            result += f;
        }

        return result;
    };
}
