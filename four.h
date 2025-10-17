#pragma once

#include <string>
#include <iostream>

class Four{
    public:
        // constructions

        // по умолчанию
        Four();

        //with заполнением
        Four(const size_t &arraySize, unsigned char defaultValue = 0);

        // list of initialization
        Four(const std::initializer_list<unsigned char> &initialValues);

        // of str
        Four(const std::string &string);

        // copying construction
        Four(const Four& other);

        // moving construction
        Four(Four&& other) noexcept;

        Four plus(const Four& other);
        Four minus(const Four& other);

        bool equals(const Four& other);
        bool more(const Four& other);
        bool less(const Four& other);

        std::ostream& print(std::ostream& ounputStream);


        //de construction
        virtual ~Four() noexcept;

    private:

        size_t arraySize;
        unsigned char* array;

        // Four& operator=(const Four& other) = delete;
        // Four& operator=(Four&& other) noexcept = delete;

};