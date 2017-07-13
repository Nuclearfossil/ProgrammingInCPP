# C++ Review - Part 1

## Overview

This document and project sample set is designed to give you a refresher in the C++ programming language and build environment.
Recently, a lot of people have been asking about C++, from the perspective of other languages. As it so happens, I've spent the
last couple of years away from C++, so this could be considered my own refresher.

Additionally, I'm going to look into new language constructs/developments. I've been primarily a C++ 98 coder for the last decade,
so I figured this would also be a great opportunity to dig into new features as well.

## What the Review will cover

I've already set up a syllabus in the parent README.md file, but to re-iterate:

- Setting up the your build environment.
- Simple language tutorial.
  - Language Basics
  - Gotchas
- The process of actually building a console application.
  - Different build types (Debug, Release, Release with Debug symbols)
- Some Libraries
  - STL and STL-like libraries
  - Header only vs. Static Libs vs. DLLs

## Structure of this project

In this directory you will find a `Docs` folder. In it you will find all the relevant documentation that goes along with source code.
I will also attempt to document the codebase as completely as possible.

For the review section, I am looking for clarity rather than optimization/neat code hacks. We'll talk about that in other discussions.

## Resources

C++ is one of the older and well developed languages out there. The amount of information on the Language is staggering and humbling.
The language is also complex - I have a saying that there are only 3 types of people that claim to have a 10/10 comprehension of the language:
Members of the C++ standards committee, liars and fresh comp sci grads. On a good day, I put myself at a solid 5/10. On an average day, it's
more like 4/10. So if there is anything blatantly wrong, or mis-represented, please feel free to contact me and I'll correct it as soon as
I can.

That said, here's some resources for you to whet your palette on:

- Jason Turner's C++ Weekly Video column: https://www.youtube.com/user/lefticus1
- Learn C++.com : It's a little too textbooky, but it's been recommended): http://www.learncpp.com
- Fred: C++ Notes : I love this site : http://www.fredosaurus.com/notes-cpp/index.html
- Compiler explorer : want to see the assembly your code is generating? : https://gcc.godbolt.org
- Online C++ shell : compiler, linker, execution : http://cpp.sh
- C++ FAQ lite: Also has a Github repo as well : http://yosefk.com/c++fqa/

## About me

My name is Ash. I've been a Game programmer since 2000. I've worked at many studios, including Ubisoft Montreal and Toronto as well
as Bioware Edmonton, where I was the Technical lead on the Digital Acting group (the team responsible for all the in-game cinematics
and conversation systems). Currently I'm a Tools lead at Blackbird Interactive.