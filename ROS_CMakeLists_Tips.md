# ROS CMakeLists 常用命令小笔记

## Define Version

```cmake
cmake_minimum_required(VERSION 2.8.3)
```

## Define Project Name

```cmake
project(${PEOJECT_NAME})
```

## Some Ctrl-V Settings

```cmake
## Compile as C++11, supported in ROS Kinetic and newer
## add_compile_options(-std=c++11)
set(CMAKE_CXX_FLAGS "-std=c++11")
set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -Wall -g -fPIC")
```

p.s. 这些不用去纠结，直接复制粘贴到你的CMakeLists就好，所以叫Ctrl-V设定~

## Find Packages

### Find Depenent CMake Packages

```cmake
find_package(catkin REQUIRED COMPONENTS
roscpp
rospy
std_msgs
message_generation #add it if u defined a custon message type~
##etc.
)
```

p.s. 第三方包

### Find Catkin Packages

```cmake
catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES beginner_tutorials
   CATKIN_DEPENDS roscpp rospy std_msgs
#  DEPENDS system_lib
)
```

p.s. ROS包

### Example For Finding Packages

感觉catin_package()只调用不赋值，赋值全部再find_package(catkin ... )里完成更简洁明了一些

有find_package(catkin REQUIRED COMPONENTS)就是只包含ROS的catkin包，如果是第三方的包，需要另外find packag, e.g. find_package(Eigen3 REQUIRED)

Find Package部分例子代码如下：

```cmake
find_package(catkin REQUIRED COMPONENTS
  roscpp
  tf
  pcl_conversions
  pcl_ros
  nav_msgs
  geometry_msgs
  actionlib
  roborts_common
  roborts_msgs
  interactive_markers
  roborts_costmap
  )

find_package(G2O REQUIRED)
find_package(SUITESPARSE REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(PCL 1.7 REQUIRED)
find_package(ProtoBuf REQUIRED)
find_package(Boost REQUIRED)

catkin_package()
```

## Add Directories

```cmake
include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  ${GeographicLib_INCLUDE_DIRS}
)
```

## Add Executable

```cmake
add_executable(${PROJECT_NAME}_node src/anomaly_detection_node.cpp src/anomaly_detection.cpp)
```

p.s. 如果有多个测试文件（多可执行文件），就用多行add_executable，有几个测试文件用几个

，==一个executable只包含一个可执行文件需要的所有.cpp文件==

## Library Target

```cmake
target_link_libraries(${PROJECT_NAME}_node #only edit this for most cases
  ${catkin_LIBRARIES} #JUST LEAVE IT HERE, DO NOT EDIT
  ${GeographicLib_LIBRARIES} #JUST LEAVE IT HERE, DO NOT EDIT
)
```

## *Custom Message

```cmake
find_package(catkin REQUIRED COMPONENTS
...
message_generation
)
add_message_files(
  FILES
  mode.msg
)
generate_messages(
  DEPENDENCIES
  std_msgs
)
```

p.s. `package.xml`里面还需要加如下代码：

```xml
<build_depend>message_generation</build_depend>
<run_depend>message_runtime</run_depend>
```

