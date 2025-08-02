#ifndef __TS2_H__
#define __TS2_H__
#include <stdarg.h>
#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "TS-core-miscel.h"

//////////////////////////////////////////////////////////////
// All global variables/storage are declared here.
// This is included only from ts2.c
//////////////////////////////////////////////////////////////

#define __DEBUG_TOYSTACKY__
#ifdef __DEBUG_TOYSTACKY__
void SerialPrint(const int count, ...) {
	char *str;
    va_list args;
	va_start(args, count);
	for (int i = 0; i < count; i++) {
		str = va_arg(args, char*);
		printf("%s\n", str);
	}
    va_end(args);
}
#else
void SerialPrint(const int count, ...) {}
#endif

const char* DEBUGMETA[6] = {
	"METASCALAR",
	"METAVECTOR",
	"METAMATRIX",
	"METAVECTORPARTIAL",
	"METAVECTORMATRIXPARTIAL",
	"METAMATRIXPARTIAL"};

ComplexFunctionPtrVector mathfnvec1param[] = {sum, sqsum, var, sdv, mean, rsum};
const char* mathfnop2paramname[] = {
						"logxy",
						"atan2", "pow",
						"max", "min",
						"+", "-",
						"*", "/",
						"%", ">",
						"<", ">=",
						"<=", "=",
						"!=", "//",
						"rem"
						}; //the 2 params functions
const int POWFNINDEX = 2; 
const int NUMMATH2PARAMFNOP = 18; 
const int NUMVOID2PARAMBIGINTFNMIN = 2; //bigint fns start from pow
const int NUMVOID2PARAMBIGINTFNMAX = 9;

const int ATAN2FNINDEX = 1;

ComplexFunctionPtr2Param mathfn2param[] = {clogx, carctangent2, cpower, cmax, cmin, cadd, csub,
									cmul, cdiv, cmod, cgt, clt, cgte, clte, ceq, cneq, cpar, crem};

const char* matrixfnname[] = {
						"det", "inv",
						"idn", "trc",
						"eival", "eivec",
						"tpose"
						};
const int NUMMATRIXPARAMFN = 7;
const char* mathfn1paramname[] = {
						"sin", "cos", "tan", "cot", 
						"rect",
						"asin", "acos", "atan", "acot", 
						"polar", 
						"sinh", "cosh", "tanh", "coth", 
						"asinh", "acosh", "atanh", "acoth", 
						"exp", "log10", "log", "log2", "sqrt", "cbrt", "conj",
						"torad", "todeg", "recip", "neg",						
						"abs", "arg", "re", "im"}; //the 1 param functions
const int EXPFNINDEX = 18;
const int NUMMATH1PARAMFN = 29;
const int NUMREAL1PARAMFN = 4;
const int NUMMATH1PARAMTRIGFN = 5;
const int NUMMATH1PARAMTRIGANTIFN = 10;

//these 23 return ComplexDouble
ComplexFunctionPtr1Param mathfn1param[] = {	csine,
											ccosine,
											ctangent,
											ccotangent,
											rect,

											carcsine,
											carccosine,
											carctangent,
											carccotangent,
											polar,

											csinehyp,
											ccosinehyp,
											ctangenthyp,
											ccotangenthyp,

											carcsinehyp, 
											carccosinehyp, 
											carctangenthyp,
											carccotangenthyp,

											cexpo, clogarithm10, 
											cln, clog2, 
											csqroot, cbroot, 
											conjugate,

											crad,
											cdeg,
											crecip,
											cneg};

//the 1 param functions that have real result
RealFunctionPtr realfn1param[] = {abso, cargu, crealpart, cimagpart};

BigIntVoid1ParamFunctionPtr bigfnvoid1param[] = {bigint_hex, bigint_dec, bigint_bin, bigint_oct, bigint_neg};
BigIntVoid2ParamFunctionPtr bigfnvoid2param[] = {bigint_pow, bigint_max, bigint_min, bigint_add, bigint_sub, bigint_mul, bigint_div, bigint_rem};

BigIntIntFunctionPtr bigfnint2param[] = {bigint_gt, bigint_lt, bigint_gte, bigint_lte, bigint_eq, bigint_neq};

const char* bigfnvoid1paramname[] = {"hex", "dec", "bin", "oct", "neg"};
const int NUMBIGINT1FNS = 5;
const char* vecfn1paramname[] = {"sum", "sqsum", "var", "sd", "mean", "rsum"};
const char* vecfn2paramname[] = {"dot"};
const int NUMVECFNS = 6;
const int NUMVEC2FNS = 1;

const long double __TS_PI__ = 3.14159265358979323846L;

void print(const char* str);
int execute(int argc, const char* const *argv);
char ** complete(int argc, const char* const *argv);
void sigint(void);
char get_char(void);

void (*NULLFN)(void) = NULL;

#define KEY_NUL 0 /**< ^@ Null character */
#define KEY_SOH 1 /**< ^A Start of heading, = console interrupt */
#define KEY_STX 2 /**< ^B Start of text, maintenance mode on HP console */
#define KEY_ETX 3 /**< ^C End of text */
#define KEY_EOT 4 /**< ^D End of transmission, not the same as ETB */
#define KEY_ENQ 5 /**< ^E Enquiry, goes with ACK; old HP flow control */
#define KEY_ACK 6 /**< ^F Acknowledge, clears ENQ logon hand */
#define KEY_BEL 7 /**< ^G Bell, rings the bell... */
#define KEY_BS  8 /**< ^H Backspace, works on HP terminals/computers */
#define KEY_HT  9 /**< ^I Horizontal tab, move to next tab stop */
#define KEY_LF  10  /**< ^J Line Feed */
#define KEY_VT  11  /**< ^K Vertical tab */
#define KEY_FF  12  /**< ^L Form Feed, page eject */
#define KEY_CR  13  /**< ^M Carriage Return*/
#define KEY_SO  14  /**< ^N Shift Out, alternate character set */
#define KEY_SI  15  /**< ^O Shift In, resume defaultn character set */
#define KEY_DLE 16  /**< ^P Data link escape */
#define KEY_DC1 17  /**< ^Q XON, with XOFF to pause listings; "okay to send". */
#define KEY_DC2 18  /**< ^R Device control 2, block-mode flow control */
#define KEY_DC3 19  /**< ^S XOFF, with XON is TERM=18 flow control */
#define KEY_DC4 20  /**< ^T Device control 4 */
#define KEY_NAK 21  /**< ^U Negative acknowledge */
#define KEY_SYN 22  /**< ^V Synchronous idle */
#define KEY_ETB 23  /**< ^W End transmission block, not the same as EOT */
#define KEY_CAN 24  /**< ^X Cancel line, MPE echoes !!! */
#define KEY_EM  25  /**< ^Y End of medium, Control-Y interrupt */
#define KEY_SUB 26  /**< ^Z Substitute */
#define KEY_ESC 27  /**< ^[ Escape, next character is not echoed */
#define KEY_FS  28  /**< ^\ File separator */
#define KEY_GS  29  /**< ^] Group separator */
#define KEY_RS  30  /**< ^^ Record separator, block-mode terminator */
#define KEY_US  31  /**< ^_ Unit separator */

#define KEY_DEL 127 /**< Delete (not a real control character...) */

#define FPGA_CMD_NUL 0
#define FPGA_CMD_CRLF 1
#define FPGA_CMD_UP 2
#define FPGA_CMD_DEL 4
#define FPGA_CMD_PGUP 5
#define FPGA_CMD_PGDN 6
#define FPGA_CMD_BKSP 8
#define FPGA_CMD_TAB 9
#define FPGA_CMD_LF 10
#define FPGA_CMD_DOWN 10
#define FPGA_CMD_RIGHT 11
#define FPGA_CMD_LEFT 12
#define FPGA_CMD_CR 13
#define FPGA_CMD_HOME 13
#define FPGA_CMD_CLS 14
#define FPGA_CMD_END 15
#define FPGA_CMD_SPC 32

#define FPGA_CMD_ERASE_SOL 16
#define FPGA_CMD_ERASE_EOL 17
#define FPGA_CMD_ERASE_LINE 18
#define FPGA_CMD_CURTOG 19
#define FPGA_CMD_CHARTOG 20

#define PROMPTSTR "ts2> "
#define PROMPTSTRLEN 5

#undef OLDIMPL

/*
vt sequences:
<esc>[1~    - Home        <esc>[16~   -             <esc>[31~   - F17
<esc>[2~    - Insert      <esc>[17~   - F6          <esc>[32~   - F18
<esc>[3~    - Delete      <esc>[18~   - F7          <esc>[33~   - F19
<esc>[4~    - End         <esc>[19~   - F8          <esc>[34~   - F20
<esc>[5~    - PgUp        <esc>[20~   - F9          <esc>[35~   - 
<esc>[6~    - PgDn        <esc>[21~   - F10         
<esc>[7~    - Home        <esc>[22~   -             
<esc>[8~    - End         <esc>[23~   - F11         
<esc>[9~    -             <esc>[24~   - F12         
<esc>[10~   - F0          <esc>[25~   - F13         
<esc>[11~   - F1          <esc>[26~   - F14         
<esc>[12~   - F2          <esc>[27~   -             
<esc>[13~   - F3          <esc>[28~   - F15         
<esc>[14~   - F4          <esc>[29~   - F16         
<esc>[15~   - F5          <esc>[30~   -

xterm sequences:
<esc>[A     - Up          <esc>[K     -             <esc>[U     -
<esc>[B     - Down        <esc>[L     -             <esc>[V     -
<esc>[C     - Right       <esc>[M     -             <esc>[W     -
<esc>[D     - Left        <esc>[N     -             <esc>[X     -
<esc>[E     -             <esc>[O     -             <esc>[Y     -
<esc>[F     - End         <esc>[1P    - F1          <esc>[Z     -
<esc>[G     - Keypad 5    <esc>[1Q    - F2       
<esc>[H     - Home        <esc>[1R    - F3       
<esc>[I     -             <esc>[1S    - F4       
<esc>[J     -             <esc>[T     - 

*/
#endif
