.. ProgrammingInC++ documentation master file, created by
   sphinx-quickstart on Sun Jul 23 06:31:55 2017.
   You can adapt this file completely to your liking, but it should at least
   contain the root `toctree` directive.

Programming in C++ Review
***********************************************************************************************************************
An introductory tutorial/review of the C++ programming language

Goals
======================================================================================================================
We understand that there is an existing level of programming expertise by the reader. You are familiar with other 
languages like C#, Rust, Java and Python. This tutorial series attempts to broach the topic of "How do I write code in
C++" as well as touch on other aspects of the development cycle like debugging, improving the build process, and so on.

Source Materials
-----------------------------------------------------------------------------------------------------------------------
Source code, as well as this documentation, can be found in Github in the `ProgrammingInCPP repo <https://github.com/Nuclearfossil/ProgrammingInCPP>`_
Feel free to fork, change and send up a Pull request with changes/additions. This will always be a 'work in progress'
as long as there is interest.

The source code will either be made available in Visual Studio 2015 (or later). You can get the Community edition of the
IDE from Microsoft at `Visual Studio Community <https://www.visualstudio.com/downloads/>`_ as well as on other web 
based compilers like `C++ Shell <http://cpp.sh/>`_ or the `Compiler Explorer <https://gcc.godbolt.org>`_

Sylabus
-----------------------------------------------------------------------------------------------------------------------

Review
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

- Setting up the your build environment.
- Simple language tutorial.

    - Language Basics.
    - Gotchas.

- The process of actually building a console application.

    - Different build types (Debug, Release, Release with Debug symbols).

^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

- Pointer definition
- Stack vs Heap allocations
- Layout of classes in memory
- Finding memory leaks

Intermediate C++
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

- Threading
- Serialization
- RTTI/Exceptions
- Templates
- Lambdas
- New data types (auto)
- More stuff as I find it.
- Some Libraries

    - STL and STL-like libraries
    - Header only vs. Static Libs vs. DLLs


.. toctree::
   :maxdepth: 2
   :caption: Contents:

   review01
   review02
   review03
   review04
   review05
   pointers01
