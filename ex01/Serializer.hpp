#pragma once
#include <stdint.h>

struct Data {
    enum { INT, FLOAT, STRING } data_type;
    union {
        int as_int;
        float as_float;
        char *as_string;
    };
};

struct Serializer {
    ~Serializer();
    Serializer();
    Serializer(const Serializer &);
    Serializer &operator=(const Serializer &);
    static uintptr_t serialize(Data *ptr);
    static Data *deserialize(uintptr_t raw);
};

void print_data(Data *data);
