##### 一、下载安装

1. 下载gcc/g++, gdb

   ```shell
   sudo apt-get update
   sudo apt-get install gcc
   sudo apt-get install g++ 	# 编译器
   sudo apt-get install gdb	# 调试器
   ```

2. 下载VScode

3. 安装插件，vscode搜索安装如下插件

   - C/C++ 编译器
   
   - Code Runner，支持一键编译程序
     - 右上角出现三角形按钮，code runner 提供的一键编译运行
     - 快捷键 ctrl+alt+n
     - ctrl+~ 打开集成终端
     
   - Vim
   
     - 设置vim快捷键冲突
   
     - 搜索vim ctrl
   
       - 取消勾选use ctrl keys
   
     - 搜索vim handle
   
       - 编辑settings.json，添加如下内容
   
       - ```json
          "vim.handleKeys": {
                 "<C-a>": false,
                 "<C-b>": false,
                 "<C-c>": false,
                 "<C-d>": false,
                 "<C-e>": false,
                 "<C-f>": false,
                 "<C-g>": false,
                 "<C-h>": false,
                 "<C-i>": false,
                 "<C-j>": false,
                 "<C-k>": false,
                 "<C-l>": false,
                 "<C-m>": false,
                 "<C-n>": false,
                 "<C-o>": false,
                 "<C-p>": false,
                 "<C-q>": false,
                 "<C-r>": false,
                 "<C-s>": false,
                 "<C-t>": false,
                 "<C-u>": false,
                 "<C-v>": false,
                 "<C-w>": false,
                 "<C-x>": false,
                 "<C-y>": false,
                 "<C-z>": false
             },
         ```
   
         

##### 二、配置调试环境

1. 新建工程文件夹

2. 工程文件夹内新建 `.vscode`文件夹

3. `.vscode`下面新建两个json文件

   - 直接编辑tasks.json，或者选中源代码文件，在界面中选择Run > Add Configuration...，然后在下拉列表中选择 C++ (GDB/LLDB) g++ build and debug active file，即选择编译器，生成可执行文件。

     - ```json
       {
         "version": "2.0.0",
         "tasks": [
           {
             "type": "shell",
             "label": "g++ build active file",
             "command": "/usr/bin/g++",
             "args": ["-g", "${file}", "-o", "${fileDirname}/${fileBasenameNoExtension}"],
             "options": {
               "cwd": "/usr/bin"
             },
             "problemMatcher": ["$gcc"],
             "group": {
               "kind": "build",
               "isDefault": true
             }
           }
         ]
       }
       ```

       

   - 直接编辑launch.json，或者选中源代码文件，在界面中选择Run > Add Configuration...，然后在下拉列表中选择C++ (GDB/LLDB) g++ build and debug active file，即选择调试器，用来调试程序

     - ```json
       {
         "version": "0.2.0",
         "configurations": [
           {
             "name": "g++ build and debug active file",
             "type": "cppdbg",
             "request": "launch",
             "program": "${fileDirname}/${fileBasenameNoExtension}",
             "args": [],
             "stopAtEntry": false,
             "cwd": "${workspaceFolder}",
             "environment": [],
             "externalConsole": false,
             "MIMode": "gdb",
             "setupCommands": [
               {
                 "description": "Enable pretty-printing for gdb",
                 "text": "-enable-pretty-printing",
                 "ignoreFailures": true
               }
             ],
             "preLaunchTask": "g++ build active file",
             "miDebuggerPath": "/usr/bin/gdb"
           }
         ]
       }
       ```

       



