#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main() {
    // 1. int -> short
    int largeInt = 40000;
    short shortValue = largeInt;

    cout << "INT -> SHORT: "
         << shortValue << endl;

    // 2. signed -> unsigned
    int negativeValue = -10;
    unsigned int unsignedValue = negativeValue;

    cout << "SIGNED -> UNSIGNED: "
         << unsignedValue << endl;

    // 3. float -> int
    float decimalValue = 25.75f;
    int integerValue = decimalValue;

    cout << "FLOAT -> INT: "
         << integerValue << endl;

    // 4. Signed integer overflow
    int maxInt = numeric_limits<int>::max();

    cout << "INTEGER OVERFLOW\n";

    // Intentional undefined behavior for UBSan testing
    int overflowValue = maxInt + 1;

    cout << overflowValue << endl;

    // 5. Array out-of-bounds
    cout << "ARRAY OUT-OF-BOUNDS\n";

    int values[3] = {10, 20, 30};

    // Intentional invalid memory access for ASan testing
    cout << values[5] << endl;

    // 6. String -> int
    string input = "9999999999";

    try {
        int converted = stoi(input);

        cout << "STRING -> INT: "
             << converted << endl;
    }
    catch (const exception& e) {
        cout << "STRING CONVERSION ERROR: "
             << e.what() << endl;
    }

    return 0;
}
