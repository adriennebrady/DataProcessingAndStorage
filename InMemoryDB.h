#ifndef DATAPROCESSINGANDSTORAGE_INMEMORYDB_H
#define DATAPROCESSINGANDSTORAGE_INMEMORYDB_H


#include <string>
#include <unordered_map>
#include <vector>

class InMemoryDB {
private:
    bool inTransaction;
    std::unordered_map<std::string, int> database;
    std::vector<std::pair<std::string, int>> queue;

public:
    InMemoryDB();
    void begin_transaction();
    void put(const std::string& key, int val);
    int get(const std::string& key);
    void commit();
    void rollback();
};


#endif //DATAPROCESSINGANDSTORAGE_INMEMORYDB_H
