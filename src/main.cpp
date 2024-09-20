#include <iostream>
#include <fstream>
#include <string>

// Function to compress a file using Run-Length Encoding
std::string compress(const std::string& input) {
    std::string compressed = "";
    int n = input.length();
    
    for (int i = 0; i < n; i++) {
        // Count occurrences of current character
        int count = 1;
        while (i < n - 1 && input[i] == input[i + 1]) {
            count++;
            i++;
        }
        compressed += input[i] + std::to_string(count);
    }
    
    return compressed;
}

// Function to decompress a file encoded with Run-Length Encoding
std::string decompress(const std::string& input) {
    std::string decompressed = "";
    int n = input.length();
    
    for (int i = 0; i < n; i++) {
        char character = input[i];
        i++;
        std::string count_str = "";
        
        // Extract the number (count) of the character
        while (i < n && isdigit(input[i])) {
            count_str += input[i];
            i++;
        }
        i--;  // Step back to counteract the loop's increment
        
        int count = std::stoi(count_str);
        
        for (int j = 0; j < count; j++) {
            decompressed += character;
        }
    }
    
    return decompressed;
}

// Main function with command-line interface
int main(int argc, char* argv[]) {
    if (argc < 4) {
        std::cout << "Usage: ./compress_tool <compress|decompress> <input_file> <output_file>" << std::endl;
        return 1;
    }

    std::string mode = argv[1];
    std::string input_file = argv[2];
    std::string output_file = argv[3];

    // Read input file
    std::ifstream infile(input_file);
    if (!infile) {
        std::cerr << "Error opening input file: " << input_file << std::endl;
        return 1;
    }
    std::string input_content((std::istreambuf_iterator<char>(infile)), std::istreambuf_iterator<char>());
    infile.close();

    std::string result;

    if (mode == "compress") {
        result = compress(input_content);
    } else if (mode == "decompress") {
        result = decompress(input_content);
    } else {
        std::cerr << "Invalid mode: " << mode << std::endl;
        return 1;
    }

    // Write output file
    std::ofstream outfile(output_file);
    if (!outfile) {
        std::cerr << "Error opening output file: " << output_file << std::endl;
        return 1;
    }
    outfile << result;
    outfile.close();

    std::cout << "Operation completed successfully!" << std::endl;

    return 0;
}
