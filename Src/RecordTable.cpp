//
// Created by raulett on 19.04.2023.
//

#include "RecordTable.h"
#include <fstream>
#include <list>
#include <sstream>
#include <iostream>



bool Record::record_compare(const Record &a, const Record &b){
    return a.attempt_num < b.attempt_num;
}

RecordTable::RecordTable() : record_table_filename("record_table.txt") {
    std::ifstream record_file(record_table_filename);
    if (!record_file.is_open()){
        return;
    } else{
        std::string line;
        int record_num;
        while (std::getline(record_file, line)){
            Record record;
            std::istringstream iss(line);
            if (!(iss >> record_num >> record.Name >> record.attempt_num)){
                continue;
            } else{
                record_list.push_back(record);
            }
        }
    }
}

std::string RecordTable::get_table(){
    std::string record_table_str = "==================\nTable of records!\n==================\n";
    uint8_t counter = 1;
    for (auto record_iter = record_list.begin();
         record_iter != record_list.end();
         record_iter++){
        record_table_str += std::to_string(counter) + '\t';
        record_table_str += record_iter->Name + '\t';
        record_table_str += std::to_string(record_iter->attempt_num) + '\n';
        counter++;
        if (counter > 10) break;
    }
    return record_table_str;
}

void RecordTable::add_record(const Record& record) {

    record_list.push_back(record);
    record_list.sort(Record::record_compare);
}

bool RecordTable::store_table() {
    std::ofstream record_file(record_table_filename);
    if (!record_file.is_open()){
        return false;
    } else {
        record_file << get_table();
        record_file.close();
    }
    return true;
}


