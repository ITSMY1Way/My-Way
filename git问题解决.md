转载自：https://my.oschina.net/u/2438381/blog/1568152

### 问题描述

> git提交，push，commit后都没有绿色小勾提示，也没有更改过任何配置文件，崩溃啊超级烦的，然后看了一些方法都不太可行，最后找到了这个，完美解决，

### 分析成因

> Windows Explorer Shell 支持 Overlay Icon 最多15个,Windows自身已经使用了4个,所以就只剩下了11个供我们使用。如果你之前安装了例如Groove这样的软件,那么可能我们可利用的就更少了,轮不到Tortoise了。像这样的情况,我们可以调整Tortoise图标名称的字母顺序,来提高Tortoise的优先位置,因为Windows 内部就是安装名称的字母顺序来优先显示的。

### 解决方法

> 在运行里 输入 regedit 进入 注册表界面,HKEY_LOCAL_MACHINE->SOFTWARE->Microsoft->Windows->CurrentVersion->Explorer->ShellIconOverlayIdentifiers.
> 打开后发现Tortoise 系列（1TortoiseNormal,2TortoiseAdded等）前面有好多项,Tortoise系列排到了15名之后,难怪不显示。现在的任务就是把它们提到前面了,修改一下它们的名字就好（我是看第一项的前缀是空格,说明空格的字符排序在前面,我就加了几个空格）,我改后的名字如（ TortoiseNormal,TortoiseAdded等）,然后关闭再打开注册表,发现Tortoise系列系列图标已经排到前面了,这时SVN的图标并没有显示,靠,重启Explorer（在任务管理器中结束explorer.exe,在文件 ->新建任务 -> 输入explorer,当然可以重启电脑,不过完全没必要.）,这样就ok了,SVN图标又出现了.
>
> 

