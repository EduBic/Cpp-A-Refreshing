
#include <iostream>
#include <bitset>

int main() {
    std::bitset<8> aBitSet(-2);
    std::bitset<8> aNegBitSet("11111111");

    std::cout << "Hello" << std::endl;

    std::cout << aNegBitSet << std::endl;
    //std::cout << aBitSet.to_ullong() << std::endl;
    //std::cout << aNegBitSet.to_ullong() << std::endl;
}