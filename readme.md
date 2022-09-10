# chalk.h

header-only console color library for C.

> this library is inspired by [chalk](https://github.com/chalk/chalk) which was made for javascript.  
> and because I wanted a color library for C, I redesigned chalk for my use in C.

## Usage

Download the `chalk.h` file and put it anywhere you want.  
Then you can include it in your project and start coding:

```c
#include <stdio.h>
#include "chalk.h"
#define CHALK_H_IMPLEMENTATION_

int main(void)
{
    printf("%s", chalk_green("Hello World!"));
    return 0;
}
```

All functions can be found in the `test.c` file.

## Testing

The tests are written in the `test.c` file.  
They can be compiled via `make test`.

This will generate a `chalk.h-test` executable that you can run.

## Contributing

Feel free to contribute to this project or to give me your ideas.

The code I wrote is not optimized and even less for production but more for fun.

If you want to improve the code, please create a pull request with your new code.

Happy coding :)

## Support

You can get support by opening an issue (preferred) or by writing me an email to `avolgha@gmail.com`.
