#include "catch_amalgamated.hpp"
#include "../include/map.hpp"

TEST_CASE("Test Map::operator[] and Map::insert") {
    SECTION("It can insert a new element") {
        Map<std::string, int> m = {{"A", 65}, {"B", 66}, {"C", 67}};

        size_t expected_size = 3;

        REQUIRE(m.size() == expected_size);
        REQUIRE(m["A"] == 65);
        REQUIRE(m["B"] == 66);
        REQUIRE(m["C"] == 67);

        // using operator[] with non-existent key always performs an insert
        int non_existent_value = m["D"];
        expected_size++;
        
        REQUIRE(m.size() == expected_size);
        REQUIRE(m["D"] == NULL);

        m.insert(std::pair<std::string, int>("E", 69));
        expected_size++;

        REQUIRE(m.size() == expected_size);
        REQUIRE(m["E"] == 69);
    }
}

TEST_CASE("Test Map::erase()") {
    SECTION("It can erase an existent key") {
        Map<std::string, int> m = {{"A", 65}, {"B", 66}, {"C", 67}};

        size_t expected_size = 3;
        REQUIRE(m.size() == expected_size);

        REQUIRE(m.erase("B") == 1);
        REQUIRE(m.size() == --expected_size);
        REQUIRE(m.count("B") == NULL);
    }

    SECTION("It cannot erase non-existent key") {
        Map<std::string, int> m = {{"A", 65}, {"B", 66}, {"C", 67}};

        size_t expected_size = 3;
        REQUIRE(m.size() == expected_size);

        REQUIRE(m.erase("D") == NULL);
        REQUIRE(m.size() == expected_size);
    }
}

TEST_CASE("Test Map::clear()") {
    SECTION("It can clear whole map") {
        Map<std::string, int> m = {{"A", 65}, {"B", 66}, {"C", 67}};

        m.clear();

        REQUIRE(m.size() == NULL);
        REQUIRE(m.empty() == true);
    }
}

TEST_CASE("Test Map::count, Map::find") {
    SECTION("It can return count of the same keys using Map::count") {
        Map<std::string, int> m = {{"A", 65}, {"B", 66}, {"C", 67}};

        REQUIRE(m.count("B") == 1);
    }

    SECTION("It can find the key using Map::find") {
        Map<std::string, int> m = {{"A", 65}, {"B", 66}, {"C", 67}};

        Map<std::string, int>::iterator it = m.find("B");
        // REQUIRE(*it == "B");
    }
}
