# hello-world-c

Minimal C Hello World.

Build (with a C compiler):

```bash
gcc -o hello hello.c
./hello
```

## Push to GitHub

From this folder, after `gh auth login`:

```bash
gh repo create hello-world-c --public --source=. --remote=origin --push
```

If the name is taken, pick another name instead of `hello-world-c`.
