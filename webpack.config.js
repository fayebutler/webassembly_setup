const WebpackShellPlugin = require('webpack-shell-plugin');
const HtmlWebpackPlugin = require('html-webpack-plugin');
const path = require('path');

var plugins = [];

// create a cpp directory in dist/
// compile the src c++ files into this directory
// outputs a .js and .wasm file
plugins.push(new WebpackShellPlugin({
  // onBuildStart: ['mkdir -p dist/cpp', 'em++ ./src/cpp/emscripten.cpp -o dist/cpp/appWASM.js'],
  onBuildStart: ['mkdir -p dist/cpp', 'emcc --bind -o dist/cpp/appWASM.js src/cpp/emscripten.cpp'],
  onBuildEnd: ['echo "Ending"']
}));

plugins.push(new HtmlWebpackPlugin({
  template:'src/index.html',
  hash:true
}));

var config = {
  entry: {
    app: path.resolve(__dirname, 'src/js/script.js')
  },
  output: {
    path: path.resolve(__dirname, 'dist'), // regular webpack
    filename: 'bundle.js'
  },
  plugins: plugins,
  module: {
  }
}

module.exports = config;
