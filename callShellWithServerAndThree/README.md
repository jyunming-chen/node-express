# node-express callShellWithServerAndThree

main.js will run a http server in http://127.0.0.1:1337


### Setup
```
> npm install
```

##### 1. Run Server or open local html file directly (serve cube.html)
```
> npm run start-mac
```

##### 2. In a browser, connect to server by url "localhost:1337"
```
> (route '/' returns cube.html once connnected)
```

### Link: 

http://localhost:1337/cube.html

### Response

http://localhost:1337/cube.html -> html response: three.js demo

http://127.0.0.1:1337/api?argv=5 -> json response: {"status":0,"output":"120"}


### CORS ISSUE:
Because cube.html and api server in different domains, if query api server from cube.html directly will suffer "Access-Control-Allow-Origin" issue as below image.
![issue](cors.png)

Solution: add below two response headers to allow all domains access
 - "Access-Control-Allow-Origin": "*",
 - "Access-Control-Allow-Headers": "Content-Type"
