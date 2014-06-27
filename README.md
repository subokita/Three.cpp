Three.cpp
=========

A port of Three.js into C++


Overview
========
This is an effort to port Three.js to OpenGL. The main idea is not to create the fastest 3D engine out there, but to create a 3D engine that's simple enough to instantiate, so that other field of computing could use it rapidly for prototyping. Thus reducing the unnecessary hoops for OpenGL newcomers when it comes to thing such as context creation, loading shaders, etc.

Current Progress
================
Still very early, nothing can be shown yet, some of the math-related classes have already been implemented.


3rd party libraries to be used
=============================
* glm (http://glm.g-truc.net/0.9.5/index.html) : for 3d math libraries. It's used because it's very close to GLSL, and writing my own library means that it's prone to bugs and slowdowns

* glfw (http://www.glfw.org): library for creating windows with OpenGL context

* three.js (http://threejs.org): as the original library to be ported from. The main reason, is that three.js, as a WebGL library, has a fairly simple and clean implementation.

FAQ
===
* Why?
