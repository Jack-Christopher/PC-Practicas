#include <bits/stdc++.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <set>

int contestant_problem[100][9] { };
int solved_penalty[100][2] { };

void order_contestant_board( int solved_penalty[100][2], std::set<int> participants)
{
    std::map<int, std::map<int, std::set<int> > > contestant_board;
    // iterate valid indices of solved_penalty
    for (auto &i: participants)
            for ( int j = 0; j < 2; j++ )
                contestant_board[solved_penalty[i][0]][solved_penalty[i][1]].insert(i);

    int index = 0;
    // iterate in reverse over contestant_board to print them
    // higher are first and lower are last
    for ( auto it = contestant_board.rbegin(); it != contestant_board.rend(); it++)
    {
        for ( auto &it2 : it->second)
        {
            for ( auto &it3 : it2.second)
            {
                std::cout << it3+1 << " ";
                std::cout << solved_penalty[it3][0] << " ";
                std::cout << solved_penalty[it3][1] << "\n";
            }
        }
    }
}


int main()
{
    int n;
    std::cin >> n;

    std::string in ="";
    //read '\n' left by std::cin
    std::getline(std::cin, in);
    //read empty line
    std::getline(std::cin, in);

    int contestant;
    int problem;
    int time;
    char L;
    std::set<int> participants;

    while (true)
    {
        std::getline(std::cin, in);
        if (in == "" || std::cin.eof())
        {
            order_contestant_board(solved_penalty, participants);
            memset(contestant_problem, 0, sizeof( contestant_problem));   
            memset(solved_penalty, 0, sizeof( solved_penalty));
            participants.clear();
            if (std::cin.eof())
                break;
            else
                std::cout << "\n";
        }
        else
        {
            // all this is an input
            std::istringstream input(in);
            input = std::istringstream(in);    
            input >> contestant >> problem >> time >> L;
            participants.insert(contestant-1);

            if (contestant_problem[contestant-1][problem-1] != -1)
            {
                if (L == 'C' )
                {
                    contestant_problem[contestant-1][problem-1] += time;
                    solved_penalty[contestant-1][0]++;
                    solved_penalty[contestant-1][1] += contestant_problem[contestant-1][problem-1];
                    contestant_problem[contestant-1][problem-1] = -1;
                }
                else if ( L == 'I')
                    contestant_problem[contestant-1][problem-1] += 20;
            }
        }
    }

    return 0;
}