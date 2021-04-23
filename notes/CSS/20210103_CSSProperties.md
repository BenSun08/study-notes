# CSS properties

## `@media` and `Window.matchMedia()`

> examples:

```css
@media (min-width: 600px) {
  overflow: hidden;
}
```

```ts
let mmRes: boolean = window.matchMedia(`(min-width: 600px)`).matches;
```

## `box-shadow`

Values:

> `inset`: draw shadow inside the border. _It can be used to cover the background_.
> Examples:
> in Chrome, when `<form>`'s `autocomplete` is not `'off'`, you can select some options, and these options has default style from the pseudo class `:-internal-autofill-selected`, and its properties, including `background` are setted withe `!important`, you can use `box-shadow` to cover the `background`:

```css
input:-webkit-autofill {
  -webkit-text-fill-color: green;
  box-shadow: inset 0 0 0 1000px black;
}
```

## `pointer-events`

> set under what circumstances a particular element can become the target of the pointer events.

Values:

> `auto`.
> `none`: the el is never the target of pointer events. However, if its descendant els set to value other than `none`, pointer event will trigger during the event capture/bubble phases.

## `position`

Values

> `fixed`: It's positioned relative to the _containing block_ established by the _viewport_, **except when** one of its ancestors has a `transform`, `perpective` or `filter` property set to value other than `none`, in which case that ancestor behave as the containing block.

## `:hover`

### Example:

> visible when hover

1. `<span>` inside the `<div>`

```css
div > span {
  visibility: hidden;
}
div:hover > span {
  visibility: visible;
}
```

2. `<span>` outside the `<div>`

```css
div:hover + span {
  visibility: visible;
}
```

## `::after`

### Example:

> tool tips:

```html
<span data-tips="this is the tips' content">text</span>
```

```css
span {
  position: relative;
}
span:hover::after {
  content: attr(data-tips);
  position: absolute;
}
```
