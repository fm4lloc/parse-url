# parse-url
simple url parse in C

Usage: ./parseurl url

Example:
```
./parseurl 'scheme://username:password@subdomain.domain.tld:80/path/file-name.suffix?query-string#hash'
```
output:
```
+SCHEME: scheme
+AUTHORITY: username:password@subdomain.domain.tld:80
 +USERINFO: username:password
  -USERNAME: username
  -PASSWORD: password
 -HOST: subdomain.domain.tld
 -PORT: 80
  +PATH: /path/file-name.suffix
   -FILENAME: file-name.suffix
   -QUERY: query-string
   -FRAGMENT: hash

```
