#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>
#include <sstream>

int main(int argc, char *argv[])
{
    struct stat buffer;

    if (argc != 4 || !std::string(argv[2]).compare("") || !std::string(argv[3]).compare("") || stat(argv[1], &buffer))
    {
        std::cout << "Invalid parameters." << std::endl;
        return (0);
    }

    std::string s1 = std::string(argv[2]);
    std::string s2 = std::string(argv[3]);
    std::ifstream infile((const char *)argv[1]);
    if (!infile.good())
    {
        std::cout << "File not readable" << std::endl;
        return (0);
    }
    std::stringstream buff;
    std::string filetext;
    std::string outfiletext;
    buff << infile.rdbuf();
    filetext = buff.str();
    if (filetext.find(s1) == std::string::npos)
        outfiletext = filetext;
    while (1)
    {
        if (filetext.find(s1) == std::string::npos)
            break ;
        outfiletext += filetext.substr(0, filetext.find(s1));
        outfiletext += s2;
        filetext = filetext.substr(filetext.find(s1) + s1.length(), std::string::npos);
        // filetext.replace(filetext.find(s1), s1.length(), s2);
    }
    infile.close();
    std::ofstream outfile(std::string(argv[1]) + ".replace");
    outfile << outfiletext;
}