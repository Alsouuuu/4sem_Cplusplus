#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include "hexdump.hpp"
#include <vector>

std::vector<char> hw02_test(std::vector<int> ascii) {
  // Код домашнего задания
  // Преобразование ASCII кода в символьное представление (5 баллов)
  // На вход подается список - численное представление символов в ASCII виде
    auto res = std::vector<char>(ascii.size());
    std::copy (ascii.begin(), ascii.end(), res.begin());
  // Требуется:
  //  a. представить ASCII код в виде символов (2 балла)
    std::for_each(res.begin(), res.end(),[](char &x){x = static_cast<char>(x);});
  //  b. отсортировать символы по убыванию (lambda) (1 балл)
    std::sort(res.begin(), res.end(), std::greater<>());
  // Пример: input = {65, 66, 67}, output = {'C', 'B', 'A'}
  // Написать 5 тестов
  return res;
}

TEST_CASE("hw02", "[test]") {
    REQUIRE(hw02_test(std::vector<int>{65, 66, 67}) == std::vector<char>{ 'C', 'B', 'A' });
    REQUIRE(hw02_test(std::vector<int>{80, 50}) == std::vector<char>{ 'P', '2' });
    REQUIRE(hw02_test(std::vector<int>{57}) == std::vector<char>{'9'});
    REQUIRE(hw02_test(std::vector<int>{90, 62, 49, 70}) == std::vector<char>{ 'Z', 'F', '>', '1' });
    REQUIRE(hw02_test(std::vector<int>{}) == std::vector<char>{});
    REQUIRE(hw02_test(std::vector<int>{1, 26, 94}) == std::vector<char>{ '^', 26, 1 });
}