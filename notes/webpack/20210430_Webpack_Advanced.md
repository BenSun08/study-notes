# Webpack Advanced

## 1. Tree Shaking

- Used in the Javascript context for dead-code elimination. Unused `export` should be dropped.
- It relies on _static structure_ of **ES2015 module syntax**, i.e. `import` and `export`.
- It's used in `production` mode by default.

### Mark the file as side-effect-tree

"side-effect" is defined as code that performs a special behavior when imported, other than exposing one or more export. An Exmaple is polyfills, which affect the global scope and usually do not provide an export.
_package.json_

```json
{
  "sideEffects": ["./src/some-side-effect-file.js", "*.css"]
}
```

## 2. Scope Hoisting

In the output bundles, each imported module is wrapped in a function closure. This makes it slower for your Javascript to execute in the browser.
Scope hoisting breaks these closures and exposes modules to higher scope(concatenate the scope of all the modules into one closure) by changing inner variables' name to avoid naming conficts.

- Only applied to **ES6 Module syntax**
- It's used in `production` mode by default with `webpack.optimize.ModuleConcatenationPlugin`.

## 3. Code Splitting

1. **Entry Points**: using `entry` configuration.
2. **Prevent Duplication**： _entry dependencies_ or `splitChunksla`.

> ### Entry Dependencies
>
> ```js
> module.exports = {
>   entry: {
>     index: { import: "./src/index.js", dependOn: "shared" },
>     another: { import: "./src/another.js", dependOn: "shared" },
>     shared: "loadash",
>   },
> };
> ```

3. **Dynamic Imports**: inline function calls within modules.

> _text.js_
>
> ```js
> export function Text() {
>   return <div>This is the text component</div>;
> }
> ```
>
> _index.js_
>
> ```js
> import("./text.js").then(({ Text }) => {
>   console.log(Text);
> });
> ```
>
> ### Prefetching/Preloading Modules

> [reference](https://webpack.js.org/guides/code-splitting/#prefetchingpreloading-modules)
