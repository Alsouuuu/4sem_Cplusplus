#include <cstring> //std::memcmp
#include <fstream> //std::ifstream
#include <iostream>
#include <string>
#include <vector>

struct Blob {
    short version;
    int size;
    char data[12];
};

class version_exception : public std::exception {
public:
    version_exception(const std::string& msg) : msg_(msg) {}
    const char* what() const noexcept override {
            return msg_.c_str();
    }
private:
    std::string msg_;
};

class size_exception : public std::exception {
public:
    size_exception(const std::string& msg) : msg_(msg) {}
    const char* what() const noexcept override {
            return msg_.c_str();
    }
private:
    std::string msg_;
};

class data_exception : public std::exception {
public:
    data_exception(const std::string& msg) : msg_(msg) {}
    const char* what() const noexcept override {
            return msg_.c_str();
    }
private:
    std::string msg_;
};

void do_fs(const std::string &filename) {
    std::ifstream reader(filename, std::ios::in | std::ios::binary);
    if (reader.is_open()) {
        // read bytes from file to buffer
        std::vector<char> bytes;
        int data_sz = 18;
        bytes.resize(data_sz);
        reader.read(reinterpret_cast<char *>(bytes.data()), data_sz);
        // parse blob
        Blob blob;
        std::memcpy(&blob.version, bytes.data(), sizeof(short));
        std::memcpy(&blob.size, bytes.data() + sizeof(short), sizeof(int));
        std::memcpy(&blob.data, bytes.data() + sizeof(short) + sizeof(int), sizeof(blob.data));
        // check version
        if (blob.version < 1 || blob.version > 7) {
            throw version_exception("Invalid version number: " + std::to_string(blob.version));
        }
        // check size
        if (blob.size != 12) {
            throw size_exception("Invalid size: " + std::to_string(blob.size));
        }
        // check data
        const char expected_data

int main()
{
    do_fs("bin_data_hw03_le.bin");

    return 0;
}