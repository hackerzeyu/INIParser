#include <iostream>
#include "utility/INIParser.h"
using namespace zeyu::utility;

int main()
{
    INIParser parser("../settings.ini");
    parser.show();
    std::cout<<parser.get("server","ip")<<","<<parser.get("server","port")<<std::endl;
    parser.set("server","ip","192.168.1.1");
    std::cout<<(string)parser.get("server","ip")<<std::endl;
    parser.update();
    return 0;
}
