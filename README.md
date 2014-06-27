Three.cpp
=========

A port of Three.js into C++


Overview
========
This is an effort to port Three.js to OpenGL. The main idea is not to create the fastest 3D engine out there, but to create a 3D engine that's simple enough to instantiate, so that other field of computing could use it rapidly for prototyping. Thus reducing the unnecessary hoops for OpenGL newcomers when it comes to thing such as context creation, loading shaders, etc.

I'm not a 3D programmer, I wanted to have a 3D library that I can use to show the results of SLAM / PTAM or Bundle Adjustment, while most sample codes out there use pre OpenGL 3.0 for visualization, and most of them implement their own 3D viewers.

Current Progress
================
Still very early, nothing can be shown yet, some of the math-related classes have already been implemented.


3rd party libraries to be used
=============================
* glm (http://glm.g-truc.net/0.9.5/index.html) : for 3d math libraries. It's used because it's very close to GLSL, and writing my own library means that it's prone to bugs and slowdowns

* glfw (http://www.glfw.org): library for creating windows with OpenGL context

* googletest (https://code.google.com/p/googletest/) : for unit testing, I'm trying to avoid boost, because it's such a kitchen sink.

* three.js (http://threejs.org): as the original library to be ported from. The main reason, is that three.js, as a WebGL library, has a fairly simple and clean implementation.


Installation
============
* Use homebrew(http://brew.sh) to install glm and glfw libraries. 
* If you need to create the unit tests, googletest has a documentation to show you how to compile the library


Guidelines
=============
* Try to keep codes clean, simple and readable. Richard Feynman once said that for any topic to be considered as properly understood, it must be explainable to and understable by college freshmen.
* It's 2014, variables named like dxdylam can be quickly and easily renamed in the scope to dx_dy_div_lambda. Keep it readable
* Make it run correctly first, optimization can come later.
* Object oriented, it's okay to take some performance hit, for the sake of readability and ease of extension.

FAQ
===
* Why those 3rd party libraries?
I played with those before, so it's better for me to use something that I already know. I want to have something that's simpler and direct, not an end product that new users would need to spent hours wrangling with where to install the libraries, what should be included, how to compile with libc++ instead of libstdc++, etc.

* Can I contribute?
Please do so, I'm not super programmer, any help is welcomed.

* Why are these codes so unoptimized?
I'm fairly average programmer, experienced, but not super programmer. Plus, it's in the early phase, I'd like to go for optimization later on.

* Why is it OS X centric (e.g. XCode, Homebrew, etc)?
I only own a Macbook Air.

