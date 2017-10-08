## Testbed install instructions

Install premake5:

    $ cd
    $ git clone https://github.com/premake/premake-core
    $ cd premake-core/
    $ git checkout v5.0.0-alpha12
    $ make -f Bootstrap.mak linux

Use it to build Box2D:

    $ cd
    $ git clone https://github.com/erincatto/Box2D
    $ cd Box2D/Box2D
    $ ~/premake-core/bin/release/premake5 gmake
    $ cd Build/gmake/

Dependencies:

    $ sudo apt install libglu1-mesa-dev freeglut3-dev libxcursor-dev libxrandr-dev libxinerama-dev
    $ make

To run the Testbed:

    $ cd ../../Testbed/
    $ ../Build/gmake/bin/Debug/Testbed 

(It has to be run from there because of a ttf font that has a relative path)

The dependencies are only for the testbed. To build Box2D without the testbed,
for example you may checkout `Box2D/` from f1c41618 and run

    $ cd Box2D
    $ make

It is a different version of Box2D but it should work fine.
Note that if you do this you will also have to edit engine/Makefile
accordingly to build the engine.
