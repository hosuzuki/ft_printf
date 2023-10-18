# ft_printf
<br>

## 🌕 What is ft_printf ?

ft_printf is an individual project at [42 Tokyo][1] to recode printf and add it to the libft.

<br>

The versatility of the printf function in C allows us to discover a feature of the C language – variadic functions – and to practice detailed management of the printing options.

### 🌖 Prototype
The function to implement is called ``ft_printf``, and will have the following prototype:
```C
int	ft_printf(const char *fmt, ...);
```

It will manage the following conversions: ``c s p d i u x X %``

Conversions:
```
%                   (% character)
c    char           (character)
s    char *         (string)
p    void *         (pointer's address)
u    unsigned int   (unsigned decimal integer)
x/X: unsigned int   (hexadecimal)
d/i: int            (integer)
```
My ft_printf manages any combination of the following flags: ``-0.*`` and minimum field width with all conversions.

Placeholders: 

``
%[Flags][Width][.Precision][Length]<type>
``

**Flags:**
```
-       Left alignment (default rigth aligned)
0       Field is padded with 0's instead of space
.       Precision
*       The width or precision is not specified in the format string, but as an additional integer value argument (given by the next va_arg)
(space) A blank space is added provided that no sign is specified
+       Add a plus sign in front of positive numbers
```
**Width:** Minumum number of characters to output (pads if necessary)

**Precision:** Maximum limit of characters to output (rounds if necessary)

<br><br>

## 🌕 Usage

### 🌖 Requirements

The function is written in C language and thus needs the **`gcc` compiler** and some standard **C libraries** to run.
<br><br>

### 🌖 Instructions

#### 🌗 Give it a try (use main.c in test directory)

##### 🌘 1. Clone the repository
```shell
git clone git@github.com:hosuzuki/ft_printf.git
```

And them, move to the cloned directory.
```shell
cd ft_printf
```

##### 🌘 2. Clone the libft repository(submodule)

First, initialize the local configuration file using ``git submodule init`` and then obtain data from the project using ``git submodule update``.

```shell
git submodule init
git submodule update
```

##### 🌘 3. Compile libftprintf.a with main.c which has test code

First, move to test directory.
```shell
cd test
```

And them, run ``make`` command.
```shell
make
```

Makefile compiles all files from the ``src/`` folders and saves the object files to the ``objs/`` folders. <br>
It then generates the output file ``libftprintf.a`` in the root directory.

Additionally, the Makefile generates ``diff.txt`` in the test directory, which displays the comparison results between the printf function and the ft_printf function.
<br><br>


#### 🌗 Using it in your code (use your main.c)

To use the function in your code, simply include its header:

```C
#include "ft_printf.h"
```

and, when compiling your code, add source files:

```shell
gcc main.c libftprintf.a
```

[1]: https://42tokyo.jp/
