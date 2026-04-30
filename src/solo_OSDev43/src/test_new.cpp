extern "C" void terminal_write(const char*);

extern "C" void test_new(void) {
    int* x = new int;

    if (x) {
        *x = 42;
        terminal_write("overloaded new works\n");
    }
}