CMake 3.11 之后支持使用 `FetchContent` 下载 Github 上使用 CMake 构建的项目。

这里只是一个简单的示例模板。不过，如果是团队项目，为了避免不可重入，最佳的方案当然还是源码编译，而不是使用网络安装。

## 项目结构

沿用一种单体哲学，把头文件（ `.hpp`）和源文件 （`.cpp`） 放到了一起。

```
├── CMakeLists.txt
├── README.md
├── build
├── src
└── tests
```

## 使用方法

建立 `build` 目录（`-p` 确保目录存在），之后进入 `build` 目录：

```
mkdir -p build
cd build
```

对上一层目录施加“魔法”：

```
cmake ..
```

构建项目：

```
cmake --build .
```

### 运行测试

可以通过 CMake 内置的 `ctest` 执行测试：

```
ctest
```

或者直接运行编译好的测试入口：

```
./cpp_test
```
