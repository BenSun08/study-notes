# What is Modular Programing?

[link](https://webpack.js.org/concepts/modules/)

## 1. Background

> Node.js has supported modular programming almost since its inception. On the web, however, support for modules has been slow to arrive. Multiple tools exist that support modular JavaScript on the web, with a variety of benefits and limitations.

## 2. Types

1. _ECAMAScript 2015_ `import` statement.[link](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Statements/import)
2. _CommonJS_ `require()` function.[link](http://www.commonjs.org/specs/modules/1.0/)
   > in _Node.js_ every file is seen as a module. Use `exports[$key] = ...` to add variables to the root module; Use `module.exports = ...` to assign a new value.
3. _AMD_(asynchronous)[link](https://github.com/amdjs/amdjs-api/blob/master/AMD.md)
4. `@import` statement in css/sass/scss file
5. `url(...)`、`<img src="..." />` attribute in HTML

## 3. Webpack Modules

1. webpack only understand js and json file. **loaders** help webpack to process other types of files and convert them to modules.[linck](https://webpack.js.org/concepts/#loaders)
