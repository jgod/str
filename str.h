/*
The MIT License (MIT)

Copyright (c) 2015 Justin Godesky

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef str_h
#define str_h

#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <functional>

namespace jgod { namespace str {
#pragma mark - Position
    /** Returns index of first occurence of substring, otherwise returns -1. */
    inline int indexOf(const std::string s, const std::string sub) {
      if (s == "" || sub == "" || sub.length() > s.length()) return -1;
      auto pos = s.find(sub);
      return (pos != std::string::npos) ? pos : -1;
    }
    /** Returns index of last occurrence of substring, otherwise returns -1. */
    inline int lastIndexOf(const std::string &s, const std::string &sub) {
      if (s == "" || sub == "" || sub.length() > s.length()) return -1;
      auto it = std::find_end(std::begin(s), std::end(s), std::begin(sub), std::end(sub));
      return (it != s.end()) ? (it - std::begin(s)) : -1;
    }
    /** Returns whether a string begins with a substring. */
    inline bool startsWith(const std::string &s, const std::string &pre) {return s.find(pre) == 0;}
    /** Returns whether a string ends with a substring. */
    inline bool endsWith(const std::string &s, const std::string &suf) {
      if (s.length() < suf.length()) return false;
      return (0 == s.compare(s.length() - suf.length(), suf.length(), suf));
    }

#pragma mark - Casing
    /** Converts a string to lowercase. */
    inline std::string toLowerCase(std::string s) {
      std::transform(std::begin(s), std::end(s), std::begin(s), ::tolower);
      return s;
    }
    /** Convers a string to uppercase. */
    inline std::string toUpperCase(std::string s) {
      std::transform(std::begin(s), std::end(s), std::begin(s), ::toupper);
      return s;
    }

#pragma mark - Trimming
    /** Trims whitespace at the beginning of a string. */
    inline std::string trimLeft(std::string s) {
      s.erase(std::begin(s),
              std::find_if(std::begin(s),
                           std::end(s),
                           std::not1(std::ptr_fun<int, int>(std::isspace))));
      return s;
    }
    /** Trims whitespace at the end of a string. */
    inline std::string trimRight(std::string s) {
      s.erase(std::find_if(s.rbegin(),
                           s.rend(),
                           std::not1(std::ptr_fun<int, int>(std::isspace))).base(),
              std::end(s));
      return s;
    }
    /** Trims whitespace at the end of a string, starting from a delimiter. */
    inline std::string trimRight(const std::string s, const std::string &delim) {
      return s.substr(0, s.find(delim));
    }
    /** Trims whitespace to the beginning and end of a string. */
    inline std::string trim(const std::string s) {return trimRight(trimLeft(s));}

    /** Removes whitespace from a string. */
    inline std::string removeWhitespace(std::string s) {
      s.erase(std::remove_if(std::begin(s),
                             std::end(s),
                             std::bind(std::isspace<char>, std::placeholders::_1, std::locale::classic())),
              std::end(s));
      return s;
    }

#pragma mark - Splitting
    /** Splits strings based on max line length. */
    inline std::vector<std::string> split(const std::string &s, const int maxLen) {
      std::vector<std::string> subStrs;
      for (auto i = 0; i < s.length(); i += maxLen) {
        subStrs.push_back(s.substr(i, maxLen));
      }
      return subStrs;
    }

    /** Splits strings based on a delimiter. */
    inline std::vector<std::string> split(const std::string &s, const char delim = '\n') {
      std::vector<std::string> strs;
      std::istringstream f(s);
      std::string _s;
      while (std::getline(f, _s, delim)) {strs.push_back(_s);}
      return strs;
    }

#pragma mark - Replacement
    /** Replaces all occurences of a search with a replacement character. */
    inline std::string replace(std::string s, const char search, const char r) {
      std::replace(std::begin(s), std::end(s), search, r);
      return s;
    }
    /** Replaces all occurences of a search with a replacement substring. */
    inline std::string replace(std::string s, const std::string &search, const std::string &r) {
      std::size_t pos = 0;
      while ((pos = s.find(search, pos)) != std::string::npos) {
        s.replace(pos, search.length(), r);
        pos += r.length();
      }
      return s;
    }

    /** Replaces all occurences of multiple searches with a replacement substring. */
    inline std::string replace(std::string s, std::initializer_list<std::string> searches, const std::string &r) {
      for (auto &i : searches) {s = replace(s, i, r);}
      return s;
    }

    /** Replaces everything after a maxLen in a string with a replacement substring (default: ""). */
    inline std::string truncate(std::string s, const int maxLen, const std::string &r = "") {
      if (s.length() > maxLen && maxLen > 0) {s = s.substr(0, maxLen) + r;}
      return s;
    }
}}
#endif /* str_h */
