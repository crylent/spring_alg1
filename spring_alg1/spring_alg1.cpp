#include <iostream>
#include "TreeMap.h"

int main()
{
    TreeMap<int, std::string>* map = new TreeMap<int, std::string>();
    map->insert(13, "A");
    map->insert(8, "B");
    map->insert(17, "C");
    map->insert(1, "D");
    map->insert(11, "E");
    map->insert(15, "F");
    map->insert(25, "G");
    map->insert(6, "H");
    map->insert(22, "I");
    map->insert(27, "J");
    map->print();
}
