#include <stdio.h>
#include <klee/ADT/KTest.h>

int main(int argc, char** argv) {
    KTest* input = kTest_fromFile(argv[1]);
    for (unsigned i = 0; i < input->numObjects; i++) {
        KTestObject object = input->objects[i];
        printf("Variable %s: ", object.name);
        for (unsigned j = 0; j < object.numBytes; j++) {
            printf("\\x%02x", object.bytes[j]);
        }
        printf("\n");
    }
}