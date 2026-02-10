// C++ includes used for precompiling -*- C++ -*-

// Copyright (C) 2003-2025 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// Under Section 7 of GPL version 3, you are granted additional
// permissions described in the GCC Runtime Library Exception, version
// 3.1, as published by the Free Software Foundation.

// You should have received a copy of the GNU General Public License and
// a copy of the GCC Runtime Library Exception along with this program;
// see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
// <http://www.gnu.org/licenses/>.

/** @file stdc++.h
 *  This is an implementation file for a precompiled header.
 */

// 17.4.1.2 Headers

// C
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cfloat>
#include <climits>
#include <csetjmp>
#include <cstdarg>
#include <cstddef>
#include <cstdlib>

#if __cplusplus >= 201103L
#include <cstdint>
#if __cplusplus < 201703L
#include <ciso646>
#endif
#endif

// C++
// #include <bitset>
// #include <complex>
#include <algorithm>
#include <bitset>
#include <functional>
#include <iterator>
#include <limits>
#include <memory>
#include <new>
#include <numeric>
#include <typeinfo>
#include <utility>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <initializer_list>
#include <ratio>
#include <scoped_allocator>
#include <tuple>
#include <typeindex>
#include <type_traits>
#endif

#if __cplusplus >= 201402L
#endif

#if __cplusplus >= 201703L
#include <any>
// #include <execution>
#include <optional>
#include <variant>
#include <string_view>
#endif

#if __cplusplus >= 202002L
#include <bit>
#include <compare>
#include <concepts>
#include <numbers>
#include <ranges>
#include <span>
#include <source_location>
#include <version>
#if __cpp_impl_coroutine
# include <coroutine>
#endif
#endif

#if __cplusplus > 202002L
#include <expected>
#include <stdatomic.h>
#endif

#if _GLIBCXX_HOSTED
// C
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cwchar>
#include <cwctype>

#if __cplusplus >= 201103L
#include <cfenv>
#include <cinttypes>
#include <cstdint>
#include <cuchar>
#if __cplusplus < 201703L
#include <ccomplex>
#include <cstdalign>
#include <cstdbool>
#include <ctgmath>
#endif
#endif

// C++
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <codecvt>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

#if __cplusplus >= 201402L
#include <shared_mutex>
#endif

#if __cplusplus >= 201703L
#include <any>
#include <charconv>
// #include <execution>
#include <filesystem>
#include <optional>
#include <memory_resource>
#include <variant>
#endif

#if __cplusplus >= 202002L
#include <barrier>
#include <bit>
#include <compare>
#include <concepts>
#include <format>
#include <latch>
#include <numbers>
#include <ranges>
#include <span>
#include <stop_token>
#include <semaphore>
#include <source_location>
#include <syncstream>
#include <version>
#endif

#if __cplusplus > 202002L
#include <expected>
#include <flat_map>
#include <flat_set>
#include <generator>
#include <print>
#include <spanstream>
#include <stacktrace>
#include <stdatomic.h>
#include <stdfloat>
#endif

#if __cplusplus > 202302L
#include <text_encoding>
#include <stdbit.h>
#include <stdckdint.h>
#endif

#endif // HOSTED




#ifndef debugcmhnd01s
#define debugcmhnd01s
using namespace std;
template<typename A, typename B> string to_string(pair<A,B> p);
template<typename Container>
auto to_string(const Container& c) -> decltype(c.begin(), c.end(), string());
template<typename T, size_t N> 
string to_string(const array<T, N>& a);

string to_string(char c) { return string(1, c); }
string to_string(bool b) { return b ? "T" : "F"; }
string to_string(string s) { return "\""+s+"\""; }
template<typename T> string to_string(complex<T> x) {return "(" + to_string(x.real()) + ", " + to_string(x.imag()) + ")"; }
template<typename A, typename B> string to_string(pair<A,B> p) {
    return "("+to_string(p.first)+", "+to_string(p.second)+")";
}
string to_string(const char* s) { return string(s); }

template<typename Container>
auto to_string(const Container& c) -> decltype(c.begin(), c.end(), string()) {
    string s="{";
    bool first = true;
    for(const auto& item : c) {
        if(!first) s += ", ";
        s += to_string(item);
        first = false;
    }
    return s+"}";
}

// helper to unpack the tuple
template<std::size_t I = 0, typename... Ts>
typename std::enable_if<I == sizeof...(Ts), void>::type
_tuple_to_string(const std::tuple<Ts...>&, std::string&){}

template<std::size_t I = 0, typename... Ts>
typename std::enable_if<I < sizeof...(Ts), void>::type
_tuple_to_string(const std::tuple<Ts...>& t, std::string& s) {
    if (I) s += ", ";
    s += to_string(std::get<I>(t));
    _tuple_to_string<I + 1>(t, s);
}

// actual overload
template<typename... Ts>
std::string to_string(const std::tuple<Ts...>& t) {
    std::string s = "(";
    _tuple_to_string(t, s);
    return s + ")";
}

template<typename T, size_t N> 
string to_string(const array<T, N>& a) {
    string s="{";
    for(size_t i=0;i<N;i++) s+=(i?", ":"")+to_string(a[i]);
    return s+"}";
}

template<typename T, size_t N> 
string to_string(const T (&a)[N]) {
    string s="{";
    for(size_t i=0;i<N;i++) s+=(i?", ":"")+to_string(a[i]);
    return s+"}";
}

template<size_t N> string to_string(bitset<N> b) {
    return to_string(b.to_string());
}

void debug_out() { cout << "\n"; }

template<typename H, typename... T>
void debug_out(H&& h, T&&... t) {
    cout << " " << to_string(std::forward<H>(h));
    debug_out(std::forward<T>(t)...);
}
#define print(...) cout<<"["<<#__VA_ARGS__<<"]:",debug_out(__VA_ARGS__)
#endif