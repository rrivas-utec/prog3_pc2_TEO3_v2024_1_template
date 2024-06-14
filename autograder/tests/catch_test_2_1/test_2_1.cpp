//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "parallel_max.h"
#include "redirect_io.h"
#include <vector>
#include <iterator>
#include <iostream>

static void test_2_1() {
  using T = int;
  std::vector<T> v1;
  std::copy(std::istream_iterator<T>(std::cin), std::istream_iterator<T>(), std::back_inserter(v1));
  auto max_val = parallel_max(v1.begin(), v1.end());
  std::cout << max_val << std::endl;
}

TEST_CASE("Question #2.1") {
    execute_test("test_2_1.in", test_2_1);
}