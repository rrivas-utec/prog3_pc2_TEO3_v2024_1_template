//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "parallel_max.h"
#include "redirect_io.h"
#include <vector>
#include <iterator>
#include <iostream>
#include <string>


static void test_2_4() {
  using T = std::string;
  std::vector<T> v1;
  std::copy(std::istream_iterator<T>(std::cin), std::istream_iterator<T>(), std::back_inserter(v1));
  auto max_val = parallel_max(v1.begin(), v1.end());
  std::cout << max_val << std::endl;
  
}

TEST_CASE("Question #2.4") {
    execute_test("test_2_4.in", test_2_4);
}