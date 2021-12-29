#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>		// sort()
#include <cstdio>	// snprintf()
#include <cstdlib>	// abort()
#include <stdexcept>
#include <ctime>
#include "assistant_func.h"

namespace jj02
{
	void test_vector(long&& value);		// 此处使用右值引用，直接传常数即可
}