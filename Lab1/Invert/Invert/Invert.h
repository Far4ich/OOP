#pragma once

void FindNorm(int n, double** arr0, double& colNorm, double& rowNorm);

std::vector<std::vector<double>> FindInvertedMatrix(std::vector<std::vector<double>> arr0, const int& dimension, std::vector<std::vector<double>> arr, std::vector<std::vector<double>> E2, std::ofstream& outputFile);

