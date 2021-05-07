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

## 4. ESLint

> ### `EsLintWebpackPlugin`
>
> ```bash
> npm i -D eslint esling-webpack-plugin @babel/eslint-parser
> npm install -g install-peerdeps
> install-peerdeps --dev eslint-config-airbnb
> ```
>
> _webpack.dev.js_
>
> ```js
> module.exports = {
>   plugins = [new ESLintWebpackPlugin(options)]
> }
> ```
>
> _.eslintrc_
>
> ```json
> {
>   "parser": "@babel/eslint-parser",
>   "extends": ["airbnb", "airbnb/hooks"],
>   "env": {
>     "browser": true,
>     "node": false
>   },
>   "rules": {
>     "import/prefer-default-export": "off" // to override airbnb rules
>   }
> }
> ```

## 5. Authoring Libraries

### Library Configuration

_webpack.config.js_

```js
module.exports = {
  output: {
    library: {
      name: "myLibrary", // the library name
      type: "umd", // specify how the library will be exposed
      export: "default", // specify which export shold be exposed as library.
    },
  },
  externals: {
    lodash: {
      // do not bundle lodash into the output file, and the cosumer should already have lodash instead
      commonjs: "lodash",
      commonjs2: "lodash",
      amd: "lodash",
      root: "_",
    },
  },
};
```

### Publish to NPM

```bash
npm publish
```

## 6. Server-Side Rendering

_webpack.ssr.js_

```js
module.exports = {
  entry {
    index: 'index-server.js'
  },
  output: {
    filename: '[name]-server.js',
    library: {
      type: 'umd',
    }
    globalObject: 'this', // 'window' by default, it's not suitabl for node.js
  },
}
```

_webpack.prod.js_

```js
module.exports = {
  plugins: [
    new HtmlWebpackPlugin({
      title: "",
      filename: "index.html",
      template: path.resolve(__dirname, "public/index.html"),
      minify: {
        removeComments: false, // to remain the placeholder
      },
    }),
  ],
};
```

_server.js_

```js
const { renderToString } = require("react-dom/server");
const SSR = require("../dist/index-server.js");
const html = renderToString(SSr);
const data = require("./data.json");

function renderMarkup(str) {
  const template = require(path.resolve(__dirname, "../dist/index.html"));
  const dataStr = JSON.stringify(data);
  return template
    .replace("<!--HTML_PLACEHOLDER", str)
    .replace(
      "<!--INITIAL_DATA_PLACEHOLDER-->",
      `<script>window.__initial_data=${dataStr}</script>`
    );
}
```

_index-server.js_
**Note**: all ESModule syntax must be transformed to commonjs

```js
require("./index.css");
const React = require("react");

function App(props) {
  return <div>hhh</div>;
}

module.exports = <App />;
```

_index.js_

```js
import ReactDOM from "react-dom";

function App(props) {
  return <div>hhh</div>;
}

ReacDOM.hydrate(<App />, document.getElementById("root")); // add listeners on DOM
```

## 7. Stats

controls what bundle information get displayed.
[reference](https://webpack.js.org/configuration/stats/).

You also can use `friendly-errors-webpack-plugin`

```bash
npm i -D friendly-errors-webpack-plugin
```

*webpack.config.js*

```js
module.exports = {
  stats: 'error-only',
  plugins: [new FriendlyErrorsWebpackPlugin()]
}
```

## 8. Compiler Hooks

The `Compiler` module is the main engine that creates a compilation instance with all the options passed through the `CLI` or `Node API`.
[refernce](https://webpack.js.org/api/compiler-hooks/)

*webpack.config.js*

```js
module.exports = {
  plugins: [
    function() {
      this.hooks.done.tap('done', stats => {
        if(stats.compilation.errorr && 
          process.argv.indexOf('--watch') === -1) 
        {
          console.log('build error')
          process.exit(1)
        }
      })
    }
  ]
}
```
