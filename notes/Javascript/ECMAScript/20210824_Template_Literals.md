---
title: "Template Literals"
date: "2021-08-24"
author: "San Wang"
---
<!-- # Template Literals -->

## Description

It's enclosed by the backtick(``).
If there is a expression preceding template literal, it's called **tagged template**.
In this case, tag expression get called with the template literal.

## Tagged Template

```js
function myTag(strings, personExp, ageExp) {
  let str0 = strings[0];
  let str1 = strings[1];
  let str2 = strings[2];

  let ageStr = ageExp > 99 ? 'centenarian' : 'youngster';

  return `${str0}${personExp}${str1}${ageStr}${str2}`;
}
let name = 'Mike';
let age = 24;
console.log(myTag`That person ${name} is a ${age}`) // That person Mike is a youngster
```

## Raw Strings

```js
function tag(strings) {
  console.log(strings.raw[0])
}
```

`String.raw()`

```js
let str = String.raw`Hi\n${2+3}!`

Array.from(str).join(',') // "H,i,\\,n,5,!"
```
