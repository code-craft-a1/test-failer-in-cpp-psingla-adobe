#include <iostream>
#include <assert.h>

char size(int cms) {
    char sizeName = '\0';
    if(cms < 38) {
        sizeName = 'S';
    } else if(cms > 38 && cms < 42) {
        sizeName = 'M';
    } else if(cms > 42) {
        sizeName = 'L';
    }
    return sizeName;
}

void testTshirtSize() {
    std::cout << "\nTshirt size test\n";
    assert(size(37) == 'S');
    assert(size(40) == 'M');
    assert(size(43) == 'L');

    // Test boundary cases
    assert(size(39) == 'M');
    assert(size(42) == 'L');  
    assert(size(0) == 'S');
    assert(size(100) == 'L');
    assert(size(42) == 'M');
    assert(size(38) == '38');


    std::cout << "All is well (maybe!)\n";
}
