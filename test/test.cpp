#include "catch_amalgamated.hpp"
#include "../include/map.hpp"

////////////////////////////////////////////////////////////////////////////
/////////////////////////////// Map tests //////////////////////////////////
////////////////////////////////////////////////////////////////////////////

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
        // REQUIRE((*it).second == "B");
    }
}


////////////////////////////////////////////////////////////////////////////
/////////////////////////////// BST tests //////////////////////////////////
////////////////////////////////////////////////////////////////////////////

TEST_CASE("Test BinarySearchTree::insert") {
    SECTION("It can insert a new element") {
        BinarySearchTree<int> bst;

        const size_t expected_size = 4;
        int expected_values[expected_size] = {5, 10, 20, 30};
        for (size_t i = 0; i < expected_size; i++) {
            bst.insert(expected_values[i]);
        }

        REQUIRE(bst.size() == expected_size);
        BinarySearchTree<int>::iterator it = bst.cbegin();
        for (size_t i = 0; i < expected_size; i++) {
            REQUIRE(*it == expected_values[i]);
        }
    }
}

TEST_CASE("Test BinarySearchTree::erase()") {
    SECTION("It can erase any element from the tree") {
        BinarySearchTree<int> bst;

        const size_t size = 4;
        int values[size] = {5, 10, 20, 30};
        for (size_t i = 0; i < size; i++) {
            bst.insert(values[i]);
        }

        bst.erase(bst.cbegin());
        bst.erase(--bst.cend());

        size_t expected_size = 2;
        int expected_values[size] = {10, 20};

        REQUIRE(bst.size() == expected_size);
        BinarySearchTree<int>::iterator it = bst.cbegin();
        for (size_t i = 0; i < expected_size; i++) {
            REQUIRE(*it == expected_values[i]);
        }
    }
}

TEST_CASE("Test BinarySearchTree::clear()") {
    SECTION("It can clear whole binary search tree") {
        BinarySearchTree<int> bst;

        const size_t size = 4;
        int values[size] = {5, 10, 20, 30};
        for (size_t i = 0; i < size; i++) {
            bst.insert(values[i]);
        }
        
        REQUIRE(bst.size() == size);

        bst.clear();
    
        REQUIRE(bst.empty() == true);
        REQUIRE(bst.size() == NULL);
    }
}
