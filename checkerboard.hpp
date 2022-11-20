#include <stdio.h>
#include <iostream>
class CheckerBoard
{
public:
    enum CellState
    {
        EMPTY = 0,
        QUEEN = 1,
        BUSY = 2,

    };

private:
    CellState checkerboard[8][8];

public:
    CheckerBoard(/* args */);

    ~CheckerBoard();
    void PrintBoard();
    void ClearColumn(int c);

    void setCell(int r, int c, CellState val);
    CellState getCell(int r, int c);
    void ClearCheckBoard(CellState board[8][8]);
    int CalculateDangerZoneForQueen(int rq, int cq);
    int CalculateDangerZone(CheckerBoard* queenBoard, int print = 0);
    int IsPlaceAvailable(int r, int c);
};

CheckerBoard::CheckerBoard(/* args */)
{
    for (int r = 0; r < 8; r++)
    {
        for (int c = 0; c < 8; c++)
            checkerboard[r][c] = CellState::EMPTY;
    }
}

CheckerBoard::~CheckerBoard()
{
}

void CheckerBoard::PrintBoard()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
            printf("%c ", (checkerboard[i][j] == QUEEN) ? 'O' : (checkerboard[i][j] == BUSY) ? '+'
                                                                                             : '.');
        printf("\n");
    }
    printf("\n");
}
void CheckerBoard::ClearColumn(int c)
{
    for (int i = 0; i < 8; i++)
    {
        checkerboard[i][c] = EMPTY;
    }
}
void CheckerBoard::setCell(int r, int c, CellState val)
{
    if ((r < 0) || (r > 7) || (c < 0) || (c > 7))
        printf("Error setting square %d %d\n", r, c);
    checkerboard[r][c] = val;
}

CheckerBoard::CellState CheckerBoard::getCell(int r, int c)
{
    return checkerboard[r][c];
}

void CheckerBoard::ClearCheckBoard(CellState board[8][8])
{
    for (int r = 0; r < 8; r++)
    {
        for (int c = 0; c < 8; c++)
            board[r][c] = EMPTY;
    }
}
int CheckerBoard::CalculateDangerZoneForQueen(int rq, int cq)
{

    for (int k = 0; k < 8; k++)
    {
        setCell(rq, k, BUSY);
    }
    for (int f = 0; f < 8; f++)
    {
        setCell(f, cq, BUSY);
    }

    int kmin = -std::min(rq, cq);
    int kmax = std::min(7 - rq, 7 - cq);
    for (int k = kmin; k <= kmax; k++)
    {
        setCell(rq + k, cq + k, BUSY);
    }
    int tmin = -std::min(7 - rq, cq);
    int tmax = std::min(7 - cq, rq);
    for (int t = tmin; t <= tmax; t++)
    {
        setCell(rq - t, cq + t, BUSY);
    }

    setCell(rq, cq, QUEEN);

    return 0;
}
int CheckerBoard::CalculateDangerZone(CheckerBoard* queenBoard,int print)
{

    ClearCheckBoard(checkerboard);

    for (int r = 0; r < 8; r++)
    {
        for (int c = 0; c < 8; c++)
        {
            if (queenBoard->getCell(r,c) == QUEEN)
                CalculateDangerZoneForQueen(r, c);
        }
    }

    if (print == 1)
        PrintBoard();

    return 1;
}
int CheckerBoard::IsPlaceAvailable(int r, int c)
{

    if (checkerboard[r][c] == CellState::EMPTY)
        return 1; // true, it is available
    else
        return 0; // false, it's not available
}
