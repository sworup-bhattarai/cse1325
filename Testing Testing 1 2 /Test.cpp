#include <windows>
#include <sstream>
#include <iostream>

namespace {
    class mb_streambuf : public std::stringbuf {
        virtual ~mb_streambuf() { if (str().size() > 0) sync(); }
        virtual int sync() {
            MessageBoxA(0, str().c_str(), "", MB_OK);
            str("");
            return 0;
        }
    } mb_buf;

    struct static_initializer {
        static_initializer() { 
            std::cout.rdbuf(&mb_buf); 
        }
    } cout_buffer_switch;
}

int main()
{
    std::cout << "Hello \nworld!"; // Will show a popup
}