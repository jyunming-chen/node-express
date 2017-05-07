# node-study callShellWithServerAndThree

main.js will run a http server in http://127.0.0.1:1337


### Setup
```
> npm install
```

##### 1. Run Static Server or open local html file directly (serve cube.html)
```
> npm run static-server
```

##### 2. Run Api Server (serve api)
```
> npm run api-server
```

### Link: 

http://localhost:8080/cube.html

### Response

http://localhost:8080/cube.html -> html response: three.js demo

http://127.0.0.1:1337/api?argv=5 -> json response: {"status":0,"output":"120"}


### CORS ISSUE:
Because cube.html and api server in different domains, if query api server from cube.html directly will suffer "Access-Control-Allow-Origin" issue as below image.
![issue](cors.png)

Solution: add below two response headers to allow all domains access
 - "Access-Control-Allow-Origin": "*",
 - "Access-Control-Allow-Headers": "Content-Type"

 Code:  https://github.com/caa1211/node-study/blob/master/callShellWithServerAndThree_differentDomain/main.js#L61-L62
