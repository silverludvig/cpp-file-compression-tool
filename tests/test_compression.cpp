#include <cassert>
#include "main.cpp"


void test_compression() {
    assert(compress("aaa") == "a3" && "Test case 1 for compress failed");
    assert(compress("aabbb") == "a2b3" && "Test case 2 for compress failed");
    assert(compress("") == "" && "Test case for empty string compress failed");
    assert(compress("abc") == "a1b1c1" && "Test case for no repeating chars compress failed");
}

void test_decompression() {
    assert(decompress("a3") == "aaa" && "Test case 1 for decompress failed");
    assert(decompress("a2b3") == "aabbb" && "Test case 2 for decompress failed");
    assert(decompress("") == "" && "Test case for empty string decompress failed");
    assert(decompress("a1b1c1") == "abc" && "Test case for no repeating chars decompress failed");
}

void test_invalid_decompression() {
    assert(decompress("a") == "" && "Test case for invalid decompression failed");
    assert(decompress("a3b") == "" && "Test case for invalid format decompress failed");
}


int main() {
    test_compression();
    test_decompression();
    
    std::cout << "All tests passed!" << std::endl;
    return 0;
}
