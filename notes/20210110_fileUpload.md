# How To Upload Files In Web APP?

## `<input type="file"/>`

### Attributes

1. `accept`: [unique file types specifiers](https://developer.mozilla.org/en-US/docs/Web/HTML/Element/input/file#unique_file_type_specifiers).

2. `HTMLInputElement.files`: selected files, which is a `FileList` object containing a list of `File` Object.

### Evevnt

1. `change`: triggered when selected files change. In the event handler, you can access files from **this**: `this.files`.

## Using hidden file input element using the click() method

```js
const filtInput = document.querySelector("input[type=file]");
fileInput.click();
```

## Selecting files using drag and drop

```js
document.addEventListener("drop", (e) => {
  e.stopPropagation();
  e.preventDefault();

  const dt = e.dataTransfer;
  const files = dt.files;
  handleFIles(files);
});
```

## Reference

1. [the File API](https://developer.mozilla.org/en-US/docs/Web/API/File/Using_files_from_web_applications)
2. [drag event](https://developer.mozilla.org/en-US/docs/Web/API/Document/drag_event)
