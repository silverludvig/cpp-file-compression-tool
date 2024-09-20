# C++ File Compression and Decompression Tool

This project is a simple file compression and decompression tool using **C++**. The tool uses a basic algorithm to compress files with repetitive data patterns, reducing file size, and can also decompress the files back to their original state.

## Features:
- **Compression**: Reduces the size of text-based files by encoding repeated characters.
- **Decompression**: Restores the file to its original format.
- **Command-line Interface**: Allows users to easily compress or decompress files using command-line arguments.
- **Error Handling**: Handles invalid input, file errors, and edge cases.

## Usage:

### To Compress a File:
```bash
./compress_tool compress <input_file> <output_file>
```

### To Decompress a File:
```bash
./compress_tool decompress <input_file> <output_file>
```

## Example:
```bash
./compress_tool compress input.txt compressed.txt
./compress_tool decompress compressed.txt decompressed.txt
```


