# node-express callShellWithServer

main.js will start a http server (using *express*) in http://127.0.0.1:1337,
and the server will execute main with argv url parameter and send response to the browser.

### Setup
```
> npm install
```

### Run Server
```
> npm run start   (the alias for "node main.js")
```

### URL window: http://127.0.0.1:1337/api?argv=5

### Response

http://127.0.0.1:1337/api?argv=5 -> output: 5! = 120

http://127.0.0.1:1337/api -> ! = 1

(main will return factorial result)

這個app 在後端開啟 http port (localhost:1337) 
由前端瀏覽器，以 localhost:1337 (url:port) route /api
get string (?argv:5) 向後端 GET 階乘的運算，結果（只是一個小字串）以response傳回client