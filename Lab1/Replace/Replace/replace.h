#pragma once

void ReplaceString(std::ifstream& inputFile, std::string& line, std::string& searchString, size_t& pos, std::string& result, std::string& replacementString, std::ofstream& outputFile);

void Replace(std::string& line, std::string& searchString, size_t& pos, std::string& result, std::string& replacementString);
