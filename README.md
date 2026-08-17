# megaphone

The beautiful thing about Unix-like systems is that a pipe is just `stdin` in disguise.

When you use the pipe operator (`|`) in your terminal, the OS seamlessly connects the stdout of the first program directly into the stdin of the second program.

However, we can make our C program smart. We can use a special POSIX function called `isatty()` (_is-a-TTY/Teletype_) to let the program look at its `stdin` and figure out: "Is a human typing at a keyboard, or is a machine feeding me data through a pipe?"

### 1. The Human Interaction
Run it normally without any pipes. The isatty() function will see your terminal.
```bash
./megaphone
```

### 2. The Simple Pipe
Now, let's use the echo command and pipe (|) its output directly into our program.
```bash
echo "hello world, this is a test" | ./megaphone
```

### 3. The Data Muncher
Because pipes are universal, you can feed it the output of any command. Let's pipe the output of ls -l (which lists your files) into `megaphone`:
```bash
ls -l | ./megaphone
```
