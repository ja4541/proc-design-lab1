# proc-design-lab1
cmake Version: 4.1.1

## make help

The following are some of the valid targets for this Makefile:
* all (the default if no target is provided)
* clean
* depend
* codegen
* edit_cache
* rebuild_cache
* hello_world
* hello.o
* hello.i
* hello.s

## What the targets almost certainly mean 

### all
The default target when you run make with no arguments.

Usually depends on the main build product(s). In this project it most likely builds hello_world (the executable) and any required object files.

### clean

Removes build artifacts (so you get a clean directory).

Typically deletes: object files (*.o), intermediate files (*.s, *.i), the executable (e.g. hello_world), possibly dependency files (e.g. *.d) and any generated caches or temporary directories.

### depend

Generates or updates dependency files for the compiler (e.g. .d files). Used so make knows which sources need recompiling when headers change.

### codegen

Runs a code generator step. Likely produces generated .c/.h or other source files used by the build. Project-specific — could run a script that emits C/assembly/source used later in the build.

### edit_cache

Project-specific. Name suggests an action to edit a cached configuration or compilation cache (for example, edit a config.cache or similar). Could open an editor on a cache file or invoke a script that changes cache values.

### rebuild_cache

Recreate or refresh whatever cache the project uses (re-run code/config/compilation caching steps). Could remove old cache and regenerate artifacts that speed builds.

## The hello* targets — what they produce

These follow a very common pattern for C/C++ toolchains:

### hello_world

Likely the final executable. Usually produced by linking hello.o (and any other object files) together: e.g. gcc hello.o -o hello_world.

### hello.o

An object file. Produced by compiling the source (e.g. hello.c) with a compile step such as gcc -c hello.c -o hello.o.

### hello.i

The preprocessed C source file. Produced by running the C preprocessor only (e.g. gcc -E hello.c -o hello.i). It contains the source after #include expansion and macro substitution.

### hello.s

The assembly output. Produced by compiling to assembly (e.g. gcc -S hello.c -o hello.s). It’s human-readable assembly generated from hello.c.

So the typical flow is:

hello.c —(preprocess)→ hello.i —(compile to asm)→ hello.s —(assemble)→ hello.o —(link)→ hello_world

But most make rules skip some intermediate files; these targets explicitly expose them so you can request them individually.

## Answer the following:

### The paths used by target_sources and target_include_directories are relative, not absolute. What file or folder are they relative to?
They’re relative to the location of the CMakeLists.txt file where the commands are written.
### What are some differences between cmake and ninja?
CMake = planner (decides what needs to be built and generates build instructions).

Ninja = worker (executes those instructions quickly).
### Why is it important to run cmake in its own directory?
We want to run cmake in its own directory so that the generated files don’t pollute our source code folder