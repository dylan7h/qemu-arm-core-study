https://developer.arm.com/documentation/dui0417/d/programmer-s-reference/memory-map?lang=en

The major system components and interfaces provided by the baseboard are:

a tile site to support RealView Logic Tiles
a Cortex-A8 test chip
a Debug FPGA implementing the CoreSight infrastructure
a Northbridge implementing the major system controllers and interfaces
a Southbridge implementing most of the remaining system peripherals
512MB of 32-bit wide (DDR) SDRAM (2 x 256MB banks)
2MB of 32-bit wide (Pseudo) SRAM
128MB of 32-bit wide NOR flash in two banks of 64MB
PISMO connector for up to 256MB (4x 64MB) of static memory expansion
PCI and PCI Express expansion buses (2 slots for each interface type)
USB interface providing 1 OTG and 2 Full Speed USB 2.0 host ports
Ethernet interface providing 10Base-T and 100Base-TX support
DVI-I interface providing color LCD display and analog VGA monitor support
Synchronous Serial Port (SSP) interface
4x RS232 interfaces with modem support
PS2 keyboard and mouse interfaces
audio CODEC interface (AAC)
CompactFlash, MMC, SD and SIM Card interfaces
8x general purpose (User) switches and LEDs
Real-Time Clock (RTC)
Time Of Year clock (TOY) with backup battery
programmable clock generators
power supplies, voltage control, and current monitoring circuitry
JTAG config and debug, and Integrated Logic Analyzer (ILA) support
Trace port (32-bit) with Embedded Trace Buffer
USB config port.


Dynamic memory mirror (0x70000000-0x7FFFFFFF)

During boot remapping however, the bottom 16MB of this memory region (0x00000000-0x00FFFFFF) can be:

NOR flash: 0x40000000-0x40FFFFFF
static expansion memory (PISMO): 0x50000000-0x50FFFFFF
0x00000000-0x0FFFFFFF	AXI	256MB

System registers	0x10000000-0x10000FFF	APB	4KB
System controller 0	0x10001000-0x10001FFF	APB	4KB
3-Wire Serial Bus Control	0x10002000-0x10002FFF	APB	4KB
Reserved	0x10003000-0x10003FFF	APB	4KB
Advanced Audio CODEC	0x10004000-0x10004FFF	APB	4KB
MultiMedia Card Interface	0x10005000-0x10005FFF	APB	4KB
Keyboard/Mouse Interface 0	0x10006000-0x10006FFF	APB	4KB
Keyboard/Mouse Interface 1	0x10007000-0x10007FFF	APB	4KB
Reserved for future use	0x10008000-0x10008FFF	APB	4KB
UART 0 Interface	
0x10009000-0x10009FFF

APB	4KB
UART 1 Interface	
0x1000A000-0x1000AFFF

APB	4KB
UART 2 Interface	
0x1000B000-0x1000BFFF

APB	4KB
UART 3 Interface	
0x1000C000-0x1000CFFF

APB	4KB
Synchronous Serial Port Interface	
0x1000D000-0x1000DFFF

APB	4KB
Smart Card Interface	0x1000E000-0x1000EFFF	APB	4KB
Watchdog 0 Interface	0x1000F000-0x1000FFFF	APB	4KB
Watchdog 1 Interface

0x10010000-0x10010FFF

APB	4KB
Timer modules 0 and 1 Interface

(Timer 1 registers start at 0x10011020)

0x10011000-0x10011FFF

APB	4KB
Timer modules 2 and 3 Interface

(Timer 3 registers start at 0x10012020)

0x10012000-0x10012FFF

APB	4KB
GPIO Interface 0

0x10013000-0x10013FFF

APB	4KB
GPIO Interface 1

0x10014000-0x10014FFF

APB	4KB
GPIO Interface 2 (miscellaneous onboard I/O)

0x10015000-0x10015FFF

APB	4KB
Serial Bus Control (DVI)	
0x10016000-0x10016FFF

APB	4KB
Real Time Clock Interface

0x10017000-0x10017FFF

APB	4KB
Timer Modules 4 and 5 Interface (Timer 5 registers start at 0x10018020)	
0x10018000-0x10018FFF

APB	4KB
Timer Modules 6 and 7 Interface (Timer 7 registers start at 0x10019020)	0x10019000-0x10019FFF	APB	4KB
System Controller 1	0x1001A000-0x1001AFFF	APB	4KB
Reserved for future use (4K x 5)	0x1001B000-0x1001FFFF	APB	20KB
Color LCD Controller configuration

0x10020000-0x1002FFFF	AHB	64KB
DMA Controller configuration

0x10030000-0x1003FFFF	AHB	64KB
Reserved (64K x 2)	0x10040000-0x1005FFFF	AHB	128KB
Internal Northbridge SRAM	0x10060000-0x1007FFFF	AXI	128KB
Reserved (64K x 6)	0x10080000-0x100DFFFF	AHB	384KB
Dynamic Memory Controller configuration	
0x100E0000-0x100E0FFF

APB	4KB
Static Memory Controller configuration	0x100E1000-0x100E1FFF	APB	4KB
Reserved	
0x100E2000-0x100E2FFF

APB	4KB
APB Registers (PLL configuration)	
0x100E3000-0x100E3FFF

APB	4KB
Reserved for future use	
0x100E4000-0x100EFFFF

APB	48KB
Reserved for future use	
0x100F0000-0x100FFFFF

APB	64KB
Reserved	
0x10100000-0x103FFFFF

−	3MB
Reserved for future use	
0x10400000-0x16FFFFFF

AHB or AXI	108MB
Reserved for future use	
0x17000000-0x17FFFFFF

AXI	16MB
Compact Flash	
0x18000000-0x18000FFF

AHB	4KB
Reserved for future use	
0x18001000-0x1BFFFFFF

AHB	63.096MB
DAP ROM table	
0x1C000000-0x1DFFFFFF

AHB	32MB
Generic Interrupt Controller 1 (GIC1) (nIRQ interrupt handling for Cortex-A8)	
0x1E000000-0x1E00FFFF

APB	64KB
Generic Interrupt Controller 2 (GIC2) (nFIQ interrupt handling for Cortex-A8)	
0x1E010000-0x1E01FFFF

APB	64KB
Generic Interrupt Controller 3 (GIC3) (nIRQ interrupt handling for Tile Site)	
0x1E020000-0x1E02FFFF

APB	64KB
Generic Interrupt Controller 4 (GIC4) (nFIQ interrupt handling for Tile Site)	
0x1E030000-0x1E03FFFF

APB	64KB
Reserved for future use	
0x1E040000-0x1EFFFFFF

AHB	15.75MB
Reserved for future use	
0x1F000000-0x1FFFFFFF

AHB	16MB
Reserved	
0x20000000-0x3FFFFFFF

AHB or AXI	512MB

PCI interface

0x60000000-0x6FFFFFFF

PCI	256MB
Dynamic memory (CS0)	
0x70000000-0x7FFFFFFF

DDR	256MB
Dynamic memory (CS1)	
0x80000000-0x8FFFFFFF

DDR	256MB
PCI interface

0x90000000-0xBFFFFFFF

PCI	768MB
Logic Tile site expansion. (If a Logic tile is not fitted, the baseboard aborts accesses to this memory region)	
0xC0000000-0xFFFFFFFF

External	1GB