//
//
// var importObject = {
//   imports: { imported_func: arg => console.log(arg) }
// };
//
// WebAssembly.instantiateStreaming(fetch('./cpp/hellowrld.wasm'), importObject)
// .then(obj => {
//   console.log("obj");
//   console.log(obj);
//   obj.instance.exports.exported_func()
// });

//
// var Module = {
//   onRuntimeInitialized: function() {
//     console.log('lerp result: ' + Module.lerp(1, 2, 0.5));
//   }
// };
