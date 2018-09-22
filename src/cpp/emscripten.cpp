#include <stdio.h>
#include <emscripten.h>
#include <emscripten/bind.h>
// #include "app.h"

using namespace emscripten;


class Util {
  public:
    static int addTwo (int a, int b);
    static int addThree (int a, int b, int c);
    static int multTwo (int a, int b);
};



int Util::addTwo (int a, int b) {
    return a + b;
}

int Util::addThree (int a, int b, int c) {
    return a + b + c;
}

int Util::multTwo (int a, int b) {
    return a * b ;
}


int main(int argc, char const *argv[]) {
    printf("[WASM] Loaded\n");

    EM_ASM(
        if (typeof window!="undefined") {
            window.dispatchEvent(new CustomEvent("wasmLoaded"))
        } else {
            global.onWASMLoaded && global.onWASMLoaded()
        }
    );

    return 0;
};

EMSCRIPTEN_BINDINGS(my_module) {
    function("addTwo", &Util::addTwo);
    function("addThree", &Util::addThree);
    function("multTwo", &Util::multTwo);
}
