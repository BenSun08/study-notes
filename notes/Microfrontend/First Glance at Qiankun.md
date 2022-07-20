---
title: "First Glance at Qiankun"
author: "San Wang"
date: "2022-07-15"
---

## What is Qiankun

- Qiankun is a microfrontend framework constructed based on *single-spa*, which mainly has three types of microfrontends: *single-spa applications*, *single-spa parcels* and *utility modules*.
- From my view, Qiankun only includes the applications part and it makes the setup of a microfrontend project easier.
- Also it has some features that single-spa do not have: *import-html-entry*(fetch the html file of microapp and parse it as an entry point) and *sandbox*.

## How to Set up a Microfrontend App using Qiankun

### Main App

register all the sub apps and start it.

```js
import { registerMicroApps, start } from 'qiankun';

registerMicroApps([
  {
    name: 'reactApp',
    entry: '//localhost:7000', // the url that you get the subapp html file
    container: '#container',
    activeRule: '/app-react',
  },
  {
    name: 'vueApp',
    entry: '//localhost:7001',
    container: '#container',
    activeRule: '/app-vue',
  },
])

start();
```

### Micro App

1. Create a file to change the *run-time* public path when run as a Micro APP
   > `publicPath` is used to rewrite your path to access you bundled files, like the `src` attribute on `<script>` and `herf` on `<link>` tag. `src="/publicPath/js/index.js"`
   >
  ```js
  if(window.__POWERED_BY_QIANKUN__) {
    __webpack_public_path__ = window.__INJECTED_PUBLIC_PATH_BY_QIANKUN__;
  }
  ```

2. Set Router to history mode and set the route base depend on whether its run as micro app or a independent app.

3. Write the hooks in entry file.

   ```js
   export async function bootstrap() {
   } 
   export async function mont(props) {
   } 
   export async function unmount() {
   } 
   ```

4. Configure webpack

   ```js
   const { name } = require('./package.json');

   module.exports = {
    ouput: {
      library: `${name}-[name]`,
      libraryTargey: 'umd',
      jsonpFunction: `webpackJsonp_${name}`
    }
   }
   ```

   > `libraryTarget` used to specific which kind module or variable or IIFE .etc,  can the bundled files be used.
   > `jsonpFunction` is used when the bundled file is loaded asynchronously.
   > *amd*: how *Asynchronous Module Definition* works:
     1. take *Require.js* as an example, it load other module by append a new `<script>` tag after the document body.

     2. `load` event trggerred when the js file loaded on the browser, at the same time append anther script tag.
