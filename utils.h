// Utils.h
#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <random>
#include <sstream>
#include <iomanip>
using namespace std;

inline string generate_guid() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 15);
    uniform_int_distribution<> dis2(8, 11);

    stringstream ss;
    ss << hex;

    for (int i = 0; i < 8; i++) ss << dis(gen);
    ss << "-";
    for (int i = 0; i < 4; i++) ss << dis(gen);
    ss << "-4"; // version 4 UUID
    for (int i = 0; i < 3; i++) ss << dis(gen);
    ss << "-";
    ss << dis2(gen); // variant
    for (int i = 0; i < 3; i++) ss << dis(gen);
    ss << "-";
    for (int i = 0; i < 12; i++) ss << dis(gen);

    return ss.str();
}

#endif
