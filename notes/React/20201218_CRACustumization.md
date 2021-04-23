# How to Customize the create-react-app Configuration

## 1. Eject

use the `eject` from _react-scripts_ to expose all the hidden configuration files.

> example:
> inside the _webpack.config.js_ file, I found that there are already some config options for .sass and .module.sass file using _sass-loader_. Now I want some extra function, so that it's allowed the sass file import css property from a js file, as belows:
> _webpack.config.js_
>
> ```js
> const options = { sourceMap: true };
> if (preProcessor === "sass-loader")
>   options.sassOptions = {
>     functions: {
>       "theme($valPath)": function (valPath) {
>         // valPath is instance of sass.types.String
>         const pathArr = valPath.getValue().split(".");
>         let res = theme;
>         for (let key of pathArr) {
>           res = res[key];
>           if (!res) throw new Error(`there is no ${valPath} in the theme`);
>         }
>         return sassUtils.castToSass(res);
>       },
>     },
>   };
> ```
>
> _theme.js_
>
> ```js
> module.exports = {
>   colors: {
>     ...
>   },
>   breakpoints: {
>     ...
>   }
> }
> ```
>
> _base.sass_
>
> ```sass
> $themeColors: theme("colors") /* this is a sass map */
> ```
>
> relevant links:
> [sass-loader](https://webpack.js.org/loaders/sass-loader/).
> [sass jsAPI](https://sass-lang.com/documentation/js-api#functions).

## 2. Create Fork from CRA(create-react-app)

Process can be look over on [this site](https://auth0.com/blog/how-to-configure-create-react-app/)
Although this method allow me to keep the original react-scripts and keep pace of the upstream, is have some disadvantages and can't fulfill my demand.

> 1. The process is too tedious. If I want to update the config file, I have to change my forked CRA repo and publish the react-scripts to npm.
> 2. My config file have some variables that are project-specific, like the _theme.js_ where some CSS properties recorded. Its's import inside my _webpack.config.js_ so that I can customize the sass-loader options. In this scenario, defining some specific variables in this forked CRA repo will make it not suitable to be commonly used in another project.
> 3. Also, the forked repo have to keep palce of the original repo. So that you can use the newly release features from the original repo. [Some tools can be used to do that](https://github.com/wei/pull).

Therefore, I cosider this is not a good method for a private project, but good for team work.

## 3. Use some rewire tools

1. [react-app-rewired](https://github.com/timarney/react-app-rewired).
2. [CRACO](https://github.com/gsoft-inc/craco)
