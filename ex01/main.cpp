#include "Serializer.hpp"
#include <iostream>

int main() {
    Data data1;
    data1.data_type = Data::INT;
    data1.as_int = 42;

    Data data2;
    data2.data_type = Data::FLOAT;
    data2.as_float = 3.1415192f;

    Data data3;
    data3.data_type = Data::STRING;
    data3.as_string = const_cast<char *>("The answer");

    std::cout << "Testing data1" << std::endl;
    std::cout << "Data: ";
    print_data(&data1);
    std::cout << "Serialized data: " << Serializer::serialize(&data1) << std::endl;
    std::cout << "Deserialized data: ";
    print_data(Serializer::deserialize(Serializer::serialize(&data1)));
    std::cout << "Deserialize(Serialize(data))==data: " << (&data1 == Serializer::deserialize(Serializer::serialize(&data1)) ? "yes" : "no") << std::endl;

    std::cout << "\nTesting data2" << std::endl;
    std::cout << "Data: ";
    print_data(&data2);
    std::cout << "Serialized data: " << Serializer::serialize(&data2) << std::endl;
    std::cout << "Deserialized data: ";
    print_data(Serializer::deserialize(Serializer::serialize(&data2)));
    std::cout << "Deserialize(Serialize(data))==data: " << (&data2 == Serializer::deserialize(Serializer::serialize(&data2)) ? "yes" : "no") << std::endl;

    std::cout << "\nTesting data3" << std::endl;
    std::cout << "Data: ";
    print_data(&data3);
    std::cout << "Serialized data: " << Serializer::serialize(&data3) << std::endl;
    std::cout << "Deserialized data: ";
    print_data(Serializer::deserialize(Serializer::serialize(&data3)));
    std::cout << "Deserialize(Serialize(data))==data: " << (&data3 == Serializer::deserialize(Serializer::serialize(&data3)) ? "yes" : "no") << std::endl;

    return 0;
}
