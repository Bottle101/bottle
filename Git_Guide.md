# Git 使用指南

*Tip1: 为了共用文件不出差错，不要用UTF-8以外的格式编码，比如中文常用的GBK等等。而且个人建议，代码中无论是注释还是什么的，都不要用中文。因为Windows和Linux的默认编码方式有差异，我用Linux打开Windows程序，所有的中文字符都是乱码的（当然可以从设置里面调，但每个文件都要调一遍，很烦），反之亦然。

*TIP2：另外，如果在Windows下编程，千万不要使用Windows自带的**记事本**编辑任何文本文件。原因是Microsoft开发记事本的团队使用了一个非常弱智的行为来保存UTF-8编码的文件，他们自作聪明地在每个文件开头添加了0xefbbbf（十六进制）的字符，你会遇到很多不可思议的问题，比如，网页第一行可能会显示一个“?”，明明正确的程序一编译就报语法错误，等等，都是由记事本的弱智行为带来的。

#### 教程里大部分是平时用不到的命令，实验室项目平时最多用到下面这些章节介绍的命令，可以对照着教程看一下这几个小章节（破折号后面就对应教程中的相应章节），每个章节3—5分钟就搞定了 https://www.liaoxuefeng.com/wiki/896043488029600/896067008724000

## Git简介 —— Git简介

可看可不看。

## 安装 —— 安装Git

过程不表，详见教程。

## 创建和上传 —— 创建版本库

`mkdir fuck_you`//创建一个用于git文件夹
`cd fuck_you`//进入文件夹

`git init`//对这个文件夹做git的初始化

`git add fuck1.txt fuck2.txt, fuck3.txt`//向这个文件夹里添加文件

`git commit -m "I donnot give a fuck!"`//commit到git上以供其他成员调用

## 回退 —— 时光机穿梭->版本回退

`git log`//显示最近更改

```
git reset --hard HEAD^//回退到上一版本
git reset --hard HEAD^^//回退到上上个版本
git reset --hard Head~100//回退100个版本
```

## 回退以后反悔想退回来 —— 时光机穿梭->版本回退

```
git reflog//显示最近的更改，运行效果如下：

$ git reflog
e475afc HEAD@{1}: reset: moving to HEAD^
1094adb (HEAD -> master) HEAD@{2}: commit: append GPL
e475afc HEAD@{3}: commit: add distributed
eaadf4e HEAD@{4}: commit (initial): wrote a readme file

//看从哪个版本回退的，看得出最后一次操作的版本号是1094adb

git reset --hard 1094a//回退到未来版本
```

## 关联至Github —— 远程仓库->添加远程库

1. 在github上创建一个repo
2. 复制git地址后执行`git remote add origin XXXXX.com/xxxx.git`
3. 上传`git push -u origin master`

一台计算机第一次提交会有ssh警告，只要绑定好ssh以后就不会有问题了，详见教程“远程仓库”章节。

## 从Github下载 —— 从远程库克隆

这个就很简单了，网页进入你想下载的项目，直接git clone，梭哈一下就完了

`git clone XXXXX.com/xxx.git`

## 总结

```
if 第一次安装
	配置ssh https://www.liaoxuefeng.com/wiki/896043488029600/896954117292416

Github上新建repo https://www.liaoxuefeng.com/wiki/896043488029600/898732864121440
本地{
git init
git add
git commit
}
复制GitHub上的repo的ssh XXX.com/xxx.git
git add remote origin XXX.com/xxx/git
git push -u origin master
end
```

```
if 做出了修改{
本地{
git add
git commit
}
git push origin master
}
```

