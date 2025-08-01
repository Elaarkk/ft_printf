# ft_printf

````ft_printf```` is a reimplementation of the standard C ````printf```` function, developed as part of the 42 curriculum.

The following conversions are implemented:

    %c – character

    %s – string

    %p – pointer (printed in hexadecimal with 0x prefix)

    %d - decimal (base 10)
    
    %i – integer (base 10)

    %u – unsigned decimal integer (base 10)

    %x – lowercase hexadecimal (base 16)

    %X – uppercase hexadecimal (base 16)

    %% – percent sign
## Installation & Usage

This is not a standalone program, you need to compile it with your own source code.

Run ````make```` to compile the library:

```bash
make
```

Compile with the library:

```bash
gcc main.c ft_printf.a -o my_program

