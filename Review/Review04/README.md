# Review 04 - Where we discuss structs, classes and other stuff

## Overview

The source code this time around is going to be a little different. We're going to have multiple
examples to go over. So this time, the `main.cpp` will work as a driver, executing optional `examples`.

The code structure will look like this:

``` prompt
main.cpp
  - example01.cpp
  - example02.cpp
  - and so on.
```

The `main` function itself will look like this:

``` C++

void main()
{
    int toRun = 0;

    switch (toRun)
    {
        case 0:
        {
            example01();
        }
        break;

        case 1:
        {
            example02()
        }
        break;

        default:
            break;
            
    };
}
```

Change the value of `toRun` to try a different example.  Yes, I could drive this via the keyboard
and a prompt, but you'll want to evaluate (and change) each of the examples. Changing a single int
value will, in my option, be the faster way to iterate.



