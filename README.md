# str

String utility methods (header-only)

## requirements

C++11 compiler

## usage

Note: all methods for string transformation return new strings.

```cpp
#include "str.h"
using namespace jgod;

str::indexOf("mystring", "pizza") == -1
str::indexOf("catdog", "dog") == 3
str::lastIndexOf("pizza", "z") == 3

str::startsWith("pizza", "pi") == true
str::endsWith("antidisestablishmentarianism", "ism") == true

str::toUpperCase("Joe Shmoe") == "JOE SHMOE"
str::toLowerCase("Joe Shmoe") == "joe shmoe"

str::trim(" x ") == "x"
str::trimLeft(" x ") == "x "
str::trimRight(" x ") == " x"
str::trimRight("Joe Shmoe", ' ') == "Joe"
str::removeWhitespace("Joe   Shmoe") == "JoeShmoe"

// replacement functions replace all occurrences
str::replace("aabbccdd", 'a', 'x') == "xxbbccdd"
std::replace("abcd", "ab", "xy") == "xycd"
std::replace("abcd", {"a", "b", "c"}, "x") == "xxxd"
std::truncate("abcdefghijk", 6) == "abcdef"
std::truncate("abcdefghijk", 6, "...") == "abcdef..."
```

## license

MIT