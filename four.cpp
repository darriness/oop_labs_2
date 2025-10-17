#include <vector>
#include "four.h"


//реализация конструкторов елы палы

Four::Four() : arraySize(0), array(nullptr){}

//конструктор с заполнением
Four::Four(const size_t& arraySize, unsigned char defaultValue) {

    if (defaultValue < '0' || defaultValue > '3') {
        throw std::invalid_argument("digit < 01 or > 03");
    }

    this->arraySize = arraySize;
    this->array = new unsigned char[arraySize];

    //заполнили значением по умолчанию
    for (size_t i = 0; i < arraySize; ++i){
        this->array[i] = defaultValue;
    }
}

//из листа инициализации
Four::Four(const std::initializer_list<unsigned char>& initialValues) {
    arraySize = initialValues.size();
    array = new unsigned char[arraySize];

    size_t index = 0;
    for (const auto& value : initialValues) {

        if (value < '0' || value > '3') {
            throw std::invalid_argument("digit < 00 or > 03");
        }

        array[arraySize - 1 - index] = value;
        index++;
    }

}

//from str
Four::Four(const std::string& String) {
    arraySize = String.size();
    array = new unsigned char[arraySize];

    for (size_t i = 0; i < arraySize; ++i){
        if (String[arraySize - 1 - i] > '3' || String[arraySize - 1 - i] < '0') {
            throw std::invalid_argument("digit < 000 or > 003");
        }

        array[i] = (String[arraySize - 1 - i]);
    }
}



//copying
Four::Four(const Four& other) {
    arraySize = other.arraySize;
    array = new unsigned char[arraySize];

    for (size_t i = 0; i < arraySize; ++i) {
        array[i] = other.array[i];
    }
}

//moving
Four::Four(Four&& other) noexcept {
    arraySize = other.arraySize;
    array = other.array;

    other.arraySize = 0;
    other.array = nullptr;
}

// realization of operations
Four Four::plus(const Four& other){
    size_t max_size = std::max(arraySize, other.arraySize);
    std::vector<unsigned char>result;
    result.reserve((max_size + 1));
    unsigned char perenos = 0;

    for (size_t i = 0; i < max_size; ++i) {
        unsigned char digit1 = (i < arraySize && array != nullptr) ? (array[i] - '0') : 0;
        unsigned char digit2 = (i < other.arraySize && other.array != nullptr) ? (other.array[i] - '0') : 0;

        unsigned char sum = digit1 + digit2 + perenos;
        result.push_back((sum % 4) + '0');
        perenos = sum / 4;
    }

    if (perenos > 0){
        result.push_back(perenos + '0');
    }

    while (result.size() > 1 && result.back() == '0'){
        result.pop_back();
    }

    std::string result_str(result.rbegin(), result.rend());

    return Four(result_str);
}

Four Four::minus(const Four& other){
    if (less(other)) throw std::logic_error("result must be positive");
    //check on odinakovskh numbers

    size_t result_size = arraySize;
    std::vector<unsigned char> result(result_size, '0');
    unsigned char zaem = 0;

    for (size_t i = 0; i < result_size; ++i) {
        unsigned char digit1 = (i < arraySize) ? (array[i] - '0') : 0;
        unsigned char digit2 = (i < other.arraySize && other.array != nullptr) ? (other.array[i] - '0') : 0;

        char difference = digit1 - digit2 - zaem;
        if (difference < 0) {
            difference += 4;
            zaem = 1;
        }
        else zaem = 0;

        result[i] = difference + '0';
    }

    size_t i = result_size;
    while (i > 0 && result[i - 1] == '0') i--;

    if (i == 0) result = {'0'};
    else result.resize(i);

    std::string result_str(result.rbegin(), result.rend());

    return Four(result_str);
}

bool Four::equals(const Four& other) {
    if (arraySize != other.arraySize) return false;

    for (size_t i = 0; i < arraySize; ++i) {
        if (array[i] != other.array[i]) return false;
    }
    return true;
}

bool Four::less(const Four& other) {
    if (arraySize < other.arraySize) return true;
    if (arraySize > other.arraySize) return false;

    for (size_t i = arraySize; i > 0; --i){
        if (array[i-1] < other.array[i-1]) return true;
        if (array[i-1] > other.array[i-1]) return false;
    }
    return false;
}

bool Four::more(const Four& other) {
    return (!less(other) && !equals(other));
}

std::ostream& Four::print(std::ostream& outputStream){
    if (arraySize == 0 || array == nullptr) {
        outputStream << '0';
        return outputStream;
    }
    for (size_t i = arraySize; i > 0; --i ){
        outputStream << (array[i - 1]);
    }
    return outputStream;
}

//and de construction

Four::~Four() noexcept {
    if (array != nullptr) {
        delete[] array;
        array = nullptr;
    }

    arraySize = 0;
}


