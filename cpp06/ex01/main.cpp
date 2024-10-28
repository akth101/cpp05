
#include "Serializer.hpp"



/// @brief /////////////////////////////////

//Data 클래스로 만들어야됨~!!!!!!!!!!!!!!!!!!!
/// @return 
int main() {
    Data data;
    data.str = "Hello, World!";

    uintptr_t serialized = Serializer::serialize(&data);
    Data* deserialized = Serializer::deserialize(serialized);

    std::cout << "Original data: " << data.str << std::endl;
    std::cout << "Deserialized data: " << deserialized->str << std::endl;

    return 0;	
}