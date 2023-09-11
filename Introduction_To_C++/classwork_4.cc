/*
1. Create an enumerated type to keep
track of the pieces on a chessboard
(ROOK, KNIGHT, etc. but EMPTY
is also an option). Then declare a 2-
dimensional array that represents the
board itself (the type is the name of
your enum). Fill the board.
2. Write a program that asks the user for
3 strings and creates a 2-dimensional
array, where each row contains the
given strings once. Then create a 2-
dimensional array, where each
column contains the given strings
once.
*/

#include <cstring>
#include <vector>
#include <iostream>

using namespace std;

#define pieces_row ROOK, KNIGHT, BISHOP, KING, QUEEN, BISHOP, KNIGHT, ROOK
#define pawn_row PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN
#define nl cout<<endl

enum ChessPiece
{ EMPTY, PAWN, ROOK, KNIGHT, BISHOP, KING, QUEEN };

int main(void)
{
    ChessPiece board[8][8] = {{pieces_row}, {pawn_row}, {},         {},
                              {},           {},         {pawn_row}, {pieces_row}};
    for (auto const& row : board)
    {
        for (auto const& piece : row) cout << piece << " ";
        nl;
    }
    nl;
    nl;
    string str_horizontal[3] = {""};
    cout << "Enter String #1:\n";
    getline(cin, str_horizontal[0]);
    cout << "Enter String #2:\n";
    getline(cin, str_horizontal[1]);
    cout << "Enter String #3:\n";
    getline(cin, str_horizontal[2]);
    cout << "\n2-dimensional array, where each row contains the given strings once:\n\n";
    for(string const& s : str_horizontal)
    {
        for(char const& c : s) cout << c << " ";
        nl;
    }
    nl;
    int maxl = 0;
    for(string const& r : str_horizontal) maxl = max(maxl, static_cast< int >(r.length()));
    nl;
    vector<string> str_vertical(maxl, string(3, ' '));
    for (int i = 0; i < maxl; i++) for (int j = 0; j < 3; j++)
        str_vertical[i][j] = (i < str_horizontal[j].length()) ? str_horizontal[j][i] : ' ';
    cout << "2-dimensional array, where each column contains the given strings once:\n\n";
    for(string const& s: str_vertical) {
        for(char const& c: s) cout << c << " ";
        nl;
    }
}