# node-study mytest

main.js will run a http server in http://127.0.0.1:1337

The API takes an angle (theta) and returns the coordinate on the Rose curve.

rose.html, in turn, moves a circle along the rose curve based on the coordinates returned.

### Setup
```
> npm install
```

##### 1. Run Static Server or open local html file directly (serve rose.html)
```
> npm run static-server
```

##### 2. Run Api Server (serve api)
```
> npm run api-server
```

### Link: 

http://localhost:8080/rose.html

### Response

http://localhost:8080/rose.html -> html response: three.js demo

http://127.0.0.1:1337/api?argv=0.12 -> json response: {"status":0,"output":"1.23 2.23"}


### CORS ISSUE:
Because cube.html and api server in different domains, if query api server from cube.html directly will suffer "Access-Control-Allow-Origin" issue as below image.
![issue](cors.png)

Solution: add below two response headers to allow all domains access
 - "Access-Control-Allow-Origin": "*",
 - "Access-Control-Allow-Headers": "Content-Type"

 Code:  https://github.com/jyunming-chen/node-study/blob/master/mytest/main.js#L61-L62
 