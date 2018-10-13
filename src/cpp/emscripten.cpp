#include <stdio.h>
#include <emscripten.h>
#include <emscripten/bind.h>
#include "app.h"

using namespace emscripten;


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
