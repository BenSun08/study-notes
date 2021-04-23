# How to Implement Ripple Effect in React

## 1. Basic HTML Structure

> ripple is actually a circle gradually scale itself util it covers the whole area

```jsx
const handleMouseDown = e => {
  ...
}
const handleMouseUp = e => {
  ...
}
render(
  <button onMouseDown={handleMouseDown} onMouseUp={handleMouseUp}>
    {this.props.chldren}
    <span data-role="ripple-container" />
  </button>
)
```

## 2. Steps

1. insert an out-of-flow element (not in-flow) that cover the area where ripple appears. And set its *'pointer-events'* CSS property to **none** and*'overflow'* to **'hidden'**.

2. the *MouseDown Event* handler do things below:
  >
  > 1. calculate the location of the mouse event relative to its containing box, this is the place where you should insert the ripple
  > 2. calculate the minimum size of the ripple so that it can cover the whole area
  > 3. create an element which includes *animation* CSS property whose value's *keyframe*(I call it **ripple**) process the scale effect.
  > 4. insert the above element into the button element as its child node(cause `ReactDOM.render()` will replace all the child nodes of the container, so I wrap the ripple element with a div so that I can use the `Element.removeChild()` to remove the ripple when the *MouseUp Event* occurs).

3. the *MouseUp Event* handler do things below:
  >
  >1. calculate the duration between the occrrence of *MouseDown Event* and *MouseUp Event*.
  >2. if the duration greater than the *ripple* duration, set the *fade out* animation to `span[data-role=ripple-container]` element by `Element.animate()` immediately
  >3. else the *fade out* animation will not be triggered util the *ripple* animation finished
  >4. when the *fade out* animation finished remove the 'ripple-container' element.

## 3. key API

1. [`Element.getBoundingClientRect()`](https://developer.mozilla.org/en-US/docs/Web/API/Element/getBoundingClientRect): get `DOMRect` instance where containning the information about the element location relative to the viewport.
2. [`Element.animate()`](https://developer.mozilla.org/en-US/docs/Web/API/Element/animate): set animation to Element using pure js and return an `Animation` instance.
3. [`ReactDOM.render() and ReactDOM.unmountComponentAtNode()`](https://reactjs.org/docs/react-dom.html#render): insert and remove React Element. It has restriction.
