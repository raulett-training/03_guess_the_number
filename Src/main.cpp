#include <iostream>
#include <ctime>
#include <format>
#include <algorithm>
#include "RecordTable.h"
#include "parse_args_max.h"


int main(int argc, char** argv) {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    uint32_t max_number = parse_args_max(argc, argv, 100);
    if (max_number == 0){
        RecordTable record_table = RecordTable();
        std::cout << record_table.get_table() << std::endl;
        return 0;
    }
    std::cout << std::format("'Guess the number' the game. Number from 0 to {} was thought.", max_number) << std::endl;
    std::cout << "What is your name?:" << std::endl;
    std::string name_str;
    std::getline(std::cin, name_str);

    std::srand(std::time(nullptr));
    const uint8_t random_var = std::rand() % max_number+1;
    int guessed_value = -1;
    uint8_t try_count = 0;
    while (random_var != guessed_value){
        try_count++;
        std::cout << "Attempt " << std::to_string(try_count) << ". Enter your guess:" << std::endl;
        std::cin >> guessed_value;
        if (guessed_value < random_var){
            std::cout << guessed_value << " less than thought value, try again!" << std::endl;
        } else if (guessed_value > random_var) {
            std::cout << guessed_value << " greater than thought value, try again!" << std::endl;
        } else {
            std::cout << "you guessed number " << unsigned(random_var)
            << " right on the " << unsigned(try_count) <<" attempt." << std::endl;
        }
    }
    Record current_record = {name_str, try_count};
    RecordTable record_table = RecordTable();
    record_table.add_record(current_record);
    std::cout << "Record table! 10 best." << std::endl;
    std::cout << record_table.get_table() << std::endl;
    record_table.store_table();
    return 0;
}
