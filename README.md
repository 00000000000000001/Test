# Test
A class for unit tests
## Example
```cpp
#include "Test.hh"

Test test{};

void ten_equals_twenty()
{
    test.equals(10,20);
}

void ten_equals_ten()
{
    test.equals(10,10);
}

void object_is_printed_correctly()
{
    int zahl{42};
    test.prints("42", zahl);
}

void object_is_not_printed_correctly()
{
    int zahl{42};
    test.prints("hello", zahl);
}

void this_test_fails()
{
    test.fail();
}

int main()
{
    ten_equals_twenty();
    ten_equals_ten();
    object_is_printed_correctly();
    object_is_not_printed_correctly();
    this_test_fails();
    return 0;
}
```
