#include "InMemoryDB.h"

void InMemoryDB::begin_transaction() {
    queue.clear();
    inTransaction = true;
}

void InMemoryDB::put(const std::string& key, int val) {
    // if put is called when a transaction is not in progress, throw an exception
    if (!this->inTransaction) {
        throw std::exception();
    }

    queue.emplace_back(key, val);
}

// -1 represents value not found
int InMemoryDB::get(const std::string& key) {
    auto val = database.find(key);
    return val == database.end() ? -1 : val->second;
}

void InMemoryDB::commit() {
    if (!this->inTransaction) {
        throw std::exception();
    }

    for (const auto& change : queue) {
        database[change.first] = change.second;
    }
    this->inTransaction = false;
}

void InMemoryDB::rollback() {
    if (!this->inTransaction) {
        throw std::exception();
    }

    queue.clear();
    this->inTransaction = false;
}

InMemoryDB::InMemoryDB() {
    inTransaction = false;
}
