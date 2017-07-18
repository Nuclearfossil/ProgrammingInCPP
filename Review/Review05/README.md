# Review 05 - Where we talk about memory

Throughout these tutorials, I've purposely shyed away from talking about memory as much as I possibly can,
doing a fair bit of hand-waving, talking about the size of structures, but avoiding talking about actual
allocation of things in C++.  In this review, I'm going to cover the intricacies of memory and memory management
in C++.

## Previously ...

Let's take a look at the 'boilerplate' code I have set up for a `main.cpp` file:

``` C++
enum Executables
{
    ex01 = 0,
    ex02,
    endoflist
};

void main()
{
    Executables toRun = ex02;

    switch (toRun)
    {
    case ex01:
    {
        break;
    }

    case ex02:
    {
        break;
    }

    default:
        break;
    }
}
```

I'm actually allocating memory in this code snippet. Where? Every time I allocate a variable. So `toRun` is
allocated, on the stack. It's done automatically for me byt the compiler.

But you hear all the time about C/C++ and memory leaks. Am I leaking memory here? How do I fix it?

Well, we're not leaking anything because of two things:

 1. The allocation is happening on the stack
 2. C/C++ scoping rules

When we allocate memory, we can allocate it from two places: the "stack" and the "heap". Every function that
you call creates it's own 'stack' memory space where it stores variables local to that function. It also stores
arguments passed in, and out of, the function during the invocation of said function.

We allocate memory from the heap via the `malloc`, `new` functions (and their variants). Anything we allocate from 
the heap, we eventually have to reclaim via `free` and `delete`, otherwise we end up with a memory leak. More on
that shortly.

We also need to talk about scoping rules. We've already seen C++ keywords that help with defining the scope of a
variable, when we looked at the `extern` keyword in "Review04". Remember, that allowed us to tell the compiler/linker
that the variable was declared elsewhere and the linker would resolve it. Let's talk more about this.  In "Review04", 
the allegro font variable we used (`extern ALLEGRO_FONT* gFont;`) was arguably a 'global' variable; with the right
keywords, you can access that variable anywhere in your application, in any file.

Does the same hold true for the variable `toRun` in the above example? No, it does not. There is no equivalent of
`main.toRun` that you can use to access that variable.  So this:

``` C++
enum Executables
{
    ex01 = 0,
    ex02,
    endoflist
};

void main()
{
    Executables toRun = ex02;

    switch (toRun)
    {
    case ex01:
    {
        break;
    }

    case ex02:
    {
        break;
    }

    default:
        break;
    }
}

void foo()
{
	main.toRun = ex01; // compile error
}
```

Fails to compile.

However, moving it out of `main()` promotes it to a more 'global' scope:

``` C++
enum Executables
{
    ex01 = 0,
    ex02,
    endoflist
};

Executables gToRun;

void main()
{
    gToRun = gToRun;

    switch (gToRun)
    {
    case ex01:
    {
        break;
    }

    case ex02:
    {
        break;
    }

    default:
        break;
    }
}

void foo()
{
	gToRun = ex01; // compiles fine
}

```

## Scoping points

Let's say we have a function with a loop:

``` C++
void foo()
{
	for (int index = 0; index < 10; index++)
	{
	    printf("%i\n", index);
	}
	
	printf("%i\n", index);
}    

```

What do you think the output from that will be?


Trick question! It doesn't actually compile. Specifically with this error:

``` prompt
 In function 'void foo()':
43:17: error: 'index' was not declared in this scope
```

That error refers to:

``` C++
void foo()
{
	for (int index = 0; index < 10; index++)
	{
	    printf("%i\n", index);
	}
	
	printf("%i\n", index);   // <<== error here
}    
```

The compiler can't find `index` because it is only scoped to the `for` loop - initializing the 
variable `index` inside the `for` loop automatically enforces the scope.

A quick change fixes this:
``` C++
void foo()
{
	int index = 0;
	for (; index < 10; index++)
	{
	    printf("%i\n", index);
	}
	
	printf("%i\n", index);   // <<== error here
}    
```

But is that a change for the better? Depends on your needs. Initializing the `index` variable inside
the `for` loop automatically enforces cleanup of that variable; you don't have to worry about accidentally
reusing that variable. That's a good thing, IMO. You can now legally do the following:

``` C++
void foo()
{
	for (int index = 0; index < 10; index++)
	{
	    printf("%i\n", index);
	}

	// do other stuff

	for (int index = 5; index < 10; index++)
	{
	    // do something else here
	}
}    
```

You can actually enforce deeper scoping of variables using the curly braces:

``` C++
void foo()
{
    {
        int innerScope = 10;
        printf("innerScope: %d\n", innerScope);
    }
    
    {
        int innerScope = 20;
        printf("innerScope: %d\n", innerScope);
    }
}    
```

Each `innerScope` is scoped between it's curly braces. The following:

``` C++
void foo()
{
    {
        int innerScope = 10;
        printf("innerScope: %d\n", innerScope);
    }
    
    {
        int innerScope = 20;
        printf("innerScope: %d\n", innerScope);
    }
    
    printf("innerScope: %d\n", innerScope); // <<== error: 'innerScope' was not declared in this scope
}    
```

Fails with the error "'innerScope' was not declared in this scope".

So, what happens if we declare `innerScope` at the top of the function?

``` C++
void foo()
{
    int innerScope = 5;
    {
        int innerScope = 10;
        printf("innerScope: %d\n", innerScope);
    }
    
    {
        int innerScope = 20;
        printf("innerScope: %d\n", innerScope);
    }
    
    printf("innerScope: %d\n", innerScope);
}    
```

The results are:

``` prompt
innerScope: 10
innerScope: 20
innerScope: 5
```

Simply put, local scope overrides the parent scope.  Let's say you wanted to access the 'parent' scope of the variable `innerScope`.
We can use the "scope resoloution operator" to do that - it's the `::` operator. However, it is not applicable to the curly brace
scoping cheat.  An example helps clarify this:

``` C++
int innerScope = 2;
void foo()
{
    int innerScope = 5;
    {
        int innerScope = 10;
        printf("innerScope: %d\n", innerScope);
    }
    
    {
        int innerScope = 20;
        printf("innerScope: %d\n", innerScope);
        printf("outer innerScope: %d\n", ::innerScope);
    }
    
    printf("innerScope: %d\n", innerScope);
}    
```

Results in the output:

``` prompt
innerScope: 10
innerScope: 20
outer innerScope: 2
innerScope: 5
```
