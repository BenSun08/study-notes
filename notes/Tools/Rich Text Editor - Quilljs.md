---
title: "Rich Text Editor - Quill.js"
author: "San Wang"
date: "2022-07-06"
---

## Basic Concepts

### Modular Architecture

  *Quill.js* is made up of the *editor core* and several modules like *clipboard*, *keyboard* .etc.
You can also customize your own module using its API.
  Its editor core includes *Parchment* to present content and fromats and *Delta* to describe contents and its changes, like insertion and deletion.

### Documentation Model

  *Quill.js* has its own documentation model called *Parchment*, where *Blot* and *Attributor* can be corresponding to DOM's *Node* and *Attribute*.

  *Parchment* has serveral types of *Blot*: *Scroll*, *Inline*, *Text*, *Block*, *Embed* and *Break*.
  *Scroll* is the root.
  **Blots that can have children must have at least one child**. Therefore, empty *Block* filled with a *Break* blot.
  **Leaf Blot** can either be *Text* or *Embed* or *Break*, which contribute content and implement `value`.

## Usages

### Module Customization

```js
class Counter {
  constructor(quill, options) {
    this.quill = quill;
    this.options = options;
    this.container = document.querySelector(options.container);
  },
  calculate() {

  },
  update() {

  }
}

Quill.register('modules/counter', Counter);

let quill = new Quill('#editor', {
  modules: {
    counter: {
      container: '#counter',
    }
  },
})
```

### Creating or Extending Blot

Example: Video

```js
const BlockEmbed = Quill.import('blots/block/embed');

class VideoBlot extends BlockEmbed {
  static create(attrs) {
    let node = super.create(); // create the DOM Node
    node.setAttribute('src', attrs.url);
    node.setAttribute('controls', attrs.controls);
    node.setAttribute('width', attrs.width);
    node.setAttribute('height', attrs.height);
  },
  static value (node) {
    return {
      url: node.getAttribute('src'),
    }
  }

}

VideoBlot.blotName = 'video';
VideoBlot.tagName = 'video';

Quill.register(VideoBlot, true);

quill.insertEmbed(quill.getSelection().index + 1, 'video', {
  url: 'https://....',
  controls: 'controls',
})
```

## Problem in Practice

1. When you dynamically change the `src` attribute of `<source>` html tag there will be no effect, use the `src` attribute of the `<video></video>` instead.
  `<source>` is a **empty element** or **void element**.
