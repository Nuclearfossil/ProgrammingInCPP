# C++ Review Part 2

## Overview

In this section, we're going to dig further into building C++ code and less so about the language itself. To do that, we're going to be using the command line a fair bit. If you've installed Visual Studio 2015 (Community) or Visual Studio 2017 you should be good.

Additionally, I'll be looking at using clang as an alternative, so you can see how it works in a non-Visual Studio environment. You can find clang (and llvm) [here](http://llvm.org/).

## Checking your configuration.

You should fire off the 'VS2015 x86 Native Tools Command Prompt' from your start menu for this. You'll know it's working if you can do this:

``` prompt
D:\ProgrammingInCPP\Review02>cl
Microsoft (R) C/C++ Optimizing Compiler Version 19.00.24215.1 for x86
Copyright (C) Microsoft Corporation.  All rights reserved.

usage: cl [ option... ] filename... [ /link linkoption... ]

D:\ProgrammingInCPP\Review02
```

For clarity, we'll call this window/toolset the `cl` compiler.

The same thing goes for clang:

``` prompt
> clang -v
clang version 4.0.1 (tags/RELEASE_401/final)
Target: x86_64-pc-windows-msvc
Thread model: posix
InstalledDir: C:\Program Files\LLVM\bin
```

At this point, you should be good. If not, check out the faq's for each.

For clarity, we'll call this window/toolset the `clang` compiler.

### What is `clang`? 

Wiki defines it as

> a compiler front end for the programming languages C, C++, Objective-C, Objective-C++, OpenMP,[5] OpenCL, and CUDA. It uses LLVM as its back end and has been part of the LLVM release cycle since LLVM 2.6.
>
> It is designed to be able to replace the full GNU Compiler Collection (GCC). Its contributors include Apple, Microsoft, Google, ARM, Sony, Intel and Advanced Micro Devices (AMD). It is open-source software,[6] with source code released under the University of Illinois/NCSA License, a permissive free software licence.

From this, we see the phrase `LLVM`. What is that? Again, Wiki to the rescue [here](https://en.wikipedia.org/wiki/LLVM)

>The LLVM compiler infrastructure project (formerly Low Level Virtual Machine) is a "collection of modular and reusable compiler and toolchain technologies"[3] used to develop compiler front ends and back ends.
>
>LLVM is written in C++ and is designed for compile-time, link-time, run-time, and "idle-time" optimization of programs written in arbitrary programming languages. Originally implemented for C and C++, the language-agnostic design of LLVM has since spawned a wide variety of front ends: languages with compilers that use LLVM include ActionScript, Ada, C#, Common Lisp, Crystal, D, Delphi, Fortran, OpenGL Shading Language, Halide, Haskell, Java bytecode, Julia, Lua, Objective-C, Pony, Python, R, Ruby, Rust, CUDA, Scala,[9] Swift, and Xojo.
>
>The name LLVM was originally an initialism for Low Level Virtual Machine, but this became increasingly less apt as LLVM became an "umbrella project" that included a variety of other compiler and low-level tool technologies, so the project abandoned the initialism.[13] Now, LLVM is a brand that applies to the LLVM umbrella project, the LLVM intermediate representation (IR), the LLVM debugger, the LLVM C++ Standard Library (with full support of C++11 and C++14), etc. LLVM is administered by the LLVM Foundation. Its president is compiler engineer Tanya Lattner.

I don't know if I can describe it better. So I won't try! If you're looking for more infor on `clang` and `LLVM`, go to the source [here](https://clang.llvm.org) and [here](http://llvm.org)

## Compiling your program, redux

Let's take the example from the previous tutorial, but this time as one file.

``` C++
// Example01.cpp
#include <stdio.h>

unsigned int Fibbonaci(unsigned int i)
{
    if (i <= 1)
        return i;

    return Fibbonaci(i - 1) + Fibbonaci(i - 2);
}

int main()
{
    for (unsigned int index = 0; index < 10; index++)
    {
        printf("The Fibbonaci series of %d is %d\n", index, Fibbonaci(index));
    }

    printf("press any key to continue");
    scanf("-");
    return 0;
}
```

This program works exactly the same as our previous example, but it's all contained in one file.

### Using the Microsoft compiler

To compile this into an executable using `cl`, we'd do the following in the source folder:

``` prompt
D:\dev\bagofholding\ProgrammingInCPP\Review02>dir
 Volume in drive D is Data
 Volume Serial Number is AEB0-7600

 Directory of D:\dev\bagofholding\ProgrammingInCPP\Review02

07/13/2017  12:59 PM    <DIR>          .
07/13/2017  12:59 PM    <DIR>          ..
07/13/2017  10:29 AM    <DIR>          Docs
07/13/2017  12:52 PM               398 Example01.cpp
07/13/2017  12:39 PM             1,009 README.md
               2 File(s)          1,407 bytes
               3 Dir(s)  1,841,761,034,240 bytes free

D:\dev\bagofholding\ProgrammingInCPP\Review02>cl Example01.cpp
Microsoft (R) C/C++ Optimizing Compiler Version 19.00.24215.1 for x64
Copyright (C) Microsoft Corporation.  All rights reserved.

Example01.cpp
Microsoft (R) Incremental Linker Version 14.00.24215.1
Copyright (C) Microsoft Corporation.  All rights reserved.

/out:Example01.exe
Example01.obj

D:\dev\bagofholding\ProgrammingInCPP\Review02>dir
 Volume in drive D is Data
 Volume Serial Number is AEB0-7600

 Directory of D:\dev\bagofholding\ProgrammingInCPP\Review02

07/13/2017  12:59 PM    <DIR>          .
07/13/2017  12:59 PM    <DIR>          ..
07/13/2017  10:29 AM    <DIR>          Docs
07/13/2017  12:52 PM               398 Example01.cpp
07/13/2017  12:59 PM           139,776 Example01.exe
07/13/2017  12:59 PM             4,299 Example01.obj
07/13/2017  12:39 PM             1,009 README.md
               4 File(s)        145,482 bytes
               3 Dir(s)  1,841,760,882,688 bytes free

D:\dev\bagofholding\ProgrammingInCPP\Review02>Example01.exe
The Fibbonaci series of 0 is 0
The Fibbonaci series of 1 is 1
The Fibbonaci series of 2 is 1
The Fibbonaci series of 3 is 2
The Fibbonaci series of 4 is 3
The Fibbonaci series of 5 is 5
The Fibbonaci series of 6 is 8
The Fibbonaci series of 7 is 13
The Fibbonaci series of 8 is 21
The Fibbonaci series of 9 is 34
press any key to continue

D:\dev\bagofholding\ProgrammingInCPP\Review02>
```

As you can see above, this ends up with the obj and the executable file living in the same folder as the source file. To redirect the files to other folders, you'd use flags to set different compiler options. Here's an example of putting obj files into an `obj` folder and the execuatble in a `bin` folder:

``` prompt
D:\dev\bagofholding\ProgrammingInCPP\Review02>mkdir obj
D:\dev\bagofholding\ProgrammingInCPP\Review02>mkdir bin
D:\dev\bagofholding\ProgrammingInCPP\Review02>cl /Fo.\obj\ Example01.cpp /Fe.\bin\Example01.exe
Microsoft (R) C/C++ Optimizing Compiler Version 19.00.24215.1 for x64
Copyright (C) Microsoft Corporation.  All rights reserved.

Example01.cpp
Microsoft (R) Incremental Linker Version 14.00.24215.1
Copyright (C) Microsoft Corporation.  All rights reserved.

/out:.\bin\Example01.exe
.\obj\Example01.obj

D:\dev\bagofholding\ProgrammingInCPP\Review02>
```

With `cl`, the `/F` flag represents the "Output File Options" [MS Docs](https://msdn.microsoft.com/en-us/library/f1cb223a.aspx)

### Using clang

The absolute *simplest* way to use `clang` is to invoke `clang-cl`. From [clang.llvm.org](https://clang.llvm.org/docs/UsersManual.html#clang-cl)

> clang-cl is an alternative command-line interface to Clang, designed for compatibility with the Visual C++ compiler, cl.exe.

And thus:

``` prompt
D:\dev\bagofholding\ProgrammingInCPP\Review02> mkdir bin

D:\dev\bagofholding\ProgrammingInCPP\Review02> mkdir obj

D:\dev\bagofholding\ProgrammingInCPP\Review02> clang-cl /Fo.\obj\ Example01.cpp /Fe.\bin\Example01.exe
Example01.cpp(19,5):  warning: 'scanf' is deprecated: This function or variable may be unsafe. Consider using scanf_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online
      help for details. [-Wdeprecated-declarations]
    scanf("-");
    ^
C:\Program Files (x86)\Windows Kits\10\Include\10.0.10240.0\ucrt\stdio.h(1270,33):  note: 'scanf' has been explicitly marked deprecated here
_CRT_STDIO_INLINE int __CRTDECL scanf(
                                ^
1 warning generated.

D:\dev\bagofholding\ProgrammingInCPP\Review02> bin\Example01.exe
The Fibbonaci series of 0 is 0
The Fibbonaci series of 1 is 1
The Fibbonaci series of 2 is 1
The Fibbonaci series of 3 is 2
The Fibbonaci series of 4 is 3
The Fibbonaci series of 5 is 5
The Fibbonaci series of 6 is 8
The Fibbonaci series of 7 is 13
The Fibbonaci series of 8 is 21
The Fibbonaci series of 9 is 34
press any key to continue
```

That said, you can do something *similar* to that using `clang++` (or `clang` if you are looking to only compile C code):

``` prompt
D:\dev\bagofholding\ProgrammingInCPP\Review02> clang++ Example01.cpp -o bin/Example01.exe
Example01.cpp:19:5: warning: 'scanf' is deprecated: This function or variable may be unsafe. Consider using scanf_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online
      help for details. [-Wdeprecated-declarations]
    scanf("-");
    ^
C:\Program Files (x86)\Windows Kits\10\Include\10.0.10240.0\ucrt\stdio.h:1270:33: note: 'scanf' has been explicitly marked deprecated here
_CRT_STDIO_INLINE int __CRTDECL scanf(
                                ^
1 warning generated.
```

Note that this does not generate object files. To generate object files you have to specifcy the `-c` flag to _ONLY_ generate object files; you cannot generate an executable unless you run `clang++` again (or a linker) to link the generated object files into a final target file.

## Next

Something simple this time around - let's move the `Fibbonaci` function below `main` and see what happens:

``` C++
// Example02.cpp
#include <stdio.h>

int main()
{
    for (unsigned int index = 0; index < 10; index++)
    {
        printf("The Fibbonaci series of %d is %d\n", index, Fibbonaci(index));
    }

    printf("press any key to continue");
    scanf("-");
    return 0;
}

unsigned int Fibbonaci(unsigned int i)
{
    if (i <= 1)
        return i;

    return Fibbonaci(i - 1) + Fibbonaci(i - 2);
}
```

And the results:

### cl

``` prompt
D:\dev\bagofholding\ProgrammingInCPP\Review02>cl /Fo.\obj\ Example02.cpp /Fe.\bin\Example02.exe
Microsoft (R) C/C++ Optimizing Compiler Version 19.00.24215.1 for x64
Copyright (C) Microsoft Corporation.  All rights reserved.

Example02.cpp
Example02.cpp(7): error C3861: 'Fibbonaci': identifier not found
```

### clang

``` prompt
D:\dev\bagofholding\ProgrammingInCPP\Review02
> clang++ Example02.cpp -o bin/Example02.exe
Example02.cpp:7:61: error: use of undeclared identifier 'Fibbonaci'
       printf("The Fibbonaci series of %d is %d\n", index, Fibbonaci(index));
                                                           ^
Example02.cpp:11:5: warning: 'scanf' is deprecated: This function or variable may be unsafe. Consider using scanf_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online
     help for details. [-Wdeprecated-declarations]
   scanf("-");
   ^
C:\Program Files (x86)\Windows Kits\10\Include\10.0.10240.0\ucrt\stdio.h:1270:33: note: 'scanf' has been explicitly marked deprecated here
_CRT_STDIO_INLINE int __CRTDECL scanf(
                               ^
1 warning and 1 error generated.
```

If you've ever worked in C/C++ before, this should have been the expected result. You can't invoke a function (or class, type, class, etc) unless it's been either implemented or declared. We can fix this by defining the signature of the function, and only the signature of the function as a `Forward Declaration`, like so:

``` C++
// Example03.cpp
#include <stdio.h>

unsigned int Fibbonaci(unsigned int i);

int main()
{
    for (unsigned int index = 0; index < 10; index++)
    {
        printf("The Fibbonaci series of %d is %d\n", index, Fibbonaci(index));
    }

    printf("press any key to continue");
    scanf("-");
    return 0;
}

unsigned int Fibbonaci(unsigned int i)
{
    if (i <= 1)
        return i;

    return Fibbonaci(i - 1) + Fibbonaci(i - 2);
}
```

### cl
``` prompt
D:\dev\bagofholding\ProgrammingInCPP\Review02>cl /Fo.\obj\ Example03.cpp /Fe.\bin\Example03.exe
Microsoft (R) C/C++ Optimizing Compiler Version 19.00.24215.1 for x64
Copyright (C) Microsoft Corporation.  All rights reserved.

Example03.cpp
Microsoft (R) Incremental Linker Version 14.00.24215.1
Copyright (C) Microsoft Corporation.  All rights reserved.

/out:.\bin\Example03.exe
.\obj\Example03.obj
```

### clang
``` prompt
D:\dev\bagofholding\ProgrammingInCPP\Review02
> clang++ Example03.cpp -o bin/Example03.exe
Example03.cpp:14:5: warning: 'scanf' is deprecated: This function or variable may be unsafe. Consider using scanf_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online
      help for details. [-Wdeprecated-declarations]
    scanf("-");
    ^
C:\Program Files (x86)\Windows Kits\10\Include\10.0.10240.0\ucrt\stdio.h:1270:33: note: 'scanf' has been explicitly marked deprecated here
_CRT_STDIO_INLINE int __CRTDECL scanf(
                                ^
1 warning generated.
```

Let's now move this into a separate file, in this case, called `Functions.cpp` and compile that.

``` C++
// Example04.cpp
#include <stdio.h>

unsigned int Fibbonaci(unsigned int i);

int main()
{
    for (unsigned int index = 0; index < 10; index++)
    {
        printf("The Fibbonaci series of %d is %d\n", index, Fibbonaci(index));
    }

    printf("press any key to continue");
    scanf("-");
    return 0;
}
```

``` C++
// Functions.cpp
unsigned int Fibbonaci(unsigned int i)
{
    if (i <= 1)
        return i;

    return Fibbonaci(i - 1) + Fibbonaci(i - 2);
}
```

Trying to compile that ...

### cl

``` prompt
cl /Fo.\obj\ Example04.cpp /Fe.\bin\Example04.exe
Microsoft (R) C/C++ Optimizing Compiler Version 19.00.24215.1 for x64
Copyright (C) Microsoft Corporation.  All rights reserved.

Example04.cpp
Microsoft (R) Incremental Linker Version 14.00.24215.1
Copyright (C) Microsoft Corporation.  All rights reserved.

/out:.\bin\Example04.exe
.\obj\Example04.obj
Example04.obj : error LNK2019: unresolved external symbol "unsigned int __cdecl Fibbonaci(unsigned int)" (?Fibbonaci@@YAII@Z) referenced in function main
.\bin\Example04.exe : fatal error LNK1120: 1 unresolved externals
```

### clang

``` prompt
D:\dev\bagofholding\ProgrammingInCPP\Review02
> clang++ Example04.cpp -o bin/Example04.exe
Example04.cpp:14:5: warning: 'scanf' is deprecated: This function or variable may be unsafe. Consider using scanf_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online
      help for details. [-Wdeprecated-declarations]
    scanf("-");
    ^
C:\Program Files (x86)\Windows Kits\10\Include\10.0.10240.0\ucrt\stdio.h:1270:33: note: 'scanf' has been explicitly marked deprecated here
_CRT_STDIO_INLINE int __CRTDECL scanf(
                                ^
1 warning generated.
```

Neither can find the `Fibbonaci` symbol. And they can't find it because the `Functions.cpp` file hasn't been compiled. How do we fix that? Well, we compile the file!

### cl
``` prompt
D:\dev\bagofholding\ProgrammingInCPP\Review02>cl /Fo.\obj\ Example04.cpp Functions.cpp /Fe.\bin\Example04.exe
Microsoft (R) C/C++ Optimizing Compiler Version 19.00.24215.1 for x64
Copyright (C) Microsoft Corporation.  All rights reserved.

Example04.cpp
Functions.cpp
Generating Code...
Microsoft (R) Incremental Linker Version 14.00.24215.1
Copyright (C) Microsoft Corporation.  All rights reserved.

/out:.\bin\Example04.exe
.\obj\Example04.obj
.\obj\Functions.obj
```

### clang
``` prompt
D:\dev\bagofholding\ProgrammingInCPP\Review02
> clang++ Example04.cpp Functions.cpp -o bin/Example04.exe
Example04.cpp:14:5: warning: 'scanf' is deprecated: This function or variable may be unsafe. Consider using scanf_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online
      help for details. [-Wdeprecated-declarations]
    scanf("-");
    ^
C:\Program Files (x86)\Windows Kits\10\Include\10.0.10240.0\ucrt\stdio.h:1270:33: note: 'scanf' has been explicitly marked deprecated here
_CRT_STDIO_INLINE int __CRTDECL scanf(
                                ^
1 warning generated.
```

This is all well and good for simple projects. The problem comes into play when you are dealing with larger code bases (dozens, if not hundreds/thousands of files). It's also a complex command line to remember. You could batch this up, if you wanted to. Nothing wrong with that. Or you could use something like `make`, `nmake` or `msbuild` to better manage this process.

But go ahead and take a look at `make` or `nmake`. We'll wait. [Here's even a quick tutorial](http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/)

These are not easy to use systems. Once you get used to them, you can be really productive, but when you have IDEs like Visual Studio, the visual interface makes these systems look like the 1970s based tools that they are. There have been other attempts to make this kind of setup easier to use (`CMake`, `premake` come to mind), but they don't hold a candle to the simplicity of a visual editor.

That said, `make` is a standard. `Cmake` is incredibly prevalent in the Open Source community. It's worth it to investigate these (FYI, Visual Studio 2017 supports `CMake` out of the box).

## Summary
That's a fair bit for this tutorial. That should give you a fair bit to chew on. In the next tutorial, I'll go ahead and go a little more into C++ as a language.
