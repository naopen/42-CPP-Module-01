#ifndef FILEREPLACER_HPP
#define FILEREPLACER_HPP

#include <string>
#include <fstream>

class FileReplacer {
private:
    std::string filename;
    std::string s1;
    std::string s2;

    // Private helper methods
    bool validateInputs() const;
    std::string replaceAll(const std::string& content) const;

public:
    FileReplacer(const std::string& filename, const std::string& s1, const std::string& s2);
    bool replace();
};

#endif
