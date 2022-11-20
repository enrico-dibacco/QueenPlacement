#include <stdio.h>
#include <iostream>
#include <checkerboard.hpp>

int main()
{
    CheckerBoard *busyBoard = new CheckerBoard();
    CheckerBoard *queenBoard = new CheckerBoard();
    std::cout << R"(
        
     ██████  ██    ██ ███████ ███████ ███    ██      ██████  █████  ██       ██████ ██    ██ ██       █████  ████████  ██████  ██████  
    ██    ██ ██    ██ ██      ██      ████   ██     ██      ██   ██ ██      ██      ██    ██ ██      ██   ██    ██    ██    ██ ██   ██ 
    ██    ██ ██    ██ █████   █████   ██ ██  ██     ██      ███████ ██      ██      ██    ██ ██      ███████    ██    ██    ██ ██████  
    ██ ▄▄ ██ ██    ██ ██      ██      ██  ██ ██     ██      ██   ██ ██      ██      ██    ██ ██      ██   ██    ██    ██    ██ ██   ██ 
     ██████   ██████  ███████ ███████ ██   ████      ██████ ██   ██ ███████  ██████  ██████  ███████ ██   ██    ██     ██████  ██   ██ 
        ▀▀                                                                                                                             
                                                                                                                                   
        
    )" << '\n';

    printf("Do you want to initiate the program?\n");
    std::cin.get();
    int validCombinations = 0;
    // qr0 is row of queen on column 0
    // qr1 is row of queen on column 1
    for (int qr0 = 0; qr0 < 8; qr0++)
    {

        if (busyBoard->IsPlaceAvailable(qr0, 0) == 0) // If queen cannot be placed
            continue;                      //  increase qr0 and skip next instructions
        queenBoard->setCell(qr0, 0, CheckerBoard::CellState::QUEEN);
        busyBoard->CalculateDangerZone(queenBoard);

        for (int qr1 = 0; qr1 < 8; qr1++)
        {
            if ((busyBoard->IsPlaceAvailable(qr1, 1) == 0))
                continue;
            queenBoard->setCell(qr1, 1, CheckerBoard::CellState::QUEEN);
            busyBoard->CalculateDangerZone(queenBoard);
            for (int qr2 = 0; qr2 < 8; qr2++)
            {
                if (busyBoard->IsPlaceAvailable(qr2, 2) == 0)
                    continue;
                queenBoard->setCell(qr2, 2, CheckerBoard::CellState::QUEEN);
                busyBoard->CalculateDangerZone(queenBoard);

                for (int qr3 = 0; qr3 < 8; qr3++)
                {
                    if (busyBoard->IsPlaceAvailable(qr3, 3) == 0)
                        continue;
                    queenBoard->setCell(qr3, 3, CheckerBoard::CellState::QUEEN);
                    busyBoard->CalculateDangerZone(queenBoard);

                    for (int qr4 = 0; qr4 < 8; qr4++)
                    {
                        if (busyBoard->IsPlaceAvailable(qr4, 4) == 0)
                            continue;
                        queenBoard->setCell(qr4, 4, CheckerBoard::CellState::QUEEN);
                        busyBoard->CalculateDangerZone(queenBoard);

                        for (int qr5 = 0; qr5 < 8; qr5++)
                        {
                            // printf("Regina sesta\n");
                            if (busyBoard->IsPlaceAvailable(qr5, 5) == 0)
                                continue;
                            queenBoard->setCell(qr5, 5, CheckerBoard::CellState::QUEEN);
                            busyBoard->CalculateDangerZone(queenBoard);

                            for (int qr6 = 0; qr6 < 8; qr6++)
                            {
                                // printf("Regina settima\n");

                                if (busyBoard->IsPlaceAvailable(qr6, 6) == 0)
                                    continue;
                                queenBoard->setCell(qr6, 6, CheckerBoard::CellState::QUEEN);
                                busyBoard->CalculateDangerZone(queenBoard);

                                for (int qr7 = 0; qr7 < 8; qr7++)
                                {
                                    // printf("Reginaottava\n");
                                    if (busyBoard->IsPlaceAvailable(qr7, 7) == 0)
                                        continue;
                                    queenBoard->setCell(qr7, 7, CheckerBoard::CellState::QUEEN);
                                    busyBoard->CalculateDangerZone(queenBoard,1);
                                    printf("%d %d %d %d %d %d %d %d\n", qr0, qr1, qr2, qr3, qr4,
                                           qr5, qr6, qr7);
                                    printf("\n\n");
                                    validCombinations++;
                                    queenBoard->ClearColumn(7);
                                    busyBoard->CalculateDangerZone(queenBoard);
                                }

                                queenBoard->ClearColumn(6);
                                busyBoard->CalculateDangerZone(queenBoard);
                            }

                            queenBoard->ClearColumn(5);
                            busyBoard->CalculateDangerZone(queenBoard);
                        }

                        queenBoard->ClearColumn(4);
                        busyBoard->CalculateDangerZone(queenBoard);
                    }

                    queenBoard->ClearColumn(3);
                    busyBoard->CalculateDangerZone(queenBoard);
                }

                queenBoard->ClearColumn(2);
                busyBoard->CalculateDangerZone(queenBoard);
            }

            queenBoard->ClearColumn(1);
            busyBoard->CalculateDangerZone(queenBoard);
        }

        queenBoard->ClearColumn(0);
        busyBoard->CalculateDangerZone(queenBoard);
    }
    printf("Valid combinations: %d.\n", validCombinations);
}
