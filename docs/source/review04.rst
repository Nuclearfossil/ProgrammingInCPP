Review 04 - Where we discuss structs, classes and other stuff
***********************************************************************
Overview
=======================================================================
The source code this time around is going to be a little different. We're going to have multiple
examples to go over. So this time, the `main.cpp` will work as a driver, executing optional `examples`.

The code structure will look like this:

.. code-block:: doscon

    main.cpp
    - example01.cpp
    - example02.cpp
    - and so on.

The ``main`` function itself will look like this:

.. code-block:: C++

    enum Executables
    {
        ex01 = 0,
        ex02,
        endoflist
    };

    void main()
    {
        Executables toRun = ex01;

        switch (toRun)
        {
            case ex01:
            {
                example01();
            }
            break;

            case ex02:
            {
                example02()
            }
            break;

            default:
                break;
                
        };
    }

Change the value of ``toRun`` to try a different example.  Yes, I could drive this via the keyboard
and a prompt, but you'll want to evaluate (and change) each of the examples. Changing a single int
value will, in my option, be the faster way to iterate.

The ``struct`` keyword and our first example (example01.h/cpp)
==============================================================================
Here's a look at the code behind our first example:

.. code-block:: C++

    /// =====================================================================================
    /// In this example, we look at defining new data types using the `struct` keyword
    /// =====================================================================================

    #include <allegro5/allegro.h>
    #include <allegro5/allegro_font.h>
    #include <allegro5/allegro_primitives.h>

    extern ALLEGRO_FONT* gFont;

    /// standard C++ definition of a struct
    struct Vertex
    {
        float x;
        float y;
    };

    /// definition of a struct with an instance of the struct (a variable,
    /// in this case, called `gGlobalPoint`)
    struct Point3D
    {
        float x;
        float y;
        float z;
    } gGlobalPoint;

    /// The more C friendly version
    extern "C"
    {
        typedef struct Point2D
        {
            float x;
            float y;
        } Point2D;
    }

    const float width = 800.0f;
    const float height = 600.0f;

    void Example01()
    {
        struct Vertex point1; // This is valid (and very c like)
        Vertex point2;  // This is valid, and C++

        gGlobalPoint.x = 0.5f * width;
        gGlobalPoint.y = 0.25f * height;

        point1.x = 0.0f;
        point1.y = 0.0f;

        point2.x = 1.0f * width;
        point2.y = 1.0f * height;

        /// An anonymous struct
        struct 
        {
            float x;
            float y;
        } point3;
        point3.x = .75f * width;
        point3.y = .5f * height;

        Point2D point4; // This is C like
        point4.x = .25f * width;
        point4.y = .4f * height;

        // Initialization of the new variable `textPos`
        Vertex textPos =
        {
            500.0f,  // x field of Vertex
            20.0f    // y field of Vertex
        };

        // And draw some text to show what points we're looking at
        al_draw_textf(gFont, 
            al_map_rgb(255, 255, 255), 
            textPos.x, textPos.y, 
            ALLEGRO_ALIGN_LEFT, 
            "Point1 (%f, %f)", point1.x, point1.y);
        textPos.y += 15;

        al_draw_textf(gFont, 
            al_map_rgb(255, 255, 255), 
            textPos.x, textPos.y, 
            ALLEGRO_ALIGN_LEFT, 
            "Point2 (%f, %f)", point2.x, point2.y);
        textPos.y += 15;

        al_draw_textf(gFont, 
            al_map_rgb(255, 255, 255), 
            textPos.x, textPos.y, 
            ALLEGRO_ALIGN_LEFT, 
            "Point3 (%f, %f)", point3.x, point3.y);
        textPos.y += 15;

        al_draw_textf(gFont, 
            al_map_rgb(255, 255, 255), 
            textPos.x, textPos.y, 
            ALLEGRO_ALIGN_LEFT, 
            "Point4 (%f, %f)", point4.x, point4.y);
        textPos.y += 15;

        al_draw_textf(gFont, 
            al_map_rgb(255, 255, 255), 
            textPos.x, textPos.y, 
            ALLEGRO_ALIGN_LEFT, 
            "gGlobalPoint (%f, %f)", gGlobalPoint.x, gGlobalPoint.y);
        textPos.y += 15;

        // Finally, draw some lines.
        al_draw_line(point1.x, point1.y, point2.x, point2.y, al_map_rgb(255, 255, 255), 1);
        al_draw_line(point2.x, point2.y, point3.x, point3.y, al_map_rgb(255, 0, 0), 1);
        al_draw_line(point3.x, point3.y, point4.x, point4.y, al_map_rgb(0, 255, 0), 1);
        al_draw_line(point4.x, point4.y, gGlobalPoint.x, gGlobalPoint.y, al_map_rgb(255, 0, 255), 1);
        al_draw_line(gGlobalPoint.x, gGlobalPoint.y, point1.x, point1.y, al_map_rgb(255, 255, 0), 1);

        al_flip_display();
        al_rest(5.0);
    };

We have a bit more code this time around. What I've done here is enumerate the number of ways that
we can use a ``struct`` (and ``typedef`` for that matter) to create our own new data type, variants
of a 2D vector.

I'm fairly certain most of this will be common knowledge to most readers, so I'm not going to review
every line of code here. However, this bit may be unfamiliar to new C++ coders:

.. code-block:: C++

    extern "C"
    {
        typedef struct Point2D
        {
            float x;
            float y;
        } Point2D;
    }

We've seen the ``extern`` keyword used earlier in this codebase, declaring an ``ALLEGRO_FONT``

``extern ALLEGRO_FONT* gFont;``

If you check out line 8 in ``main.cpp``, you'll see the definition of the ``gFont`` variable:

``ALLEGRO_FONT* gFont = nullptr;``

The ``extern`` keyword just says that the declaration of this variable is done outside this file,
and it's up to the linker to resolve it. Nothing more than that.

But then we have that ``extern "C"`` ... that sure doesn't look like that's what's going on here.

But it kind of is. Here's what Microsoft has to say about the ``extern`` keyword:

    | The ``extern`` keyword declares a variable or function and specifies that it has external linkage
      (its name is visible from files other than the one in which it's defined). When modifying a variable,
      ``extern`` specifies that the variable has static duration (it is allocated when the program begins and
      deallocated when the program ends). The variable or function may be defined in another source file, or
      later in the same file. Declarations of variables and functions at file scope are external by default.

The key takeaway from that is that is specifies the linkage conventions. From a little further 
down in the docs `Microsoft Docs <https://docs.microsoft.com/en-us/cpp/cpp/using-extern-to-specify-linkage>`_

    | In C++, when used with a string, extern specifies that the linkage conventions of another language are being used for the declarator(s). C functions and data can be accessed only if they are previously declared as having C linkage. However, they must be defined in a separately compiled translation unit.
    | 
    | Microsoft C++ supports the strings "C" and "C++" in the string-literal field. All of the standard include files use the extern "C" syntax to allow the run-time library functions to be used in C++ programs.

In short, this enforces the C linkage rules for anything encompassed in the the braces. This isn't
a cheat to force code to be 'pure C', but it does help enfoce *some* rules (alllinker based rules).
Read: This doesn't make the code compile in C - you're using a C++ compiler, it'll still compile it as
C++. It just links it like it's C. Test this theory if you'd like by removing the ``typedef``.

Or, crack open the following link: `Compiler Explorer <https://godbolt.org/g/kC79EA>`_ to see the warnings.

Anyway, this was a bit off-topic. We'll look at ``extern`` after a bit, when looking at linking in C libraries.

When we run this bit of code, we get the following result:

.. image:: Images/review04/example01.png

Counting bytes and a knock to our sanity (example02.h/cpp)
=============================================================================
How much space does a struct take up? From our previous review (Review03), we had a table that illustrated
how big each native data type would be. To help illustrate, let's take the following code:

.. code-block:: C++

    // Example program
    #include <stdio.h>

    int main()
    {
        printf("Size of a char: %lu byte(s)\n", sizeof(char));
        printf("Size of a float: %lu byte(s)\n", sizeof(float));
        printf("Size of a double: %lu byte(s)\n", sizeof(double));
        printf("Size of a int: %lu byte(s)\n", sizeof(int));
        printf("Size of a unsigned int: %lu byte(s)\n", sizeof(unsigned int));
    }

and run it in the C++ shell `C++ shell example <cpp.sh/2kuqg>`_

Here's the output:

.. code-block:: doscon

    Size of a bool:         1 byte(s)
    Size of a char:         1 byte(s)
    Size of a float:        4 byte(s)
    Size of a double:       8 byte(s)
    Size of a int:          4 byte(s)
    Size of a unsigned int: 4 byte(s)

This is a great little table for us to use now. In `example02` I've done the same, so that we have a reference point
to work back from.

.. code-block:: C++

    #include <allegro5/allegro_font.h>

    struct Point2D
    {
        float x;    // 4 bytes
        float y;    // 4 bytes
    };              // 8 bytes total

    struct RGB
    {
        float r;    // 4 bytes
        float g;    // 4 bytes
        float b;    // 4 bytes
    };              // 12 bytes total

    struct RGBA
    {
        float r;    // 4 bytes
        float g;    // 4 bytes
        float b;    // 4 bytes
        float a;    // 4 bytes
    };              // 16 bytes total

    struct UV
    {
        float u;    // 4 bytes
        float v;    // 4 bytes
    };              // 8 bytes total


    struct Vertex
    {
        Point2D position;   // 8 bytes
        RGB     color;      // 12  bytes
        UV      texCoord;   // 8 bytes
    };                      // 28 bytes total

    struct VisibleVertex01
    {
        bool    visible;    // 1 byte
        Point2D position;   // 8 bytes
        RGB     color;      // 12 bytes
        UV      texCoord;   // 8 bytes
    };                      // 29 bytes

    extern ALLEGRO_FONT* gFont;

    void Example02()
    {
        Point2D textPos;
        textPos.x = 10.0f;
        textPos.y = 20.0f;

        al_draw_textf(gFont, al_map_rgb(255, 255, 255), textPos.x, textPos.y, ALLEGRO_ALIGN_LEFT, "Size of char:            %d bytes", sizeof(char));
        textPos.y += 15;
        al_draw_textf(gFont, al_map_rgb(255, 255, 255), textPos.x, textPos.y, ALLEGRO_ALIGN_LEFT, "Size of float:           %d bytes", sizeof(float));
        textPos.y += 15;
        al_draw_textf(gFont, al_map_rgb(255, 255, 255), textPos.x, textPos.y, ALLEGRO_ALIGN_LEFT, "Size of bool:            %d bytes", sizeof(bool));
        textPos.y += 15;
        al_draw_textf(gFont, al_map_rgb(255, 255, 255), textPos.x, textPos.y, ALLEGRO_ALIGN_LEFT, "Size of Point2D:         %d bytes", sizeof(Point2D));
        textPos.y += 15;
        al_draw_textf(gFont, al_map_rgb(255, 255, 255), textPos.x, textPos.y, ALLEGRO_ALIGN_LEFT, "Size of RGB:             %d bytes", sizeof(RGB));
        textPos.y += 15;
        al_draw_textf(gFont, al_map_rgb(255, 255, 255), textPos.x, textPos.y, ALLEGRO_ALIGN_LEFT, "Size of RGBA:            %d bytes", sizeof(RGBA));
        textPos.y += 15;
        al_draw_textf(gFont, al_map_rgb(255, 255, 255), textPos.x, textPos.y, ALLEGRO_ALIGN_LEFT, "Size of UV:              %d bytes", sizeof(UV));
        textPos.y += 15;
        al_draw_textf(gFont, al_map_rgb(255, 255, 255), textPos.x, textPos.y, ALLEGRO_ALIGN_LEFT, "Size of Vertex:          %d bytes", sizeof(Vertex));
        textPos.y += 15;
        al_draw_textf(gFont, al_map_rgb(255, 255, 255), textPos.x, textPos.y, ALLEGRO_ALIGN_LEFT, "Size of VisibleVertex01: %d bytes", sizeof(VisibleVertex01));
        textPos.y += 15;


        al_flip_display();

        al_rest(5.0);

    }

Now, we run this code:

.. image:: Images/review04/struct_sizes.png

Wait now ... What's going on with `VisibleVertex01`? Shouldn't that be 29?

It gets worse. Go ahead and inject the following into `VisibleVertex01`:

.. code-block:: C++

    struct VisibleVertex01
    {
        bool    visible;    // 1 byte
        Point2D position;   // 8 bytes
        bool    dummyA;     // 1 byte
        RGB     color;      // 12 bytes
        UV      texCoord;   // 8 bytes
    };                      // 30 bytes total?

.. image:: Images/review04/struct_sizes_02.png

.. code-block:: C++

    struct VisibleVertex01
    {
        bool    visible;    // 1 byte
        Point2D position;   // 8 bytes
        bool    dummyA;     // 1 byte
        RGB     color;      // 12 bytes
        bool    dummyB;     // 1 byte
        UV      texCoord;   // 8 bytes
    };                      // 31 bytes total?

.. image:: Images/review04/struct_sizes_03.png

.. code-block:: C++

    struct VisibleVertex01
    {
        bool    visible;    // 1 byte
        Point2D position;   // 8 bytes
        bool    dummyA;     // 1 byte
        RGB     color;      // 12 bytes
        bool    dummyB;     // 1 byte
        UV      texCoord;   // 8 bytes
        bool    dummyC;     // 1 byte
    };                      // 32 bytes total?

.. image:: Images/review04/struct_sizes_04.png

What's going on? Is the ``sizeof`` funtion not working?

I mean, that's not a lot of wasted space for an individual element, but it adds up quickly. Thus
we really can't ignore it. In the last version of the `VisibleVertex01` struct, we see that we've
wasted 8 bytes per `VisibleVertex01`. If we were to have a mesh with 65,000 unique instances of that
type, that's 520,000 bytes.

So, how can we fix that? Well, we can use the preprocessor like so:

.. code-block:: C++

    #pragma pack(push)
    #pragma pack(1)
    struct VisibleVertex02
    {
        bool    visible;    // 1 byte
        Point2D position;   // 8 bytes
        RGB     color;      // 12 bytes
        UV      texCoord;   // 8 bytes
    };                      // 29 bytes total
    #pragma pack(pop)

    // a little further down ...

        al_draw_textf(gFont, al_map_rgb(255, 255, 255), textPos.x, textPos.y, ALLEGRO_ALIGN_LEFT, "Size of VisibleVertex02: %02d bytes", sizeof(VisibleVertex02));
        textPos.y += 15;

And now run the program, you get the following:

.. image:: Images/review04/struct_sizes_success.png

That's great, but that still doesn't answer *why*.

Let's start with something simpler:

.. code-block:: C++

    // Example program
    #include <stdio.h>

    struct TestA
    {
        char a; // 1 byte
        int  b; // 4 bytes
    };

    int main()
    {
        printf("Size of a char:  %02lu byte(s)\n", sizeof(char));
        printf("Size of a int:   %02lu byte(s)\n", sizeof(int));
        printf("Size of a TestA: %02lu byte(s)\n", sizeof(TestA));
    
    }

Which results in:

.. code-block:: doscon

    Size of a char:  01 byte(s)
    Size of a int:   04 byte(s)
    Size of a TestA: 08 byte(s)

That *should* have been 5 bytes, no matter how you slice it. So, how does this work?
What's happening here is that *something* in that structure is adding padding. *Why* is it doing
that and *where* is it doing it are the questions we need to answer.

Fundamentally, when dealing with memory, CPUs access memory in *word* sized chunks. I purposely didn't
explicitly say how big a word is, because that actually varies on architecture. For our purposes, this
will be either 4 byte or 8 byte alignment (4 for 32 bit systems, 8 for 64 bit systems).

For now, let's assume a 4 byte alignment (makes the math easier to work with). In the `TestA` struct we
have the first field `a` starting at byte 0. This is A-OK (0 is always a good starting point). And it is a byte
long. So we can assume that the next field `b` starts on the second byte, right?

Nope!

Remember, the CPU is reading in the value from the *word* aligned boundary. In this case, 4 bytes. So there
is padding added into the struct between fields ``a`` and ``b`` of 3 bytes. In essence, the structure looks like this:

.. code-block:: C++

    struct TestA
    {
        char a; // 1 byte
        char pad[3];
        int  b; // 4 bytes
    };

Don't believe me? Let's write some code!

.. code-block:: C++

    // Example program
    #include <stdio.h>
    #include <memory.h>

    struct TestA
    {
        char a; // 1 byte
        int  b; // 4 bytes
    };

    struct TestB
    {
        char a;      // 1 byte
        char pad[3]; // 3 bytes
        int  b;      // 4 bytes
    };

    int main()
    {
        printf("Size of a char:  %02lu byte(s)\n", sizeof(char));
        printf("Size of a int:   %02lu byte(s)\n", sizeof(int));
        printf("Size of a TestA: %02lu byte(s)\n", sizeof(TestA));
        printf("Size of a TestB: %02lu byte(s)\n", sizeof(TestB));

        TestA testA;

        testA.a = 'G';
        testA.b = 76;

        TestB testB;

        memcpy(&testB, &testA, sizeof(TestA));

        printf("testA.a [%c] testB.a [%c]\n", testA.a, testB.a);
        printf("testA.b [%d] testB.b [%d]\n", testA.b, testB.b);

        int result = memcmp(&testB, &testA, sizeof(TestA));

        if (result == 0)
        {
            printf("The memory blocks are equal!\n");
        }
        else
        {
            printf("The memory blocks are UNEQUAL!!!\n");
        }
    }

And the results?

.. code-block:: doscon

    Size of a char:  01 byte(s)
    Size of a int:   04 byte(s)
    Size of a TestA: 08 byte(s)
    Size of a TestB: 08 byte(s)
    testA.a [G] testB.a [G]
    testA.b [76] testB.b [76]
    The memory blocks are equal!

You can see this in the C++ shell `padding example 01 <cpp.sh/8756o>`_

The struct should give you a good idea as to what it looks like, but I like pictures ...

.. code-block:: doscon

    | word boundary | word boundary |
    | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |   Bytes
    | a |           | b             |   |   TestA structure
    | a |     pad   | b             |   |   TestB structure

Let's try it with some different sized data types.

.. code-block:: C++

    // Example program
    #include <stdio.h>

    struct TestA
    {
        char a;     // 1 byte
        double b;   // 8 bytes
    };              // 9 bytes?

    int main()
    {
        printf("Size of a char:   %02lu bytes\n", sizeof(char));
        printf("Size of a double: %02lu bytes\n", sizeof(double));
        printf("Size of a TestA:  %02lu bytes\n", sizeof(TestA));
    }

.. code-block:: doscon

    Size of a char:   01 bytes
    Size of a double: 08 bytes
    Size of a TestA:  16 bytes

[cppshell link](pp.sh/5byeg)

OK, now it's just messing with us. If we're locking into *word* sized boundaries, shouldn't that have been 12?

.. code-block:: C++

    char   a; // 4  bytes
    double b; // 8  bytes
    // total     12 bytes

There's one more piece to the puzzle, and the c-faq has a great blurb on it `On the C-faq <http://c-faq.com/struct/align.esr.html>`_

    | On modern 32-bit machines like the SPARC or the Intel 86, or any Motorola chip from the 68020 up, each data iten must 
      usually be "self-aligned", beginning on an address that is a multiple of its type size. Thus, 32-bit types must begin 
      on a 32-bit boundary, 16-bit types on a 16-bit boundary, 8-bit types may begin anywhere, struct/array/union types have 
      the alignment of their most restrictive member. The first member of each continuous group of bit fields is typically 
      word-aligned, with all following being continuously packed into following words (though ANSI C requires the latter only 
      for bit-field groups of less than word size).

Let's try something to test this theory:

.. code-block:: C++

    // Example program
    #include <stdio.h>

    struct TestA
    {
        char a;
        double b;
        char c;
    };

    int main()
    {
        printf("Size of a char:   %02lu bytes\n", sizeof(char));
        printf("Size of a double: %02lu bytes\n", sizeof(double));
        printf("Size of a TestA:  %02lu bytes\n", sizeof(TestA));
    }

and the output?

.. code-block:: doscon

    Size of a char:   01 bytes
    Size of a double: 08 bytes
    Size of a TestA:  24 bytes

`link to the code <cpp.sh/7y3u>`_

I think you're starting to see a pattern here. Padding is done, per element, based on the largest
type alignment requirements.

For completeness, here's the C++ shell version of the `TestA`/`TestB` structs using the ``#pragma pack(1)``: `reference link <cpp.sh/6tec>`_

I've purposely avoided talking about pointers. I've done this on purpose as this throws a little more complexity into the mix.
I will be talking about them at a later point, but for now, I'd like to move on to classes.

Where we add functionality to our types (example03.h/cpp)
===================================================================
Object Oriented programming.

I'm not goint to talk about Object Oriented programming.

I mean, seriously, in 2017, I think there's enough material on the web to cover Inheritance, Encapsulation, Abstraction, interfaces ...
that's not what I wanted to write this series about. What I want to talk about is the nitty-gritty of the C++ implementation of classes.

If you're looking for an introduction to Object Oriented Programming in C++, I'd recommend you start 
`OOP Introduction here <https://www3.ntu.edu.sg/home/ehchua/programming/cpp/cp3_OOP.html>`_, 
`Welcome to OOP here <http://www.learncpp.com/cpp-tutorial/81-welcome-to-object-oriented-programming/>`_ to start.
As far as printed material, it's been so long since I've taught C++/OOP, I don't think I can recommend anything remotely good. I'm not sure how well Scott Meyers' series of books
holds up these days, but they were decent reading back in '03. I do remember using "C++ How to Program" as a teaching resource back in the 90s, but I haven't looked at it in
over a decade `How to Program C++ by Paul Deitel here <https://www.amazon.com/How-Program-7th-Paul-Deitel/dp/0136117260/ref=sr_1_2?s=books&ie=UTF8&qid=1500351972&sr=1-2>`_

What I do want to talk about is the syntax of Classes. I think that tends to get lost in the shuffle of folks learning C++, so I don't mind burning
a bit of time as part of the refresher.

But first, let's look at the ``struct`` keyword again. We know that it allows us to set up a collection of fields to layout
a structure in memory. But what if we were had the ability to bind Functions as a field?

like so:

.. code-block:: C++

    struct Vertex
    {
        float x;
        float y;
        
        void Set(float inX, float inY)
        {
            x = inX;
            y = inY;
        }
    };

We've essentially merged fields with functions. Could that work? Go ahead and throw that into the C++ shell `example for fields with functions here <http://cpp.sh>`_

It compiles!

So, ... how do we use it? I mean, we have a new struct that has a function, but how do we go about *doing* something with it?

Well, let's create a new variable of type `Vertex` called `point01`:

.. code-block:: C++

    int main()
    {
        Vertex point1;
    }

Add that and compile. Aside from some warnings, that works fine.

So, we already know how to access the fields. What's the chances that accessing the functions is as trivial?

Try this:

.. code-block:: C++

    int main()
    {
        Vertex point1;
        
        point1.Set(10.0f, 20.0f);
        
        printf("The value of point1 is (%f, %f)\n", point1.x, point1.y);
    }

Run it in the C++ shell and ...

.. code-block:: doscon

    The value of point1 is (10.000000, 20.000000) 

That's pretty much it. The ``struct`` keyword is all you need to create objects with data and functions!  We're done!
There's nothing left to learn about C++!

That's total nonsense, I know. There's so much more to cover.

The thing with the ``struct`` keyword is that everything we've done so far is of ``public`` scope. That's the default
scope for anything defined in a struct. That's mostly for backwards compatability, as the original definition of 
the struct keyword in C didn't have a concept of 'data/functional hiding'.

So, scoping in structs. Like I said before, the default scope for a ``struct`` is ``public``. There's also
``private`` and ``protected``.

Both the ``private`` and ``protected`` keywords hide elements of your structure. So if you were to do the following:

.. code-block:: C++

    struct Vertex
    {
        float x;
        float y;
        
        void Set(float inX, float inY)
        {
            x = inX;
            y = inY;
        }
        
        private:
        double mX;
        
        protected:
        char buffer[3];
    };

You would not be able to access either ``mX`` or ``buffer`` in the main function:

.. code-block:: C++

    int main()
    {
        Vertex point1;
        
        point1.Set(10.0f, 20.0f);
        point1.mX = 5.0;
        
        printf("The value of point1 is (%f, %f)\n", point1.x, point1.y);
    }

When compiling produces:

.. code-block:: doscon

    In function 'int main()':
    16:12: error: 'double Vertex::mX' is private
    28:12: error: within this context

Check it out `with a private and protected example here <cpp.sh/46wuk>`_

However, we can access it from inside the ``Vertex`` class:

.. code-block:: C++

    struct Vertex
    {
        float x;
        float y;
        
        void Set(float inX, float inY)
        {
            x = inX;
            y = inY;
            mX = inX - inY;
        }
        
        private:
        double mX;
        
        protected:
        char buffer[3];
    };

Code `with another a private and protected example here <cpp.sh/3o5ty>`_

What we've seen so far is that we're hiding ``private`` and ``protected`` behind the ``struct`` barrier.
We can also use derivation of structs to build object hierarcies:

Creating a new struct called ``ColorVertex`` like so:

.. code-block:: C++

    struct Vertex
    {
        float x;
        float y;
        
        void Set(float inX, float inY)
        {
            x = inX;
            y = inY;
            mX = inX - inY;
        }
        
        private:
        double mX;
        
        protected:
        char buffer[3];
    };

    struct ColorVertex : Vertex
    {
        int r;
        int g;
        int b;
    };

Allows `ColorVertex` to access all `public` and `protected` members of `Vertex`, but it hides 
everything that's `private`. Go ahead, try and access `mX` and the `buffer` members of `Vertex`
through `ColorVertex`. `Sandbox is here <cpp.sh/6nmzf>`_

OK, so that's a very quick run-though of the `struct` usage as an object.

But we never use it.

NEVER.

OK, that's a lie. We tend to use ``structs`` when talking about POD (Plain Old Data) types. But
when you want to define Classes, that's when you use the ``class`` keyword.

What's the difference between ``struct`` and ``class``? One thing, and one thing only - the default
access level. For the `struct` keyword, the default access level is ``public``. For ``class`` it's
``private``.

 - For completeness, POD (Plain Old Data) means nothing more than a struct that contains nothing but data. 
   It can be compelex data, but it contains no 'logic'.

To convert the example over to classes?

.. code-block:: C++

    // Example program
    #include <stdio.h>

    class Vertex
    {
        public:
            float x;
            float y;
        
            void Set(float inX, float inY)
            {
                x = inX;
                y = inY;
                mX = inX - inY;
            }
        
        private:
            double mX;
        
        protected:
            char buffer[3];
    };

    class ColorVertex : public Vertex
    {
        int r;
        int g;
        int b;
    };

    int main()
    {
        ColorVertex point1;
        
        point1.Set(10.0f, 20.0f);
        
        printf("The value of point1 is (%f, %f)\n", point1.x, point1.y);
    }

A couple of things to note:

 #. When deriving from ``Vertex``, we need to qualify it as ``public``. eg ``class ColorVertex : public Vertex``
 #. If you do not do that, and define it as ``class ColorVertex : Vertex`` the scope of `Vertex` defaults to ``private``
 
So what do you get from doing all that? The current set of code fails to compile due to data and functions being
inaccessible? It's not trivial to describe the implementation details of ``private`` inheritance. Think of it like this:

When you privately derive from a base class, all ``public`` members become ``private``. You still have access to all ``protected``
members, but that's it.

So, as an example:

.. code-block:: C++

    // Example program
    #include <stdio.h>

    class Vertex
    {
        public:
            float x;
            float y;
        
            void Set(float inX, float inY)
            {
                x = inX;
                y = inY;
                mX = inX - inY;
            }
        
        private:
            double mX;
        
        protected:
            void ProtectedSet(float inX, float inY)
            {
                x = inX + 5;
                y = inY + 5;
            }
            char buffer[3];
    };

    class ColorVertex : protected Vertex
    {
        public:
        int r;
        int g;
        int b;
        
        void ExposedSet(float inX, float inY)
        {
            ProtectedSet(inX, inY);
        }
        
        float GetX() { return x; }
        float GetY() { return y; }
    };

    int main()
    {
        ColorVertex point1;
        
        point1.ExposedSet(10.0f, 20.0f);
        
        printf("The value of point1 is (%f, %f)\n", point1.GetX(), point1.GetY());
    }

`link to the example is here <cpp.sh/8oubb>`_

That is an incredibly convoluted example. I'll see if I can come up with a better one, but
in all honesty, you tend *not* to use this pattern. I think in all my years of coding, I've
run across it a handfull of times.

Additional references
===================================================================
 - `The Lost Art of C Structure Packing <http://www.catb.org/esr/structure-packing/>`_: Read this. Seriously.
 - `Coding for Performance: Data alignment and structures <https://software.intel.com/en-us/articles/coding-for-performance-data-alignment-and-structures>`_: another good read.
 - `Packed Structures <https://learn.mikroe.com/packed-structures-make-memory-feel-safe/>`_
 - `Sven-Hendrik Haase paper on Alignment in C <https://wr.informatik.uni-hamburg.de/_media/teaching/wintersemester_2013_2014/epc-14-haase-svenhendrik-alignmentinc-paper.pdf>`_
 - `C-Faq blurb <http://c-faq.com/struct/align.html>`_
 - `And, of course, Wikipedia <https://en.wikipedia.org/wiki/Data_structure_alignment>`_
