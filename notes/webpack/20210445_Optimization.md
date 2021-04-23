# optimization.splitChunks

## default configuration

  ```js
  module.exports = {
    //...
    optimization: {
      splitChunks: {
        chunks: 'async',
        // minimum size, in bytes, for a chunk to be generated
        minSize: 20000,
        minRemainingSize: 0,
        // minimum times must a module be shared before splitting
        minChunks: 1,
        maxAsyncRequests: 30,
        // maximum number of parallel requests at an entry point
        maxInitialRequests: 30, 
        // size threshold at which splitting is enforced
        enforceSizeThreshold: 50000,
        cacheGroups: {
          defaultVendors: {
            test: /[\\/]node_modules[\\/]/,
            priority: -10,
            reuseExistingChunk: true,
          },
          default: {
            minChunks: 2,
            priority: -20,
            // If the current chunk contains modules already split out from the main bundle, it will be reused instead of a new one being generated. This can impact the resulting file name of the chunk.
            reuseExistingChunk: true,
          },
        },
      },
    },
  };
  ```

## practice

**If you add some custom `cacheGroups` with custom names, these chunks is required to be put in `HttpWebpackPlugin`'s `chunks` options. Where `['chunk-common', 'chunk-vendors', ${entryName}]` is the default value. Also `entry` config need to be changed**

## reference

[optimization.splitChunks](https://webpack.js.org/configuration/optimization/#optimizationsplitchunks)
