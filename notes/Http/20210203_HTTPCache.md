# What is HTTP Cache?

## Kinds

1. Private browser caches: in your browser.
2. Shared Proxy cached: in ISP or your company.

## Targets

1. a `200` response to a `GET` request containing a resource like HTML documents, images or files.
2. a `301`(moved permanently) response.
3. a `404`(not found) result page.
4. a `206`(partial content) page.
5. responses other than `GET` if sth. suitable for use as cache key is defined.

## Controlling Caching

### The `Cache-Control` header

1. `Cache-Control: no-store`: no caching.
2. `Cache-Control: no-cahce`: a cache will send the request to the origin server for validation before releasing a cached copy.
3. `Cache-Control: private`: the response is intended for a single user.
4. `Cache-Control: public`: the response may be cached by any cache.
5. `Cache-Control: max-age=<seconds>`: indicate the maximum amount of time is which a resource will be considered fresh.
6. `Cache-Control: must-revalidate`: **TODO**.

## Freshness

_cache eviction_: the algorithm for the finite cache stroge to periodically remove some items.

When the cache receive a request for a stale resource, it forwards this request with `If-None-Match` to check if it is in fact still fresh. If so, the server return `304`(Not Modified) header without sending the body of the requested resource.

Freshness lifetime: `Cache-Control: max-age=N`. If it's not present, check `Expires`, then its value is: `Expires` minus `Date`.

Heuristic freshness checking: If origin server does not specify `Cache-Control` or `Expires`. Look for `Last-Modified` header. And the value will be `Date` minus `Last-Modified` divided by 10. And the expiration:

> expirationTime = responseTime + freshnessTime - currentAge

## Revved Resources

Some resources change infrequently, but when they change you want them update quickly, like *js* files and *css* files. These files can be named in a special way with version infomation(like *webpack* names js and css files with hash value). Their updated copies will be cached when the (html) files update, which haves links to them.

## Cache Validation

### `ETag` and `If-None-Match`

### `Last-Modified` and `If-Modifies-Since`

## Varying Responses

 > `Vary` header determines how to match future request headers to decide whether a cached response can be used, or if a fresh one must be requested from the origin server.

 1. `Accept-Encoding`
 2. `User-Agent`
