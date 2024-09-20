#include <cassert>
#include "main.cpp"

void test_compression() {
    assert(compress("aaa") == "a3");
    assert(compress("aabbb") == "a2b3");
}

void test_decompression() {
    assert(decompress("a3") == "aaa");
    assert(decompress("a2b3") == "aabbb");
}

int main() {
    test_compression();
    test_decompression();
    
    std::cout << "All tests passed!" << std::endl;
    return 0;
}
