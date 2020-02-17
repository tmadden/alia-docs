alia
====

<div class="hide-when-deployed">

[![image](https://img.shields.io/travis/tmadden/alia/master.svg?style=flat&logo=travis-ci&logoColor=white)](https://travis-ci.org/tmadden/alia/branches)
[![image](https://img.shields.io/appveyor/ci/tmadden/alia/master.svg?style=flat&logo=appveyor&logoColor=white)](https://ci.appveyor.com/project/tmadden/alia/branch/master)
[![image](https://img.shields.io/codecov/c/github/tmadden/alia/master.svg?style=flat&logo=codecov&logoColor=white)](https://codecov.io/gh/tmadden/alia/branch/master)
![image](https://img.shields.io/badge/C++-14-green.svg?style=flat&logo=c%2B%2B)
[![image](https://img.shields.io/badge/stability-unstable-yellow.svg?style=flat)](https://github.com/orangemug/stability-badges#unstable)

</div>

**WARNING**: This project is in an unstable, pre-release state. There
are missing links, missing documentation pages, missing features, and
APIs that may change in the future. That said, what's there now should
work well, so if you're interested in playing around with it, I welcome
any feedback or contributions!

alia (pronounced uh-LEE-uh) is a modern C++ library for developing reactive
applications. It provides a core of generic facilities for reactive programming
and is designed to hook up to other, more traditional libraries and allow them
to be used in a reactive manner. In particular, alia features:

* **data-backed control flow** - alia provides mechanisms for tracking your
  control flow so that you can stably associate arbitrary data objects with
  specific points in your application's reactive presentation logic.

  In alia, rather than explicitly managing trees of presentation objects, you
  compose your application as a tree of function calls, each of which is capable
  of managing its own object(s) internally. At any point in time, the tree of
  presentation objects naturally reflects whatever the function calls specify.

* **dataflow semantics** - alia provides tools for modeling the computations in
  your application as a dataflow that implicitly supports the reality that
  function inputs are often not immediately available (because they are waiting
  for user inputs, background calculations, remote queries, etc.).

alia also provides a whole suite of supporting features that help keep these
concepts practical in real-world applications: efficient change detection for
program state, efficient routing of events, declarative event handlers, etc.

<div class="hide-when-deployed">

Check out [the documentation](https://tmadden.github.io/alia) for more info.

</div>

A Quick Example
---------------

Below is a simple interactive "Hello, World!" example that uses an experimental
[asm-dom](https://github.com/mbasso/asm-dom) wrapper. To see it in action and
read more about it, <a target="_self"
href="https://tmadden.github.io/alia/#/reactive-hello">click here</a>.

```cpp
void
do_greeting_ui(dom::context ctx, bidirectional<string> name)
{
    dom::do_text(ctx, "What's your name?");

    // Allow the user to input their name.
    dom::do_input(ctx, name);

    // If we have a name, greet the user.
    alia_if(name != "")
    {
        dom::do_text(ctx, "Hello, " + name + "!");
    }
    alia_end
}
```

Other assorted examples are available <a target="_self"
href="https://tmadden.github.io/alia/#/assorted-examples">here</a>.

Project Status
--------------

alia is the result of more than a decade of development and evolution. It began
life as an immediate mode GUI library like [Dear
ImGui](https://github.com/ocornut/imgui). This 'IMGUI' form of alia has been
used in multiple generations of major in-house projects and commercial
collaborations, and the core reactive mechanics of alia have proven themselves
in those environments.

This open-source version of alia is a relatively minor evolutionary improvement
on those core mechanics (with far better testing and documentation). The only
revolutionary change in this version is the decision to ditch the actual GUI
code (which other libraries do better anyway) in favor of focusing on those core
mechanics.

This new direction for alia means that it no longer actually *does* anything out
of the box. It needs to be integrated with other libraries that do things. While
alia's mechanics are perfectly capable of supporting this, this is a new
direction and new work to be done.

At the moment, I provide experimental/example integrations with asm-dom and Qt,
but I'm still in the process of developing realistic integrations for my own
purposes, and I have no immediate plans of providing "official" integrations for
any external libraries.

**So at this point, if you're interested in using alia in a real project, it
will require some work on your part to hook it up to the libraries you need for
user interfaces, rendering, etc.** I provide guidance and examples on how to do
this, and in my experience, it's relatively fun and straightforward work, but it
still needs to be done.

And if you're interested in sharing your integrations, I'm more than happy to
incorporate them as examples and/or link people to your projects.

Getting Started
---------------

Continue on to <a target="_self"
href="https://tmadden.github.io/alia/#/reactive-hello">the full
documentation</a> for more info.