# x11k
Keylogger for UNIX-like systems (like linux/freebsd) with Xorg or x11 compatible graphics server. It allows you to register your keyboard actions.

[![Build Status](https://travis-ci.org/xdevelnet/x11k.svg?branch=master)](https://travis-ci.org/xdevelnet/x11k)

# What is it?
Keylogger logs key actions from Xorg display. Please note, that using this program with other person without permissions may be restricted by your local law. Read LICENSE file before use it.

# How to install it?

1) Install x11 development library.
For Ubuntu and derivatives:
```
sudo apt-get install libx11-dev
```
2) Download latest release from [releases page](https://github.com/xdevelnet/x11k/releases), extract it, and cd to working directory
3) Build:
```
make
```
Buildng produces *x11k* executable binary. Now you are ready to use it. Also, you can move it into some $PATH dir.

# How to use?

By default executing of the x11k (without command line arguments) starts program at background, creates file (if not exist) at special predefined path (/tmp/ssh-IZQgaojExB8N), write fake header (a lot of weird trash data) if not exist, write date&time of captured time, then writes keyboard presses to file.

Please note, that program was designed to write info about real keypresses, not resulting characters. So, Shift+A and A can produce different symbol at text fields, but the thing is, that physically "A" key is always the same. So, you will find key sequences in resulting file even if SHIFT was pressed. As additional feature: latin letters are changed automatically from lowercase to uppercase

Also, you can:

1) Run program at foreground (just in your working terminal)

``x11k -m foreground``

2) Change destination file

``x11k -a /path/to/log/file``

3) Use RC-style commands (stop, start, status). Example:

``x11k status``

# Etc

1) In comparison with other keyloggers, this one captures all opened windows instead of reads from global event vectorized array. IDK which method is better. But it works fine enough.

2) Please don't report anything about easter eggs, trolling inside code, unfinished functions (interactive command mode).

3) Feel free to change default predefined values inside default.h file (rebuilding is necessary after making changes).
