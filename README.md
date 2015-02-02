# parse-url
simple url parse in C

Usage: ./parseurl url

Example:
```
./parseurl 'https://foo:bar@zaz.com:12/go/en/p.php?a=b&c=d%20pong#2'
```
output:
```
+SCHEME: https
+AUTHORITY: foo:bar@zaz.com:12
 +USERINFO: foo:bar
  -USERNAME: foo
  -PASSWORD: bar
 -HOST: zaz.com
 -PORT: 12
  +PATH: /go/en/p.php
   -FILENAME: p.php
   -QUERY: a=b&c=d%20pong
   -FRAGMENT: 2
```
