# node-express callShell

main.js will execute the binary built from main.cpp,


### Setup & Run
```
> npm install 
> npm run start   (the alias for "node main.js")
```


Note: Below command will build main.cpp to *a.out*
```
> npm run build (the alias for "gcc main.cpp")
```

(*a.out* will return factorial result of argv[1])

這個app 不牽涉http 及前端的browser
純粹是：後端的node.js 藉由 shelljs 呼叫 EXE 執行檔