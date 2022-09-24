#include <stdio.h>

#include "chalk.h"
#define CHALK_H_IMPLEMENTATION_

int main(void)
{
	printf("\n\n");
	printf("\t%s %s %s %s %s %s %s\n", chalk_bold("bold"), chalk_dim("dim"), chalk_italic("italic"), chalk_underline("underline"), chalk_inverse("inverse"), chalk_strikethrough("strikethrough"), chalk_black("black"));
	printf("\t%s %s %s %s %s %s %s %s %s\n", chalk_red("red"), chalk_green("green"), chalk_yellow("yellow"), chalk_blue("blue"), chalk_magenta("magenta"), chalk_cyan("cyan"), chalk_white("white"), chalk_gray("gray"), chalk_bgBlack("bgBlack"));
	printf("\t%s %s %s %s %s %s %s\n", chalk_bgRed("bgRed"), chalk_bgGreen("bgGreen"), chalk_bgYellow("bgYellow"), chalk_bgBlue("bgBlue"), chalk_bgMagenta("bgMagenta"), chalk_bgCyan("bgCyan"), chalk_bgWhite("bgWhite"));
	printf("\t%s\n", chalk("chalk() test string", COLOR_YELLOW | COLOR_BOLD | COLOR_UNDERLINE));
	printf("\n\n");
	return 0;
}

