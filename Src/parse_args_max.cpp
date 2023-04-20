//
// Created by raulett on 21.04.2023.
//
#include <string>
#include <algorithm>
#include "parse_args_max.h"

uint32_t parse_args_max(int argc, char** argv, uint32_t def_num){
    if (argc > 0) {
        for (int i=0; i<argc; i++) {
            std::string arg_str = argv[i];
            if (arg_str == "-table"){
                return 0;
            }
            if ((arg_str == "-max")&&(i+1 < argc)){
                std::string arg_str = argv[i+1];
                if (std::all_of(arg_str.begin(), arg_str.end(), ::isdigit)){
                    return std::stoi(arg_str);
                }
            }
        }
    }
    return def_num;
}