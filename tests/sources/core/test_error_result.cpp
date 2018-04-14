////////////////////////////////////////////////////////////////////////////////
// The MIT License (MIT)
//
// Copyright (c) 2018 Nicholas Frechette & Animation Compression Library contributors
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
////////////////////////////////////////////////////////////////////////////////

#include <catch.hpp>

#include <acl/core/error_result.h>

#include <cstdint>
#include <cstring>

using namespace acl;

TEST_CASE("ErrorResult", "[core][error]")
{
	REQUIRE(ErrorResult().any() == false);
	REQUIRE(ErrorResult().empty() == true);
	REQUIRE(std::strlen(ErrorResult().c_str()) == 0);

	REQUIRE(ErrorResult("failed").any() == true);
	REQUIRE(ErrorResult("failed").empty() == false);
	REQUIRE(std::strcmp(ErrorResult("failed").c_str(), "failed") == 0);

	ErrorResult tmp("failed");
	REQUIRE(tmp.any() == true);
	tmp.reset();
	REQUIRE(tmp.any() == false);
	REQUIRE(tmp.empty() == true);
	REQUIRE(std::strlen(tmp.c_str()) == 0);
}