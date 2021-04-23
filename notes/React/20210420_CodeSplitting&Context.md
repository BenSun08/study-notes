# Code Splitting and Context in React

## 1. Code Splitting

### `import()`

Using the dynamic `import`

```js
imoprt("./helper").then((helper) => {
  console.log(helper.func(1));
});
```

### `React.lazy() & Suspense`

_Note: They are not available for server-side rendering_
In React you can use `React.lazy()` and `Suspense` to render a dynamic import as a regular componet.
A typical example is the usage in router.

```jsx
import { lazy } from "react";
const Blogs = lazy(() => import("./blogs"));
const Home = lazy(() => import("./home"));

function App() {
  return (
    <Router>
      <Suspense fallback={<div>loading...</div>}>
        <Switch>
          <Route path="/blogs">
            <Blogs />
          </Route>
          <Route path="/">
            <Home />
          </Route>
        </Switch>
      </Suspense>
    </Router>
  );
}
```

## 2. Context

### 1. When to use

Context is designed to share data that considered to be 'global' for a tree of React component, such as the current authenticated user and theme, or preferred language, etc.

### 2. API

#### `React.createContext()`

```js
const MyContext = React.createContext(defaultValue);
```

#### `Context.Provider`

```jsx
<MyContext.Provider value={/* some value*/}>
  <App />
</MyContext.Provider>
```

#### `Context.Consumer`

```jsx
<MyContext.Consumer>
  {value => /* render something based on the context value */}
</MyContext.Consumer>
```

#### `Class.contextType`

```js
class MyClass extends React.Component {
  static contextType = MyContext;

  componentDidMount() {
    const value = this.context;
  }
}
```

#### `React.useContext()`

```js
const value = React.useContext(MyContext);
```

### 3. Examples

#### Dynamic Context

```js
const UserContext = React.createContext(null);

function App() {
  const [user, setUser] = React.useState(null);

  React.useEffect(() => {
    fetchProfile().then((res) => setUser(res.data));
  }, []);

  return (
    <div>
      <UserContext.Provider value={user}>
        <Router />
      </UserContext.Provider>
    </div>
  );
}
```

#### Updating Context from a Nested Component

**context.js**

```js
export const ThemeContext = React.createContext({
  theme: theme.dark,
  toggle: () => {},
});
```

**toggle-button.js**

```jsx
export default function ToggleButton() {
  return (
    <ThemeContext.Cosumer>
      {({ theme, toggle }) => (
        <button style={{ background: theme }} onClick={toggle}>
          Toggle Theme
        </button>
      )}
    </ThemeContext.Cosumer>
  );
}
```
