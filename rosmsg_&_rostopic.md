# rosmsg & rostopic

写在前面，rosmsg和rostopic都是和ROS通信有关的命令，他们的区别主要在于，rosmsg用来显示这个包有哪些消息类型，每个消息类型包含有哪些消息，而查看这些消息在程序运行中的具体赋值情况，以及对这些消息中变量的值进行操作。

## 显示当前ROS正在运行哪些消息

`rosmsg list`

`rostopic list`

## 显示自己想要看的消息并且查看它每个变量的实时值

`rosmsg show XXX/xxx`

`rostopic echo XXX/xxx`

## 改变某个消息的变量值并且发出去

`rostopic pub XXX/xxx`