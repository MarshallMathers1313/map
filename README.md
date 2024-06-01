# map

Implementation of std::map

## Example

```cpp
#include <string>
#include <iostream>

#include "map.hpp"

int main() {
    // Create a map of three (string, int) pairs
    map<std::string, int> m = {{"CPU", 10}, {"GPU", 15}, {"RAM", 20}};
    std::cout << "1) Initial map: " << m << std::endl;

    m["CPU"] = 25; // Update an existing value
    m["SSD"] = 30; // Insert a new value
    std::cout << "2) Updated map:" << m << std::endl;

    // Using operator[] with non-existent key always performs an insert
    std::cout << "3) m[\"UPS\"]: " << m["UPS"] << std::endl;
    std::cout << "4) Updated map: " << m << std::endl;

    m.erase("GPU");
    std::cout << "5) After erase: " << m << std::endl;
    std::cout << "6) m.size(): " << m.size() << std::endl;

    m.clear();
    std::cout << std::boolalpha << "7) Map is empty: " << m.empty() << std::endl;

    return 0; 
}

```
