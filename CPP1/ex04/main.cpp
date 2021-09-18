#include <iostream>
#include <fstream>
#include <string>

/*Make a program called replace that takes a filename and two strings, let’s call them
s1 and s2, that are NOT empty.
It will open the file, and write its contents to FILENAME.replace, after replacing
every occurrence of s1 with s2.
All the member functions of the class std::string are allowed, except replace. Use
them wisely!
Of course, you will handle errors as best you can. Do not use the C file manipulation
functions, because that would be cheating, and cheating’s bad, m’kay?
You will turn in some test files to show your program works.*/

int main(int argc, char *argv[])
{
    std::string temp;
    std::string filename(argv[1]);

    if (argc != 4)
    {
        std::cout << "Invalid parameters" << std::endl;
        return (0);
    }
    std::ifstream ifs("to_read");
    std::ofstream ofs(filename.append(".replace"));
}