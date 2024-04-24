#include <iostream>
#include "InMemoryDB.h"

int main() {
    InMemoryDB inmemoryDB;

    std::cout << "Result from get(\"A\"): " << inmemoryDB.get("A") << std::endl;

    try {
        inmemoryDB.put("A", 5);
    }
    catch (const std::exception& e) {
        std::cout << "Result from put(\"A\", 5): " << e.what() << std::endl;
    }

    inmemoryDB.begin_transaction();
    std::cout << "Begin transaction." << std::endl;

    inmemoryDB.put("A", 5);
    std::cout << "Putting (\"A\", 5)" << std::endl;

    // not commited yet so still null
    std::cout << "Result from get(\"A\"): " << inmemoryDB.get("A") << std::endl;

    inmemoryDB.put("A", 6);
    std::cout << "Putting (\"A\", 6)" << std::endl;

    inmemoryDB.commit();
    std::cout << "Commiting." << std::endl;

    std::cout << "Result from get(\"A\"): " << inmemoryDB.get("A") << std::endl;

    try {
        std::cout << "Commiting." << std::endl;
        inmemoryDB.commit();
    }
    catch (const std::exception& e) {
        std::cout << "Result from commiting: " << e.what() << " because no transaction in progress." << std::endl;
    }

    try {
        std::cout << "Rollback." << std::endl;
        inmemoryDB.rollback();
    }
    catch (const std::exception& e) {
        std::cout << "Result from rollback: " << e.what() << " because no transaction in progress." << std::endl;
    }

    std::cout << "Result from get(\"B\"): " << inmemoryDB.get("B") << std::endl;

    inmemoryDB.begin_transaction();
    std::cout << "Begin transaction." << std::endl;

    inmemoryDB.put("B", 10);
    std::cout << "Putting (\"B\", 10)" << std::endl;

    std::cout << "Rollback." << std::endl;
    inmemoryDB.rollback();

    std::cout << "Result from get(\"B\"): " << inmemoryDB.get("B") << std::endl;

    return 0;
}
