#include "FileReplacer.hpp"
#include <iostream>
#include <sstream>

FileReplacer::FileReplacer(const std::string& filename, const std::string& s1, const std::string& s2)
    : filename(filename), s1(s1), s2(s2) {}

bool FileReplacer::validateInputs() const {
    if (filename.empty()) {
        std::cerr << "Error: Empty filename" << std::endl;
        return false;
    }
    if (s1.empty()) {
        std::cerr << "Error: Empty search string" << std::endl;
        return false;
    }
    return true;
}

std::string FileReplacer::replaceAll(const std::string& content) const {
    std::string result;
    size_t lastPos = 0;
    size_t findPos;

    while ((findPos = content.find(s1, lastPos)) != std::string::npos) {
        result.append(content, lastPos, findPos - lastPos);
        result.append(s2);
        lastPos = findPos + s1.length();
    }
    result.append(content, lastPos, content.length() - lastPos);

    return result;
}

bool FileReplacer::replace() {
    if (!validateInputs()) {
        return false;
    }

    // Open input file
    std::ifstream inFile(filename.c_str());
    if (!inFile.is_open()) {
        std::cerr << "Error: Cannot open input file: " << filename << std::endl;
        return false;
    }

    // Read entire file content
    std::stringstream buffer;
    buffer << inFile.rdbuf();
    inFile.close();

    // Create output filename
    std::string outFilename = filename + ".replace";

    // Open output file
    std::ofstream outFile(outFilename.c_str());
    if (!outFile.is_open()) {
        std::cerr << "Error: Cannot create output file: " << outFilename << std::endl;
        return false;
    }

    // Replace content and write to output file
    std::string content = buffer.str();
    std::string replacedContent = replaceAll(content);
    outFile << replacedContent;
    outFile.close();

    return true;
}
