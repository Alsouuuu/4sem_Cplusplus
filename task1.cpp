#include <catch2/catch_test_macros.hpp>
#include <ostream>
#include <vector>
#include <algorithm>

std::vector<int> hw01_test(std::vector<int> nums) {
    // Код домашнего задания
    // Фильтрация массива
    // На вход подается список целочисленных чисел. Требуется отфильтровать по следующему правилу:
    auto res = std::vector<int>(nums.size());
    // 1. Отсеять четные числа - на данном этапе новый вектор будет содержать только нечетные числа
    {
        auto last_val = std::copy_if(nums.begin(), nums.end(), res.begin(), [](int x) { return x % 2 != 0; });
        res.resize(std::distance(res.begin(), last_val));
    }
    // 2. Отсеять числа, которые деляться на 3 и на 11
    {
        auto last_val = std::copy_if(res.begin(), res.end(), res.begin(),[](int x) { return x % 3 != 0 and x % 11 != 0; });
        res.resize(std::distance(res.begin(), last_val));
    }
    // 3. В начало вектора добавить 5
    {
        std::reverse(res.begin(), res.end());
        res.push_back(5);
        std::reverse(res.begin(), res.end());
    }
    // 4. Отсортировать по убыванию
    std::sort(res.begin(), res.end(), std::greater<>());
    // 5. Пробежаться по вектору и если встретилось число в диапазоне [5...15], то удвоить его
    std::for_each(res.begin(), res.end(),[](int &x){if (5 <= x and x <= 15) x = x * 2;});
    // 6. Написать 2-3 теста
    // Подсказки: std::copy_if, std::for_each
    return res;
}

TEST_CASE("hw01", "[test]") {
    REQUIRE(hw01_test(std::vector<int>{1, 2, 3, 4}) == std::vector<int>{10, 1});
    REQUIRE(hw01_test(std::vector<int>{1, 2, 25, 4}) == std::vector<int>{25, 10, 1});
    REQUIRE(hw01_test(std::vector<int>{2, 4, 3}) == std::vector<int>{10});
    REQUIRE(hw01_test(std::vector<int>{5, 2, 8, 1, 9}) == std::vector<int>{10, 10, 1});
}