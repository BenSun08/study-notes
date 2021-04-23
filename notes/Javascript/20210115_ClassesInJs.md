# Some Useful Classes/Objects in Javascript

## `FormData`

> construct a set of key/value pairs representing form fields and their values.

### instance methods

1. `append(key, value)`: the value can be `USVString` or `Blob`(including subclassed such as `File`).

## `Blob`

> The `Blob` Object` is a file-like object of immutable row data. It can be read as text or binary data, or converted to `ReadableStream`. Blobs can represent data which is not neccessarily in a javascript-native format.

### properties

  1. `type`(**read only**): indicate the MIME type of the data contained in the blob.

## `File`

## `ReadableStream`

> `body` property of a `Response` object.

## `ArrayBuffer`

  > The `ArrayBuffer` object is used to represent a generic, fixed-length raw binary data buffer.
  > It's an array of byte. In other languages it's often called **bytes array**.

## `FileReader`

> let web app asynchronously read the contents of files stored on the _user's computer_ using `File` or `Blob`

### properties

1. `result`(**read only**)

### instance methods

1. `readAsDataURL()`: starts reading the contents of the specified `Blob`, once finished, the `result` attribute contains a `data:` URL representing the file's data.
2. `readAsArrayBuffer()`
3. `readAsBinaryString()`
4. `readAsText()`

### events

1. `load`: triggered when reading operation is successfully completed
2. `error`

## `URL`

### static methods

1. `createObjectURL(object)`: object: `Blob` | `File` | `MediaSource`
2. `revokeOjectURL()`
