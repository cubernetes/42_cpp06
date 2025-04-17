#include "Serializer.hpp"
#include <iostream>
#include <stdint.h>

Serializer::~Serializer() {}
Serializer::Serializer() {}
Serializer::Serializer(const Serializer &) {}
Serializer &Serializer::operator=(const Serializer &) { return *this; }

uintptr_t Serializer::serialize(Data *ptr) { return reinterpret_cast<uintptr_t>(ptr); }

Data *Serializer::deserialize(uintptr_t raw) { return reinterpret_cast<Data *>(raw); }

void print_data(Data *data) {
    switch (data->data_type) {
    case Data::INT:
        std::cout << "INT: " << data->as_int << std::endl;
        break;
    case Data::FLOAT:
        std::cout << "FLOAT: " << data->as_float << std::endl;
        break;
    case Data::STRING:
        std::cout << "STRING: " << data->as_string << std::endl;
        break;
    default:
        std::cout << "UNKNOWN: " << data << std::endl;
        break;
    }
}
