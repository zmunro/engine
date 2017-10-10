# Instructions

## Build Box2D

Box2D comes with a graphical test environment called the Testbed.
It depends on a few libraries, which on Debian based Linux distributions can be
installed with

    $ sudo apt install libglu1-mesa-dev freeglut3-dev libxcursor-dev libxrandr-dev libxinerama-dev

I don't have a machine to test this on but I believe that the equivalents for other OS's are:

 - Windows: "GLEW", "glu32", "opengl32", "winmm"
 - macOS:   "OpenGL.framework", "Cocoa.framework", "IOKit.framework", "CoreFoundation.framework", "CoreVideo.framework"

However the makefile specified will likely not just "work" after installing those programs. A different makefile needs to be generated
by running gmake again as in commit 406315c55ea43379. Then the same changes introduced between that commit and 7a03ad0593c2213e should
be made to the generated makefiles, as these changes are what allow us to add our own visual tests. 

If you are running Windows or macOS you're encouraged to do this! That way we can establish a functional working environment for all.
Also, if you're on Windows you will have to do many strange things involving MingW and Cygwin in order to have GNU make in the first place.

Anyway after installing the dependencies, run

    $ cd Box2D/Box2D/Build/make
    $ make

Finally, to run the Testbed:

    $ cd ../../Testbed/
    $ ../Build/gmake/bin/Debug/Testbed 

(It has to be run from there because of a ttf font that has a relative path)

The dependencies are only for the Testbed. If you just want to build Box2D and work on the engine then you run the same make command
and ignore all the errors. Box2D should build successfully anyways.

## Build the engine

To compile and link the engine files, cd to `engine` and run `make`. You need to have built Box2D (but not the Testbed) previously for this to work.

If you add some new functionality and want to add a visual test for it, write a new file in Testbed/Tests called "MyTest.h", for example, and build Box2D again.
Run the Testbed as described above and you should see your test in the dropdown menu.
