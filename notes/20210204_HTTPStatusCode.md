# HTTP Response Status Code

## Five Classed

  1. Informational Responses(100 - 199).
  2. Successful Responses(200 - 299).
  3. Redirects(300 - 399).
  4. Client Errors(400 - 499).
  5. Server Errors(500 - 599).

## Informational Responses

  `101 Switching Protocols`

## Successful Responses

  `200 OK`

## Redirects

  `304 Not Modified`: this tell client that the response is not modified, so the client can continue to use the same cached response.

## Client Errors

  `400 Bad Request`: the server can't understand the request due to the invalid syntax.
  `401 Unauthorized`: mean *unauthenticated*.
  `403 Forbidden`:  the client does not have rights to access the content; that is, *unauthorized*. Unlike `401`, the client's identity is known to the server.
  `404 Not Found`: the server can't found the requested resource.
  `405 Method Not Allowed`: the request method is konwn by the server but has been disabled and cannot be used.

## Server Errors

  `500 Internal Server Error`: the server has encountered a situation it doesn't konw how to handle.
  `502 Bad Gateway`: the server acting as a gateway or proxy, receive an invalid response from the upstream server.
