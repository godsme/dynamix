DynaMix
===========

[![Language](https://img.shields.io/badge/language-C++-blue.svg)](https://isocpp.org/) [![Standard](https://img.shields.io/badge/C%2B%2B-11-blue.svg)](https://en.wikipedia.org/wiki/C%2B%2B#Standardization) [![License](https://img.shields.io/badge/license-MIT-blue.svg)](https://opensource.org/licenses/MIT)

[![Travis CI](https://travis-ci.org/iboB/dynamix.svg?branch=master)](https://travis-ci.org/iboB/dynamix) [![AppVeyor](https://ci.appveyor.com/api/projects/status/02qjl0v3np4boo46?svg=true)](https://ci.appveyor.com/project/iboB/dynamix)



DynaMix (Dynamic Mixins) is a new take on polymorphism. It allows the composition and modification of polymorphic types at run time in C++. 

The library is a means to create a project's architecture rather than achieve its purpose.

DynaMix can be of great help for the software architecture of system with very complex objects like games (especially role-playing ones or strategies), CAD systems, enterprise systems, UI libraries, and more.

The library uses the type `dynamix::object` as a placeholder, whose
instances can be extended with existing classes (mixins), thus providing
a particular instance with the functionality of all those types. Accessing the
newly formed type's interface is made through messages -- stand-alone functions
generated by the library, which can be thought of as methods.

Here is a small example of what your code may look like if you use the library:

```c++
    // assuming my_objects.get_ally(0); is a way to get an ally to the
    // main character in a game
    dynamix::object& obj = my_objects.get_ally(0);

    // now let's make the object think some positive thoughts about the
    // main character

    think(obj); // C++ doesn't allow us to have obj.think().
                // DynaMix's messages are standalone functions

    // type composition
    dynamix::mutate(obj)
        .add<flying_creature>();

    // object can now respond to fly()

    fly(obj); // ...instead of obj.fly()

    // type mutation
    dynamix::mutate(obj)
        .remove<ally>()
        .add<enemy>();

    think(obj); // the same object now thinks negative thoughts about the main
                // character, since it's no longer an ally, but an enemy
```

Here is a list of features of the library:

* Compose types from mixins at run time
* Physically separate interface and implementation
* Non-intrusive -- mixins don't need to have a common parent or any special code
inside
* Mutate "live" objects by changing their composition at run time
* Have multicast messages, which are handled by many mixins within an object
* Possibility to have custom allocators to finely tune the memory and aim for
cache-locality for critical parts of the code
* Ability to have dynamic libraries that can enrich or modify objects, without
modifying (or even rebuilding) the executable.
* Thread safe message calls - as thread safe as the underlying methods.

## Documentation

The full documentation is available at the [GitHub page of the library](https://ibob.github.io/dynamix/)

## License

This software is distributed under the MIT Software License
See accompanying file LICENSE.txt or copy [here](https://opensource.org/licenses/MIT).

Copyright &copy; 2013-2016 [Borislav Stanimirov](http://github.com/iboB), [Zahary Karadjov](http://github.com/zah)

## Boost.Mixin

DynaMix was initially developed as [Boost.Mixin](https://github.com/iboB/boost.mixin) but is now a separate library, that doesn't depend on the Boost libraries Collection.

DynaMix, unlike Boost.Mixin, has no C++98 support. It's C++11 only.

DynaMix is distributed under the MIT license, whereas Boost.Mixin is distributed under the Boost Software License. 

