# Pointers in C++

## Summary

This is a review of sorts, but I'm going to dig much deeper into memory specifics of the
C family of languages. Thus I felt it was far more worthwhile to break it into it's own
group of projects.

For the most part, I'll be sticking with Visual Studio, rather than the C++ shell for the
code samples; we want to be looking at memory and Visual Studio has much better tools for
that.

With that said, I forsee the majority of these projects being console applications. I want
these to potentially be portable fairly easily to other compilers/OSes. Making them Windows
applications will hamper that. I also will be avoiding using Allegro this time around as
I want to keep us focused on memory and pointers.

## Why are we looking at pointers?

If you come from other languages like C#, Java, Python, you really haven't had to worry a lot
about memory, from a truly lower level standpoint. However, with C++, you _will_ be very
interested in what's happening with memory.

Why's that? It's pretty simple, actually: 

> C++ if horrifically bad at dealing with memory.

_What??_

If you come from any of those other languages, you will, without a doubt, believe that what
I've just written is the gospel. So why is that?

Let's look at an incredibly simple C# example:

``` C#
using System;
					
public class Program
{
	public class Shape
	{
		public Shape()
		{
			Console.WriteLine("  -> Shape Constructor");
		}
		
		~Shape()
		{
			Console.WriteLine("  -> Shape Destructor");
		}
		
		public void Draw()
		{
			Console.WriteLine("  -> Shape Draw");
		}
	}
	
	public static void Main()
	{
		Shape A = new Shape();
	}
}
```

[.Net Fiddle version](https://dotnetfiddle.net/knmGE4)

How much are we leaking there? If you said 'none', you're correct. C# will automatically Garbage collect
`A` when it's no longer being used.

The same thing in C++?

``` C++
// Example program
#include <stdio.h>

class Shape
{
public:
    Shape()
    {
        printf("  -> Shape Constructor\n");
    }

    ~Shape()
    {
        printf("  -> Shape Destructort\n");
    }

    void Draw()
    {
        printf("  -> Drawing a shape\n");
    }
};

int main()
{
    Shape* A = new Shape();
}
```

[C++ shell](cpp.sh/7nyr)

How much are we leaking there? I'll give it to you in a percentage: 100% leaky.

Yes, fixing that would be trivial; just add a `delete A`; before main finishes. But that's
no magic bullet. Let me show you something:

``` C++
// Example program
#include <stdio.h>

class Shape
{
public:
    Shape()
    {
        printf("  -> Shape Constructor\n");
    }

    ~Shape()
    {
        printf("  -> Shape Destructort\n");
    }

    void Draw()
    {
        printf("  -> Drawing a shape\n");
    }
};

int main()
{
    Shape* A = new Shape();
    Shape* B = A;
    
    A->Draw();
    B->Draw();
    delete A;
    
    B->Draw();
}
```

What happens there?

[C++ shell](cpp.sh/7womq)

output:

``` prompt
  -> Shape Constructor
  -> Drawing a shape
  -> Drawing a shape
  -> Shape Destructort
  -> Drawing a shape
```

Looks good to me! Next!

Suddenly, a stranger appears next to you, eyeing your computer

"Whoa up there pardner! I think you've got some cattle rustler's in your code there"

Startled, you sit upright in your chair. You could have sworn you locked the front door.
Heart racing, you stammer a shocked response.

"Who the hell are you?"

"Why, I'm the Allocator Kidd. And I think your memory's being rustled up but good! Do y'mind
if'n I take the reigns there?"

He pulls off his leather cowboy gloves, revealing weathered, leathery hands, with millimeter thick
callusses cover the tips of each finger, undoubtably from years of being a keyboard jockey in
the wild west.

You stand up, tenatively offering your chair. With a sly grin he nods, taking a seat, roughly
pulling the keyboard into his lap. With a side glance he looks at your lighted mouse and
mutters to himself

"A mouse. How _quaint_"

He writes two lines of code, smiles and becons you to look at what he's written.

``` C++
int main()
{
    Shape* A = new Shape();
    Shape* B = A;
 
    printf("How big is a Shape? %lu\n", sizeof(A));
    printf("Is that really how big a Shape is? %lu\n", sizeof(*A));
    
    A->Draw();
    B->Draw();
    delete A;
    // ...
```

``` prompt
  -> Shape Constructor
How big is a Shape? 8
Is that really how big a Shape is? 1
  -> Drawing a shape
  -> Drawing a shape
  -> Shape Destructort
  -> Drawing a shape
```

"So, what do you think about them apples, Pardner?"

Looking at the code, you come to realize that asking for the `sizeof(A)` is really only asking
for the size of the pointer for an instance of a `Shape` object. It makes sense for any pointer
on a 64 bit system to be 8 (8*8 = 64 after all).

But why does the `sizeof(*A)` give you a result of 1?

Well, first off, remember that the use of the `*` symbole acts as a 'de-reference' operation.
It essentially takes a pointer and returns the contents at that location, according to the type
of the object it's a pointer of. So it's saying that the Class `Shape` is only ... one byte big?

Is that the case?  You motion to the Data Cowboy to vacate the chair so you can add the following
to the code:

``` C++
    printf("How big is a Shape? %lu\n", sizeof(A));
    printf("Is that really how big a Shape is? %lu\n", sizeof(*A));
    printf("So what is the size of a Shape, really? %lu\n", sizeof(Shape));
```

And the results?

``` prompt
  -> Shape Constructor
How big is a Shape? 8
Is that really how big a Shape is? 1
So what is the size of a Shape, really? 1
  -> Drawing a shape
  -> Drawing a shape
  -> Shape Destructort
  -> Drawing a shape
```

But that can't be right! How can a class only be one byte big.

Our Digital Cowpoke sees the look of consternation on your face, motions to the keyboard and 
begins to type as you move to the side. He adds a bit of code to the bottom of the `Shape` class and
and re-runs the code

``` C++
    void Draw()
    {
        printf("  -> Drawing a shape with text: [%s]\n", value);
    }

    char value[256];
};

int main()
{
    Shape* A = new Shape();
    Shape* B = A;
    strcpy(A->value, "Here is some text");
    printf("How big is a Shape? %lu\n", sizeof(A));
    printf("Is that really how big a Shape is? %lu\n", sizeof(*A));
    printf("So what is the size of a Shape, really? %lu\n", sizeof(Shape));
    
    A->Draw();
    B->Draw();
    
    delete A;
    memset(A, 0, sizeof(Shape));  // Mimicing someone else re-using the memory that was just freed
    
    B->Draw();
}
```

``` prompt
  -> Shape Constructor
How big is a Shape? 8
Is that really how big a Shape is? 256
So what is the size of a Shape, really? 256
  -> Drawing a shape with text: [Here is some text]
  -> Drawing a shape with text: [Here is some text]
  -> Shape Destructort
  -> Drawing a shape with text: []
```

[Source](cpp.sh/6vp72)

The class had no data.

THE CLASS HAD NO DATA.

Now that it has data, we get a size that looks sane. But that doesn't explain why
`sizeof` gave us a value of 1 when there was no data present.

Hopalong Hacker can see where you're going, as he's been there before. He cracks open
your browser and feverently types in a URL he's had memorized long before you could
hold a mouse.

[In Memory of Bjarne](http://www.stroustrup.com/bs_faq2.html#sizeof-empty)

### Why is the size of an empty class not zero?

> To ensure that the addresses of two different objects will be different. For the same reason, "new" always returns pointers to distinct objects.

With that, the Marlborough Man-Of-Code tips his hat to you and disappears in a puff of AND-logic.

But there's still something off with this code.  Look at the results of calling the `Draw` method.

The problem is this: We don't have a complex enough codebase.

Let's talk about the logic of the codebase first:

 - We allocate instances of `Shape` called `A` and assign the pointer `A` to `B`.
   - This just dupicates the pointer; they just point to the same memory block.
 - We delete `A`
 - We then try to access `B` by calling the `Draw` method. And it works

It'll work because we haven't had the chance for another heap allocation to reclaim that block
of memory. But here's the kicker: Because we originally had a class with no data, *IT WOULDN'T MATTER!*

Wait ... why wouldn't it matter? We deleted the instance of the object. If we somehow managed
to reclaim that block of memory for something else ... wouldn't that be an issue?

The answer is, how could it? Remember when we measured the size of the class, it was _effectively_
zero? That's because we only measure fields in a class when allocating memory. The previous
example should have proven that to you, where we allocated a character array 256 bytes long and
we ended up seeing that the size of `Shape` was, in fact, 256 bytes.

But that makes no senes! The code has to live with the object instance, right? We create an
instance of an object and it creates an instance of the code and data. Right?

Let me ask you a question - does the code change between instances of the same class? I mean,
the data does, totally. But _does the code actually change_?

No, it doesn't.

And then, the answer is clear ... Data and Code do *not* live at the same spot in memory.

Here's something to chew on: [Anatomy of a program in memory](http://duartes.org/gustavo/blog/post/anatomy-of-a-program-in-memory/)

I really love that article. It's one of the better written pieces on the layout of a program in memory.
It doesn't answer all the questions, but it's a great start.

All your code lives in what's called the "Text Segment" of your application's process memory.
The data for your class (everything that isn't a function) lives on the Heap. So how does your
class access that data? Well, the compiler understands that there is data associated with each
class and injects into your code a `this` keyword whenever it accesses a class property.

Remember this bit of code?

``` C++
void Draw()
{
    printf("  -> Drawing a shape with text: [%s]\n", value);
}
```

That's in the `Shape` class. Well, the compiler is actually doing (no pun intended) this:

``` C++
void Draw()
{
    printf("  -> Drawing a shape with text: [%s]\n", this->value);
}
```

[Don't believe me? Here you go](cpp.sh/7tzyj)

Are we to the point yet where you think memory handling in C++ is horrific yet?

OK, so it's not actually horrific. You have a tremendous amount of control over memory in C++.
But it's not something trivial you can ignore. Understanding what's going on with memory is
incredibly important to writing good/fast/bugfree code.

## More stuff to watch out for.

Oh, we are not done yet. Not by a long shot.

In the previous example, let me ask you a question:

"Who owns the instance of shape `A`?"

I mean, consider this, from the last example:

``` C++
int main()
{
    Shape* A = new Shape();
    Shape* B = A;
    strcpy(A->value, "Here is some text");
```

What happens when we assign `A` to `B`? In languages like C#, what the 'thing' that `A` points
to has an internal reference count and it increments that when the assignment happens. And
that count gets decremented when `A` or `B` get set to null/set to something else/half a dozen
other reasons.

But what about C++?

Well, by default, C++ has no concept of ownership. Or reference counting.

Unless you add it yourself. But I'm getting way, way ahead of myself.

At this point, consider that you have to be very aware of where you allocate/assigner pointers.