# Class Syntax

## 1. Defining Class

### 1. Class declarations

```js
class Rectangle {
  constructor(height, width) {
    this.height = height;
    this.width = width;
  }
}
```

> difference between _function declaration_ and _class declaration_: **Hoisting**

### 2. Class expressions

```js
const Rectangle = class {
  constructor() {}
};
```

## 2. Constructor

> A constuctor can use the `super` keyword to call the _constructor of the super class_.

## 3. Static methods and properties

> Static members are called without instantiating their class and **cannot** called through a class instance. They used to create _utility function_ or properties that are useful fo caches, or data don't need to be replicated across instances.

## 4. Bindgin `this` with prototype and static methods

> **Class-based** syntax When a static(_this ref to the class_) or prototype(_this ref to the class object/instance_) method is called without a value for `this`, such as by assigning the method to a variable and then calling it, this `this` will be `undefined` inside the method.

```js
class Animal {
  speak () {
    return this
  }
  static eat {
    return this
  }
}
Animal.eat() // class Animal
const eat = Animal.eat
eat() // undefined

const animal = new Animal()
animal.speak() // the Animal object
const speak = animal.speak
speak() // undefined
```

> **Function-based** syntax: in non-strict mode, `this` ref to global object.

```js
const Animal = function () {};
Animal.prototype.speak = function () {
  return this;
};
Animal.eat = function () {
  return this;
};
const animal = new Animal();
const speak = animal.speak;
speak(); // global object(in non-strict mode)

const eat = Animal.eat;
eat(); // global object(in non-strict mode)
```

## 5. Field declarations

### 1. public(default)

### 2. private

```js
class Rectangle {
  #width = 0;
  #height;
  constructor(height, width) {
    this.height = height;
    this.width = width;
  }
}
```

### 3. public, private, protected and readonly modifiers are features of TypeScript

> 1. `protected` property of a class can be accessed by the its derived class
> 2. these modifiers can be used as the shortened `readonly name:string` parameter on the constructor to **create** and **initialize** the `name` member.

```ts
class Person {
  constructor(private name: string) {}
}
```

equal to

```ts
class Person {
  private name: string;
  constructor(name: string) {
    this.name = name;
  }
}
```

## Reference

1. [MDN](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Classes)
2. [TypeScript](https://www.typescriptlang.org/docs/handbook/classes.html)
