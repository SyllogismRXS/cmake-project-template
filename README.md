cmake project template
================

Starting point for any C++ CMake Project 

Instructions and Notes:

1.) To build the project, just execute the build.sh script:

$ ./build.sh

2.) You can run executables that are created in the bin directory by appending
    the executable call to the end of the build.sh call, like this:

$ ./build.sh ./hello-world

3.) You may want to change the project name in the main CMakeLists.txt file.
    Just run a find and replace on the strings "syllo" and "SYLLO" with the
    name of your new project.

4.) You can also use the ./clean.sh script to clean the entire project before
    commiting your changes and pushing them to the server repo.


