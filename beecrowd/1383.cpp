#include <iostream>
#include <vector>
#include <sstream>
#include <set>

using matrix = std::vector<std::vector<int>>;

bool validate(matrix board) {
  std::set<std::pair<int, int>> centers = {
    {1,1},
    {1,4},
    {1,7},
    {4,1},
    {4,4},
    {4,7},
    {7,1},
    {7,4},
    {7,7}
  };

  for (auto i = 0; i < 9; i++) {
    std::set<int> col, row;

    for (auto j = 0; j < 9; j++) {
      col.insert(board[j][i]);
      row.insert(board[i][j]);

      if (centers.find({i, j}) != centers.end()) {
        std::set<int> quadrant = {
          board[i][j],
          board[i-1][j-1],
          board[i-1][j],
          board[i-1][j+1],
          board[i][j+1],
          board[i+1][j+1],
          board[i+1][j],
          board[i+1][j-1],
          board[i][j-1],
        };

        if (quadrant.size() != 9) {
          return false;
        }
      }
    }
    
    if (col.size() != 9 || row.size() != 9) {
      return false;
    }
  }

  return true;
};

int main() {
  int n, field;
  std::cin >> n;
  std::cin.ignore();
  for (auto idx = 1; idx <= n; idx++) {
    matrix sudoku;
    std::string line;
    std::cout << "Instancia " << idx << std::endl;
    // Read sudoku board;
    for (auto i = 0; i < 9; i++)
    {
      getline(std::cin, line);
      std::stringstream ss(line);
      std::vector<int> sudoku_line;
      while (ss >> field)
      {
        sudoku_line.push_back(field);
      }
      sudoku.push_back(sudoku_line);
    }

    if (validate(sudoku))
    {
      std::cout << "SIM" << std::endl;
    }
    else
    {
      std::cout << "NAO" << std::endl;
    }

    std::cout << std::endl;
  } 
}