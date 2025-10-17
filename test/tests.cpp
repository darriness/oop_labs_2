#include <gtest/gtest.h>
#include "../four.h"
#include <sstream>

// === Тесты конструкторов ===

TEST(FourTest, DefaultConstructor) {
    Four num;
    std::ostringstream out;
    num.print(out);
    EXPECT_EQ(out.str(), "0");
}

TEST(FourTest, FillConstructor) {
    Four num(8, '3');
    std::ostringstream out;
    num.print(out);
    EXPECT_EQ(out.str(), "33333333");
}

TEST(FourTest, InitializerListConstructor) {
    Four num{'1', '2', '3', '0', '2', '1'};
    std::ostringstream out;
    num.print(out);
    EXPECT_EQ(out.str(), "123021");
}

TEST(FourTest, StringConstructorValid) {
    Four num("1112312");
    std::ostringstream out;
    num.print(out);
    EXPECT_EQ(out.str(), "1112312");
}

TEST(FourTest, StringConstructorInvalid) {
    EXPECT_THROW(Four("1245"), std::invalid_argument);
}

// === Арифметика ===

TEST(FourTest, AddWithoutCarry) {
    Four a("203");
    Four b("12");
    Four c = a.plus(b);
    std::ostringstream out;
    c.print(out);
    EXPECT_EQ(out.str(), "221");
}

TEST(FourTest, AddWithCarry) {
    Four a("333");
    Four b("10");
    Four c = a.minus(b);
    std::ostringstream out;
    c.print(out);
    EXPECT_EQ(out.str(), "323");
}

TEST(FourTest, RemoveWithoutBorrow) {
    Four a("22");
    Four b("1113");
    Four c = a.plus(b);
    std::ostringstream out;
    c.print(out);
    EXPECT_EQ(out.str(), "1201");
}

TEST(FourTest, RemoveWithBorrow) {
    Four a("200");
    Four b("11");
    Four c = a.minus(b);
    std::ostringstream out;
    c.print(out);
    EXPECT_EQ(out.str(), "123");
}

TEST(FourTest, RemoveNegative) {
    Four a("10");
    Four b("23");
    EXPECT_THROW(a.minus(b), std::logic_error);
}