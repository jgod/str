# str

String utility methods (header-only)

## requirements

C++11 compiler

## usage

All methods for string transformation return new strings.

```
#include "str.h"
using namespace jgod;

str::indexOf("mystring", "pizza") == -1
str::indexOf("catdog", "dog") == 3

str::startsWith("pizza", "pi") == true
str::endsWith("antidisestablishmentarianism", "ism") == true

str::toUpperCase("Joe Shmoe") == "JOE SHMOE"
str::toLowerCase("Joe Shmoe") == "joe shmoe"

str::trim(" x ") == "x"
str::trimLeft(" x ") == "x "
str::trimRight(" x ") == " x"
str::trimRight("Joe Shmoe", ' ') == "Joe"
str::removeWhitespace("Joe   Shmoe") == "JoeShmoe"

// replacement functions replace all occurences
str::replace("aabbccdd", 'a', 'x') == "xxbbccdd"
std::replace("abcd", "ab", "xy") == "xycd"
std::replace("abcd", {"a", "b", "c"}, "x") == "xxxd";
std::replaceSlashes("a/b/c/d") == "abcd";
std::replaceSpaces("a b c d") = "abcd";
std::truncate("abcdefghijk", 6) == "abcdef";
std::truncate("abcdefghijk", 6, "...") == "abcdef...";
```

## license

MIT