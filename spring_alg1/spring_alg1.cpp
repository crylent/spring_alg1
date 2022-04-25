#include <iostream>
#include "TreeMap.h"

int main()
{
    TreeMap<int, std::string>* map = new TreeMap<int, std::string>();
    std::cout << "insert(13, \"A\")\n"
        << "insert(8, \"B\")\n"
        << "insert(17, \"C\")\n"
        << "insert(1, \"D\")\n"
        << "insert(11, \"E\")\n"
        << "insert(15, \"F\")\n"
        << "insert(25, \"G\")\n"
        << "insert(6, \"H\")\n"
        << "insert(22, \"I\")\n"
        << "insert(27, \"J\")\n";
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
    std::cout << "remove(8)\n"
        << "remove(6)\n"
        << "remove(22)\n";
    map->remove(8);
    map->remove(6);
    map->remove(22);
    map->print();
}
