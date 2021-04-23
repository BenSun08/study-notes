# Read the Vue Source Code

## 1. Vue Instance

### `initMixin`

define `Vue.prototype._init` which indicate the init process:

1. set `this._uid`.
2. set `this._isVue`.
3. set `this.$options`.
4. set `_renderProxy`
5. call bundles of initialize functions:

   1. `initLifecycle`: init `$parent`, `$root`, `$children`, `$refs`, `_watcher`, `_inactive`...
   2. `initEvents`: init `_events`, `hasHookEvent` and init parent attached events.
   3. `initRender`: **todo**.
   4. call `beforeCreate` hook.
   5. `initInjections`: resolve injections before data/props. **reason**: in case that `this` has provide property.

      ```js
      let source = vm;
      while (source) {
        if (source._provided && hasOwn(source._provided, provideKey)) {
          result[key] = source._provided[provideKey];
          break;
        }
        source = source.$parent;
      }
      ```

   6. `initState`:
      1. `initProps` and make its properties reactive, and proxy `this.props` to `this._props`
      2. `initMethods`: bind methods to `this`.
      3. `initData` and make them reactive, and proxy `this.data` to `this._data`.
         > *why is data a function when using Vue.extend(extendProps)*: `data` comes from `this.$options`, and `$options` comes from the `constructor` of the class, which is assigned with merged `extendProps` and props from `Vue` class. `data` in our code is stored in `extendProps`, and it's first used to extend as subclass of `Vue`. And then this subclass is used to create component instances. To sum up, `data` in your code is stored in the constructor of the subclass using reference.
      4. `initComputed`:
         1. A `Watcher` instance is created and stored in `this._computedWatchers[]`, the `get()` method of this lazy watcher warp the function that you write. Also, it assign this watcher to the static `target` property of `Dep`. In constructor of the watcher, this `get()` is not invoked immediately.
         2. Using `Object.defineProperty()` to set `this[keyOfComputed]`'s getter, where the dirtiness(whether its dependencies has updated) of this property is judged. If it's dirty, the `get()` method will be invoked.
         3. Every getter's context of the dependencies has a `Dep` instance. When the `get()` method runs, it invokes getters of this watcher's dependencies, where current watcher that trigger this getter was konwn by `Dep.target`, and following procedure was executed: `Dep` instance of this getter was added to the watcher's `deps` list; this watcher was added to the dep's `subs` list as a subscriber.
         4. In dependencies' setter, dep's `notify()` method was invoked, where invokes all its subscribers's(they are all watchers) `update()` method, where the `dirty` property is setted to `true`. Therefore, when the computed value was gotten in somewhere next time, it will trigger its watcher's `get()` method.
            > *Why computed function can't be async*: in computed property's getter, if it's value is dirty, the function you write will run and the result will be attached to the watcher's `value` property. What you get from computed property is the `watcher.value`. If the function is `async`, the value you get won't be the final result.
      5. `initWatch`: set watchers using `this.$watch`.
   7. `initProvide`: resolve provide in to `this._provided`.
   8. call `created` hook.
   9. call `this.$mount`.

### `stateMixin`

1. proxy get function `Vue.prototype.$data` and `Vue.prototype.$props` to `this._data` and `this._props`.

2. `Vue.prototype.$set`: `defineReactive()` of the inserted property.
3. `Vue.prototype.$delete`: reactively delete property of obj/index of array and update on the view.
4. `Vue.prototype.$watch`:
   1. A `Watcher` instance was created, the function you write was attached to its `cb` property. And in its `constructor()`, `getter` was created by the functon's name, and then `get()` method was invoked. Therefore, the relation between `dep` of the property you watch and the `watcher` established.
   2. When the setter of property you are watching is triggered, `dep.notify()` will be invoked. The `watcher` will invoke its `update()` method, and queue the `watcher` into the `scheduler`, which schedule running of the `cb` you write.

### `eventMixin`

1. `Vue.prototype.$on`: add event handler into the array `this._events[eventName]`.
2. `Vue.prototype.$emit`: invoke all the event handlers in the array `this._events[eventName]`.
3. `Vue.prototype.$off`: remove specific one or all the event handlers in the array `this._events[eventName]`.
4. `Vue.prototype.$once`: `$on` a wrapper function, where this wrapper function was `$off` and the event handler was invoked.

### `lifecycleMixin`

1. `Vue.prototype._update`: **todo**
2. `Vue.prototype.$forceUpdate`: invoke `this._watcher.update()` **todo**
3. `Vue.prototype.$destroy`:
   1. invoke `beforeDestroy` hook.
   2. remove self form parent.
   3. teardown its watchers.
   4. invoke `destroyed` hook.
   5. turn off all instance listeners.

### `renderMixin`

1. `Vue.prototype.$nextTick`: **todo**
2. `Vue.prototype._render`: **todo**

## 2. Observer, Dep and Watcher
