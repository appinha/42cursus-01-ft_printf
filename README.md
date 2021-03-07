<h1 align="center">
	42cursus' ft_printf
</h1>

<p align="center">
	<b><i>Development repo for 42cursus' ft_printf project</i></b><br>
	For further information about 42cursus and its projects, please refer to <a href="https://github.com/appinha/42cursus"><b>42cursus repo</b></a>.
</p>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/appinha/42cursus-01-ft_printf?color=blueviolet" />
	<img alt="Number of lines of code" src="https://img.shields.io/tokei/lines/github/appinha/42cursus-01-ft_printf?color=blueviolet" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/appinha/42cursus-01-ft_printf?color=blue" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/appinha/42cursus-01-ft_printf?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/appinha/42cursus-01-ft_printf?color=brightgreen" />
</p>

<h3 align="center">
	<a href="#%EF%B8%8F-about">About</a>
	<span> · </span>
	<a href="#-index">Index</a>
	<span> · </span>
	<a href="#%EF%B8%8F-usage">Usage</a>
	<span> · </span>
	<a href="#-testing">Testing</a>
	<span> · </span>
	<a href="#-useful-links">Useful Links</a>
</h3>

---

## 🗣️ About

> _This project is pretty straight forward. You will recode printf. Hopefully you will be able to reuse it in future project without the fear of being flagged as a cheater. You will mainly learn how to use variadic arguments._

For detailed information, refer to the [**subject of this project**](https://github.com/appinha/42cursus/tree/master/_PDFs).

	🚀 TLDR: this project consists of coding a library that contains a simplified version (more
	information below) of the printf function.

### Mandatory

* **format specifiers** - `cspdiuxX%`
* **flags** - `-0.*` and minimum field width with all conversions

### Bonus

* **format specifiers** - `nfge` (one or more)
* **flags** - `l ll h hh` (one or more) and `# +` (all)

## 📑 Index

`@root`

* [**📁 ft_printf:**](ft_printf/) source code developed for the project.
* [**📁 testing:**](testing/) my own testing program.

`@/ft_printf/`

_Note: files contain both mandatory and all bonus requirements._

**Functions in `ft_printf.c`**

* `ft_printf` (and auxiliary static functions) - Initialization function: start/end variadic arguments functions `<stdarg.h>`; in between that, goes through the input string printing plain characters or collecting + treating format specifiers to the FORMAT SPECIFIER STRUCT thus printing each occurrance with the corresponding function.

**Functions in `ft_printf_flags.c`**

* `print_flags` (and auxiliary static functions) - Prints each format specifier function's outputted string with formatting in accordance with the collected format specifiers.

**Functions in `ft_printf_csp_pct.c`**

The following functions output the input variable (collected by `va_arg` function) as a pointer to a string to be printed by the `print_flags` function.

* `print_spec_c`	- **character** (`%c`) type input variable;
* `print_spec_s`	- **string** (`%s`) type input variable;
* `print_spec_pct`	- **percent** (`%%`) character.

**Functions in `ft_printf_iduxo.c`**

The following functions output the input variable (collected by `va_arg` function) as a pointer to a string to be printed by the `print_flags` function.

* `print_spec_i_d_u`	- **int** (`%i` and `%d`) and **unsigned int** (`%u`)type input variables;
* `print_spec_x`		- **lower** (`%x`) and **upper hexadecimal** (`%X`) type input variables;
* `print_spec_o`		- **octal** (`%o`) type input variable;
* `print_spec_p`		- **pointer** (`%p`) type input variable.

**Functions in `ft_printf_f_g.c`**

The following functions output the input variable (collected by `va_arg` function) as a pointer to a string to be printed by the `print_flags` function.

* `print_spec_f_e_g`	- triage for **float** (`%f`), **scientific notation** (`%e`) and **general format** (`%g`) type input variables;
* `print_spec_f`		- **float** (`%f`) type input variable;
* `print_spec_g`		- **general format** (`%g`) type input variable.

**Functions in `ft_printf_f_g.c`**

The following functions output the input variable (collected by `va_arg` function) as a pointer to a string to be printed by the `print_flags` function.

* `print_spec_e` - **scientific notation** (`%e`) type input variable.

**Functions in `ft_printf_utils.c`**

Basic Libc functions - _Note: some were adapted and thus named with a suffix to indicate the nature of the customization._

* `ft_strlen`		- find length of string;
* `ft_strchr_01`	- check the occurence of a character in a string;
* `ft_putchar_len`	- writes the input character to the output stream of stdout;
* `ft_putcstr_len`	- writes the input string to the output stream of stdout;

**Functions in `ft_printf_utils_2.c`**

Basic Libc functions - _Note: some were adapted and thus named with a suffix to indicate the nature of the customization._

* `ft_strlcpy`	- copy string to another location;
* `ft_strlcat`	- concatenate strings;
* `ft_strdup`	- save a copy of a string (with malloc);
* `ft_strjoin`	- join two strings (with malloc);
* `ft_substr`	- extract a substring (with malloc).

**Functions in `ft_printf_utils_3.c`**

Basic Libc functions - _Note: some were adapted and thus named with a suffix to indicate the nature of the customization._

* `ft_pow`			- returns the value of first argument raised to the power of second argument.
* `ft_ullitoa_base`	- allocates (with malloc) and returns a string representing the integer received as an argument according to the given base.
* `ft_fmod`			- returns the modulo of the float received as an argument.

**Functions in `ft_ftoa_rnd.c`**

* `ft_ftoa_rnd` - allocates (with malloc) and returns a string representing the float received as an argument.

## 🛠️ Usage

### Requirements

The library is written in C language and thus needs the **`gcc` compiler** and some standard **C libraries** to run.

### Instructions

**1. Compiling the library**

To compile the library, run:

```shell
$ cd path/to/ft_printf && make
```

**2. Using it in your code**

To use the library functions in your code, simply include its header:

```C
#include "ft_printf.h"
```

and, when compiling your code, add the required flags:

```shell
-lftprintf -L path/to/libftprintf.a -I path/to/ft_printf.h
```

## 📋 Testing

**1. First, configure the path to the ft_printf folder in the Makefile (inside `/testing/`):**

```Makefile
PROJECT_DIR	= ../ft_printf/
```

**2. Then run:**

```shell
make
```

### Third-party testers

* [gavinfielder/pft](https://github.com/gavinfielder/pft)
* [Mazoise/42TESTERS-PRINTF](https://github.com/Mazoise/42TESTERS-PRINTF)
* [HappyTramp/ft_printf_test](https://github.com/HappyTramp/ft_printf_test)
* [t0mm4rx/ftprintfdestructor](https://github.com/t0mm4rx/ftprintfdestructor)
* [charMstr/printf_lover_v2](https://github.com/charMstr/printf_lover_v2)

## 📌 Useful Links

* [C++ Reference - printf](http://www.cplusplus.com/reference/cstdio/printf/)
* [Article: Secrets of “printf” (PDF)](https://www.cypress.com/file/54441/download)
* [MacOS documentation - printf](https://opensource.apple.com/source/xnu/xnu-201/osfmk/kern/printf.c.auto.html)
* [IEEE-754 Floating Point Converter](https://www.h-schmidt.net/FloatConverter/IEEE754.html)
* [How does one print floats for ft_printf? - Stack Overflow - 42 Network](https://stackoverflow.com/c/42network/questions/133/134#134)
* [Printing Floating-Point Numbers](http://www.ryanjuckett.com/programming/printing-floating-point-numbers/)
* [Printing Floating-Point Numbers Quickly and Accurately with Integers](https://www.cs.tufts.edu/~nr/cs257/archive/florian-loitsch/printf.pdf)
* [What precisely does the %g printf specifier mean? - Stack Overflow](https://stackoverflow.com/questions/54162152/what-precisely-does-the-g-printf-specifier-mean)
