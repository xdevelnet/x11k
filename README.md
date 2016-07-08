# x11k
Keylogger for UNIX-like systems like linux/freebsd with Xorg (or x11 compatiable) graphics server. Allows you to log your keyboard actions.

# Installation

1)
```
sudo apt-get install git libx11-dev
```
2)
```
git clone https://github.com/xdevelnet/x11k.git
cd x11k
make
```
Now you have x11k binary and ready to use it. You may wish to move it into some $PATH dirs.

# Usage
1) ``x11k -m background -a /path/to/log/file``
2) ``x11k -m foreground``
3) ``x11k status``
4) ``x11k stop``
