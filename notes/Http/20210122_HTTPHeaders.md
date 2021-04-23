# Some Properties in HTTP Request/Response Headers

## Request

### `Accept-Encoding`

### `If-Modified-Since`

Sent from cache to validate the freshness of the resource. Response with `Last-Modified`.

### `If-None-Match`

Sent from cache to validate the freshness of the resource. Response with `Etag`.

### `User-Agent`

## Response

### `Cache-Control`

Control the cache behavior.

### `Content-Disposition`

#### As a response header for the main body

> indicate if the content is expected to be _inline_ with the browser or a _attachment_ downloaded locally.

### `Date`

### `ETag`

Used for cache freshness validation.

### `Expires`

The expiration time of the resource. It's use to check the freshness of the cached resource.

### `Last-Modified`

Used from cache freshness validation.

### `Vary`
