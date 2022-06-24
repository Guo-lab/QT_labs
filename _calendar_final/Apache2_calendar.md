# 部署Apache （Kylin_Ubuntu） 

​                                                                                                                                         2022.06 郭思齐

- `sudo apt-get update`
- `sudo apt-get install apache2`

当你安装完；后面我们只需要关注两个目录： /var/www/html 和 /etc/apache2 
[如果你有兴趣可以查一查其他的配置比如域名和虚拟主机（-~ | ~- ）]

理论上讲后面的很多操作只能命令行操作, 因为需要sudo最高权限

- 首先把数据放到待部署的位置：

  - 将remote压缩文件解压，文件名称remote
  - remote文件贴到桌面, 假设桌面绝对路径是/home/a/桌面
  - `sudo mv /home/a/桌面/remote /var/www/html/remote`

- 接下来，开始部署

  - `sudo vi /etc/apache2/mods-enabled/dir.conf`     修改如下（其实就是添加了/remote）

  - ```bash
    <IfModule mod_dir.c>
            DirectoryIndex index.html index.cgi index.pl index.php index.xhtml index.htm /remote
    </IfModule>
    
    # vim: syntax=apache ts=4 sw=4 sts=4 sr no
    ```

  - `sudo vim /etc/apache2/apache2.conf`  最后一行添加 `ServerName localhost:80`

- `systemctl start apache2`

`ip addr` 后得到的主机ip可在内网访问比如我的

2: ens33: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc fq_codel state UP group default qlen 1000
    link/ether 00:0c:29:9d:8e:be brd ff:ff:ff:ff:ff:ff
    altname enp2s1
    inet **aaa.aaa.aaa.136**/24 brd 192.168.183.255 scope global dynamic noprefixroute ens33
    inet6 fe80::161a:c6f7:f926:d0a9/64 scope link noprefixroute 

浏览器输入 192.168.183.136/remote 或  192.168.183.136/remote/files