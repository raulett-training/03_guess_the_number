//
// Created by raulett on 19.04.2023.
//
#ifndef INC_03_GUESS_THE_NUMBER_RECORDTABLE_H
#define INC_03_GUESS_THE_NUMBER_RECORDTABLE_H

#include <string>
#include <list>


struct Record{
    std::string Name;
    unsigned int attempt_num;
    static bool record_compare_name_and_count(const Record &a, const Record &b);
};

class RecordTable {
private:
    std::string record_table_filename;
    std::list<Record> record_list;
public:
    RecordTable();
    std::string get_table();
    void add_record(const Record& record);
    bool store_table();
};


#endif //INC_03_GUESS_THE_NUMBER_RECORDTABLE_H
