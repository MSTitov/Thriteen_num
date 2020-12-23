#define _UNICODE
#include <iostream>
#include <stdlib.h>
#include <cassert>
#include <fstream>
#include <string>


namespace tools
{
    namespace detail_match_pattern
    {
        template<class s>
        bool aoti(const s* ch)
        {
            assert(ch);

            int c1 = 0, c2 = 0, counter = 0;

            while (*ch)
            {
                if (isalpha(*ch))
                {
                    std::string sym(1, *ch);
                    if (counter <= 5)
                        c1 += strtol(sym.c_str(), NULL, 16);

                    else if (counter >= 7)
                        c2 += strtol(sym.c_str(), NULL, 16);
                }
                else
                {
                    std::string sym(1, *ch);
                    if (counter <= 5)
                        c1 += strtol(sym.c_str(), NULL, 16);
                    else if (counter >= 7)
                        c2 += strtol(sym.c_str(), NULL, 16);
                }

                ++counter;
                ++ch;
            }

            return c1 == c2;
        }
    }

    template<class s>
    bool match_aoti(const s& num)
    {
        return detail_match_pattern::aoti(&num[0]);
    }
}

int main(int argc, char* argv[])
{
    int counter = 0;
    char* p = new char[1024];
    
    std::ifstream fis("num.txt", std::ios_base::in | std::ios_base::app);

    while (fis.getline(p, 1024))
        if (tools::match_aoti(p))
            ++counter;
    
    
    std::cout << counter << " beautiful number[s]\n";

    delete[] p;
    return 0;
}