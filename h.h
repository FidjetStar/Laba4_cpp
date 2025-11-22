#ifndef H_H
#define H_H

#include <vector>
#include <string>

void fillKeyboard(std::vector<std::vector<int>> &matrix);
void fillRandom(std::vector<std::vector<int>> &matrix);
void fill_file(std::vector<std::vector<int>> &matrix, std::string filename);
void matrix29Console(std::vector<std::vector<int>> &matrix);
void matrix29File(std::vector<std::vector<int>> &matrix);
void matrix59Console(std::vector<std::vector<int>> &matrix);
void matrix59File(std::vector<std::vector<int>> &matrix);
void clearMatrix(std::vector<std::vector<int>> &matrix);

#endif