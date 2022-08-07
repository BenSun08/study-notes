---
title: "Beginner's Guide"
author: "San Wang"
date: "2022-06-28"
---

## How to locate the *nginx.conf* file in server

### use `locate`

This command searches files in the regularly updated database containing bits of files,
while the `find` command searches through the entire filesystem.

```sh
locate nginx.conf
```

### use `ps`

1. `ps`
  Display information about the *snapshot* of active process.
  If you want *repetitive updated* information, use `top` instead.

  Due to history reasons, there are three types of options:
  >
  > 1. UNIX options: one dash
  > 2. BSD options: no dash
  > 3. GNU options: two dash

    `a`   list all process with a termianl(tty).
    `x`   list all process owned by you.
    `a` + `x`   list all process.  
    `u`   selected by effective user id or user name.

2. `grep`

  *grep [OPTION...] PATTERNS[FILE..]*
  search *PATTERNS* in each *FILE*, and print each line that matches the pattern.

3. **pipe**
  The vertical bar `|` between two command is called **pipe**, it means that the output of the command on the left become the input of the commond on the right.

```sh
ps aux|grep nginx
```

After displaying the information above, we know which configuration file the nginx process is using.

## Basic Usage of Nginx

nginx has one *master process* and several *worker processes*. Master process used to read, evaluate the configuration file and maintain worker processes.

### Starting, Stopping and Reloading Configuration

```sh
nginx -s SIGNAL
```

`stop`, `quit`, `reload`, `reopen`.
Changes that made in the configuration file will be applied until the command to reload configuration file.

```sh
nginx -s reload
```

To see more information, see[Controlling nginx](https://nginx.org/en/docs/beginners_guide.html).

### Configuration Files's Structure

```ng
http {
  server {
    location {
      ...  
    }
  }
}
```

### Serving Static Content

```ng
server {
  location / {
    root /data/www;
    try_files $uri $uri/ /default/index.html;
  }

  location /images/ {
    root /data;
  }

  location /media/ {
    alias /data/myproject/media/;
  }
}
```

`root`  -> `root` value plus the `location` value.
`alias` -> replace the `location` value.
`try_files`  -> check recursively if files exist in a specific order and serve the file located first.

### Simple Proxy Server
