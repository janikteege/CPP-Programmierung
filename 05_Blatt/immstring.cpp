#include "immstring.hpp"

// Functions from <cstring> may be used to ease working with 
// null-terminated strings.
// Further reference: https://en.cppreference.com/w/cpp/header/cstring
#include <cstring>

// This header contains std::copy_n for copying sequences of data.
// Further reference: https://en.cppreference.com/w/cpp/header/algorithm
#include <algorithm>

namespace Util {

// NOTE: Compiler errors related to this constructor provide hints to
//        where else you need to use `const`.
ImmutableString::ImmutableString(const ImmutableString& other)
        : m_size{other.size()}, // Order of initialization is important here!
          m_data{new char[m_size+1]} {
    // Note: The string consists of `m_size` characters and is terminated by a
    //       `\x0` character, thus: `m_size+1`.
    std::copy_n(other.c_str(), m_size + 1, m_data);
}

ImmutableString::ImmutableString(const char* src)
        : m_size{(int)strlen(src)},
          m_data{new char[m_size+1]} {
    std::copy_n(src, m_size + 1, m_data);
}

ImmutableString ImmutableString::concat(const ImmutableString& other) const {
    int resultLength = m_size + other.size();
    char* resultBuf = new char[resultLength + 1];
    for(int i = 0; i < m_size; i++) {
        resultBuf[i] = m_data[i];
    }
    for(int i = 0; i < other.size(); i++) {
        resultBuf[m_size + i] = other.c_str()[i];
    }
    resultBuf[m_size + other.size()] = '\x0';
    ImmutableString result = ImmutableString(resultBuf);
    delete[] resultBuf;
    return result;
}

ImmutableString::~ImmutableString() {
    delete[] m_data;
}

ImmutableString::ImmutableString(const char* buf, int len)
        : m_size{len},
          m_data{new char[m_size+1]} {
    std::copy_n(buf, m_size + 1, m_data);
}
} // Util