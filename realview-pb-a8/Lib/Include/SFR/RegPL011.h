#ifndef __REGPL011__H__
#define __REGPL011__H__

#include "Type.h"

typedef struct
{
    /* 0x000  */ 
    union
    {
        __IO uint32_t Reg;
        struct
        {
            __IOM uint32_t DATA       : 8;    /* [ 7:0 ]    Receive (read) data character. 
                                                            Transmit (write) data character.*/
            __IOM uint32_t FE         : 1;    /* [ 8 ]      Framing error. When set to 1, it indicates that the received character did not have a valid stop bit (a valid stop bit is 1).
                                                            In FIFO mode, this error is associated with the character at the top of the FIFO.*/
            __IOM uint32_t PE         : 1;    /* [ 9 ]      Parity error. When set to 1, it indicates that the parity of the received data character does not match the
                                                            parity that the EPS and SPS bits in the Line Control Register, UARTLCR_H on page 3-12 select.
                                                            In FIFO mode, this error is associated with the character at the top of the FIFO. */
            __IOM uint32_t BE         : 1;    /* [ 10 ]     Break error. This bit is set to 1 if a break condition was detected, indicating that the received data input was held LOW for longer 
                                                            than a full-word transmission time (defined as start, data, parity and stop bits).
                                                            In FIFO mode, this error is associated with the character at the top of the FIFO. When a break occurs,
                                                            only one 0 character is loaded into the FIFO. The next character is only enabled after the receive data
                                                            input goes to a 1 (marking state), and the next valid start bit is received.*/
            __IOM uint32_t OE         : 1;    /* [ 11 ]     Overrun error. This bit is set to 1 if data is received and the receive FIFO is already full.
                                                            This is cleared to 0 once there is an empty space in the FIFO and a new character can be written to it.*/
            __IOM uint32_t RESERVED   : 20;   /* [ 12:31 ] */
        } Bit;
        
    } UARTDR;            /* RW 0x--- 12/8 Data Register, UARTDR on page 3-5 */
    /* 0x004  */
    union
    {
        __IO uint32_t Reg;
        struct
        {
            __IOM uint32_t FE         : 1;    /* [ 0 ]      Framing error. When set to 1, it indicates that the received character did not have a valid stop bit (a valid stop bit is 1).
                                                            This bit is cleared to 0 by a write to UARTECR.
                                                            In FIFO mode, this error is associated with the character at the top of the FIFO. */
            __IOM uint32_t PE         : 1;    /* [ 1 ]      Parity error. When set to 1, it indicates that the parity of the received data character does not match the
                                                            parity that the EPS and SPS bits in the Line Control Register, UARTLCR_H on page 3-12 select.
                                                            This bit is cleared to 0 by a write to UARTECR.
                                                            In FIFO mode, this error is associated with the character at the top of the FIFO. */
            __IOM uint32_t BE         : 1;    /* [ 2 ]      Break error. This bit is set to 1 if a break condition was detected, indicating that the received data input
                                                            was held LOW for longer than a full-word transmission time (defined as start, data, parity, and stop bits).
                                                            This bit is cleared to 0 after a write to UARTECR.
                                                            In FIFO mode, this error is associated with the character at the top of the FIFO. When a break occurs,
                                                            only one 0 character is loaded into the FIFO. The next character is only enabled after the receive data
                                                            input goes to a 1 (marking state) and the next valid start bit is received. */
            __IOM uint32_t OE         : 1;    /* [ 3 ]      Overrun error. This bit is set to 1 if data is received and the FIFO is already full.
                                                            This bit is cleared to 0 by a write to UARTECR.
                                                            The FIFO contents remain valid because no more data is written when the FIFO is full, only the contents
                                                            of the shift register are overwritten. The CPU must now read the data, to empty the FIFO. */
            __IOM uint32_t RESERVED   : 28;   /* [ 4:31 ] */
        } Bit;
    } UARTRSR_ECR;      /* RW 0x0 4/0 Receive Status Register/Error Clear Register, UARTRSR/UARTECR on page 3-6 */
    /* 0x008-0x014 */
    __O uint32_t RESERVED0[3U];
    /* 0x018 */ 
    union
    {
        __O uint32_t Reg;
        struct
        {
            __OM uint32_t CTS        : 1;    /* [ 0 ]       Clear to send. This bit is the complement of the UART clear to send, nUARTCTS, modem status input.
                                                            That is, the bit is 1 when nUARTCTS is LOW. */
            __OM uint32_t DSR        : 1;    /* [ 1 ]       Data set ready. This bit is the complement of the UART data set ready, nUARTDSR, modem status input. 
                                                            That is, the bit is 1 when nUARTDSR is LOW. */
            __OM uint32_t DCD        : 1;    /* [ 2 ]       Data carrier detect. This bit is the complement of the UART data carrier detect, nUARTDCD, modem status input. 
                                                            That is, the bit is 1 when nUARTDCD is LOW. */
            __OM uint32_t BUSY       : 1;    /* [ 3 ]       UART busy. If this bit is set to 1, the UART is busy transmitting data. This bit remains set until the
                                                            complete byte, including all the stop bits, has been sent from the shift register.
                                                            This bit is set as soon as the transmit FIFO becomes non-empty, regardless of whether the UART is enabled or not. */
            __OM uint32_t RXFE       : 1;    /* [ 4 ]       Receive FIFO empty. The meaning of this bit depends on the state of the FEN bit in the UARTLCR_H Register.
                                                            If the FIFO is disabled, this bit is set when the receive holding register is empty.
                                                            If the FIFO is enabled, the RXFE bit is set when the receive FIFO is empty. */
            __OM uint32_t TXFF       : 1;    /* [ 5 ]       Transmit FIFO full. The meaning of this bit depends on the state of the FEN bit in the UARTLCR_H Register.
                                                            If the FIFO is disabled, this bit is set when the transmit holding register is full.
                                                            If the FIFO is enabled, the TXFF bit is set when the transmit FIFO is full. */
            __OM uint32_t RXFF       : 1;    /* [ 6 ]       Receive FIFO full. The meaning of this bit depends on the state of the FEN bit in the UARTLCR_H Register.
                                                            If the FIFO is disabled, this bit is set when the receive holding register is full.
                                                            If the FIFO is enabled, the RXFF bit is set when the receive FIFO is full. */
            __OM uint32_t TXFE       : 1;    /* [ 7 ]       Transmit FIFO empty. The meaning of this bit depends on the state of the FEN bit in the Line Control Register, UARTLCR_H on page 3-12.
                                                            If the FIFO is disabled, this bit is set when the transmit holding register is empty.
                                                            If the FIFO is enabled, the TXFE bit is set when the transmit FIFO is empty.
                                                            This bit does not indicate if there is data in the transmit shift register. */
            __OM uint32_t RI         : 1;    /* [ 8 ]       Ring indicator. This bit is the complement of the UART ring indicator, nUARTRI, modem status input.
                                                            That is, the bit is 1 when nUARTRI is LOW. */
            __OM uint32_t RESERVED   : 23;   /* [ 9:31 ] */
        } Bit;
    } UARTFR;            /* RO 0b-10010--- 9 Flag Register, UARTFR on page 3-8 */
    /* 0x01C */
    __O uint32_t RESERVED1;
    /* 0x020 */ 
    union
    {
        __IO uint32_t Reg;
        struct
        {
            __IOM uint32_t ILPDVSR    : 8;    /* [ 0:7 ]    8-bit low-power divisor value.
                                                            These bits are cleared to 0 at reset. */
            __IOM uint32_t RESERVED   : 24;   /* [ 8:31 ] */
        } Bit;
    } UARTILPR;          /* RW 0x00 8 IrDA Low-Power Counter Register, UARTILPR on page 3-9 */
    /* 0x024 */ 
    union
    {
        __IO uint32_t Reg;
        struct
        {
            __IOM uint32_t DIVINT     : 16;   /* [ 0:15 ]   The integer baud rate divisor.
                                                            These bits are cleared to 0 on reset. */
            __IOM uint32_t RESERVED   : 16;   /* [ 16:31 ] */
        } Bit;
    } UARTIBRD;          /* RW 0x0000 16 Integer Baud Rate Register, UARTIBRD on page 3-9 */
    /* 0x028 */ 
    union
    {
        __IO uint32_t Reg;
        struct
        {
            __IOM uint32_t DIVFRAC    : 6;    /* [ 0:5 ]    The fractional baud rate divisor.
                                                            These bits are cleared to 0 on reset. */
            __IOM uint32_t RESERVED   : 26;   /* [ 6:31 ] */
        } Bit;
    } UARTFBRD;          /* RW 0x00 6 Fractional Baud Rate Register, UARTFBRD on page 3-10 */
    /* 0x02C */ 
    union
    {
        __IO uint32_t Reg;
        struct
        {
            __IOM uint32_t BRK        : 1;    /* [ 0 ]      Send break. If this bit is set to 1, a low-level is continually output on the UARTTXD output, after completing transmission of the current character. 
                                                            For the proper execution of the break command, the software must set this bit for at least two complete frames.
                                                            For normal use, this bit must be cleared to 0. */
            __IOM uint32_t PEN        : 1;    /* [ 1 ]      Parity enable:
                                                            0 = parity is disabled and no parity bit added to the data frame
                                                            1 = parity checking and generation is enabled.
                                                            See Table 3-11 on page 3-14 for the parity truth table. */
            __IOM uint32_t EPS        : 1;    /* [ 2 ]      Even parity select. Controls the type of parity the UART uses during transmission and reception:
                                                            0 = odd parity. The UART generates or checks for an odd number of 1s in the data and parity bits.
                                                            1 = even parity. The UART generates or checks for an even number of 1s in the data and parity bits.
                                                            This bit has no effect when the PEN bit disables parity checking and generation. See Table 3-11 on
                                                            page 3-14 for the parity truth table. */
            __IOM uint32_t STP2       : 1;    /* [ 3 ]      Two stop bits select. If this bit is set to 1, two stop bits are transmitted at the end of the frame. 
                                                            The receive logic does not check for two stop bits being received. */
            __IOM uint32_t FEN        : 1;    /* [ 4 ]      Enable FIFOs:
                                                            0 = FIFOs are disabled (character mode) that is, the FIFOs become 1-byte-deep holding registers
                                                            1 = transmit and receive FIFO buffers are enabled (FIFO mode). */
            __IOM uint32_t WLEN       : 2;    /* [ 5:6 ]    Word length. These bits indicate the number of data bits transmitted or received in a frame as follows:
                                                            b11 = 8 bits
                                                            b10 = 7 bits
                                                            b01 = 6 bits
                                                            b00 = 5 bits. */
            __IOM uint32_t SPS        : 1;    /* [ 7 ]      Stick parity select.
                                                            0 = stick parity is disabled
                                                            1 = either:
                                                            • if the EPS bit is 0 then the parity bit is transmitted and checked as a 1
                                                            • if the EPS bit is 1 then the parity bit is transmitted and checked as a 0.
                                                            This bit has no effect when the PEN bit disables parity checking and generation. See Table 3-11 on
                                                            page 3-14 for the parity truth table. */
            __IOM uint32_t RESERVED   : 24;   /* [ 8 ] */
        } Bit;
    } UARTLCR_H;         /* RW 0x00 8 Line Control Register, UARTLCR_H on page 3-12 */
    /* 0x030 */ 
    union
    {
        __IO uint32_t Reg;
        struct
        {
            __IOM uint32_t UARTEN     : 1;    /* [ 0 ]      UART enable:
                                                            0 = UART is disabled. If the UART is disabled in the middle of transmission or reception, it completes the current character before stopping.
                                                            1 = the UART is enabled. Data transmission and reception occurs for either UART signals or SIR signals depending on the setting of the SIREN bit. */
            __IOM uint32_t SIREN      : 1;    /* [ 1 ]      SIR enable:
                                                            0 = IrDA SIR ENDEC is disabled. nSIROUT remains LOW (no light pulse generated), and signal transitions on SIRIN have no effect.
                                                            1 = IrDA SIR ENDEC is enabled. Data is transmitted and received on nSIROUT and SIRIN.
                                                            UARTTXD remains HIGH, in the marking state. Signal transitions on UARTRXD or modem status inputs have no effect.
                                                            This bit has no effect if the UARTEN bit disables the UART. */
            __IOM uint32_t SIRLP      : 1;    /* [ 2 ]      SIR low-power IrDA mode. This bit selects the IrDA encoding mode. If this bit is cleared to 0,
                                                            low-level bits are transmitted as an active high pulse with a width of 3/16th of the bit period. 
                                                            If this bit is set to 1, low-level bits are transmitted with a pulse width that is 3 times the period of the IrLPBaud16 input signal, 
                                                            regardless of the selected bit rate. Setting this bit uses less power, but might reduce transmission distances. */
            __IOM uint32_t RESERVED0  : 4;    /* [ 3:6 ] */
            __IOM uint32_t LBE        : 1;    /* [ 7 ]      Loopback enable. If this bit is set to 1 and the SIREN bit is set to 1 and the SIRTEST bit in the Test
                                                            Control Register, UARTTCR on page 4-5 is set to 1, 
                                                            then the nSIROUT path is inverted, and fed through to the SIRIN path. 
                                                            The SIRTEST bit in the test register must be set to 1 to override the normal half-duplex SIR operation. 
                                                            This must be the requirement for accessing the test registers during normal operation, and SIRTEST must be cleared to 0 when loopback testing is finished. 
                                                            This feature reduces the amount of external coupling required during system test.
                                                            If this bit is set to 1, and the SIRTEST bit is set to 0, the UARTTXD path is fed through to the UARTRXD path.
                                                            In either SIR mode or UART mode, when this bit is set, the modem outputs are also fed through to the modem inputs.
                                                            This bit is cleared to 0 on reset, to disable loopback. */
            __IOM uint32_t TXE        : 1;    /* [ 8 ]      Transmit enable. If this bit is set to 1, the transmit section of the UART is enabled. 
                                                            Data transmission occurs for either UART signals, or SIR signals depending on the setting of the SIREN bit. 
                                                            When the UART is disabled in the middle of transmission, it completes the current character before stopping. */
            __IOM uint32_t RXE        : 1;    /* [ 9 ]      Receive enable. If this bit is set to 1, the receive section of the UART is enabled. Data reception
                                                            occurs for either UART signals or SIR signals depending on the setting of the SIREN bit. 
                                                            When the UART is disabled in the middle of reception, it completes the current character before stopping. */
            __IOM uint32_t DTR        : 1;    /* [ 10 ]     Data transmit ready. This bit is the complement of the UART data transmit ready, nUARTDTR,
                                                            modem status output. That is, when the bit is programmed to a 1 then nUARTDTR is LOW. */
            __IOM uint32_t RTS        : 1;    /* [ 11 ]     Request to send. This bit is the complement of the UART request to send, nUARTRTS, modem status output. 
                                                            That is, when the bit is programmed to a 1 then nUARTRTS is LOW. */
            __IOM uint32_t Out1       : 1;    /* [ 12 ]     This bit is the complement of the UART Out1 (nUARTOut1) modem status output. 
                                                            That is, when the bit is programmed to a 1 the output is 0. For DTE this can be used as Data Carrier Detect (DCD). */
            __IOM uint32_t Out2       : 1;    /* [ 13 ]     This bit is the complement of the UART Out2 (nUARTOut2) modem status output. That is, when the
                                                            bit is programmed to a 1, the output is 0. For DTE this can be used as Ring Indicator (RI). */
            __IOM uint32_t RTSEn      : 1;    /* [ 14 ]     RTS hardware flow control enable. If this bit is set to 1, RTS hardware flow control is enabled. 
                                                            Data is only requested when there is space in the receive FIFO for it to be received. */
            __IOM uint32_t CTSEn      : 1;    /* [ 15 ]     CTS hardware flow control enable. If this bit is set to 1, CTS hardware flow control is enabled.
                                                            Data is only transmitted when the nUARTCTS signal is asserted. */
            __IOM uint32_t RESERVED1  : 16;   /* [ 16:31 ] */
        } Bit;
    } UARTCR;            /* RW 0x0300 16 Control Register, UARTCR on page 3-15 */
    /* 0x034 */ 
    union
    {
        __IO uint32_t Reg;
        struct
        {
            __IOM uint32_t TXIFLSEL   : 3;    /* [ 0:2 ]    Transmit interrupt FIFO level select. The trigger points for the transmit interrupt are as follows:
                                                            b000 = Transmit FIFO becomes ≤ 1/8 full
                                                            b001 = Transmit FIFO becomes ≤ 1/4 full
                                                            b010 = Transmit FIFO becomes ≤ 1/2 full
                                                            b011 = Transmit FIFO becomes ≤ 3/4 full
                                                            b100 = Transmit FIFO becomes ≤ 7/8 full
                                                            b101-b111 = reserved. */
            __IOM uint32_t RXIFLSEL   : 3;    /* [ 3:5 ]    Receive interrupt FIFO level select. The trigger points for the receive interrupt are as follows:
                                                            b000 = Receive FIFO becomes ≥ 1/8 full
                                                            b001 = Receive FIFO becomes ≥ 1/4 full
                                                            b010 = Receive FIFO becomes ≥ 1/2 full
                                                            b011 = Receive FIFO becomes ≥ 3/4 full
                                                            b100 = Receive FIFO becomes ≥ 7/8 full
                                                            b101-b111 = reserved. */
            __IOM uint32_t RESERVED   : 26;   /* [ 6:31 ] */
        } Bit;
    } UARTIFLS;          /* RW 0x12 6 Interrupt FIFO Level Select Register, UARTIFLS on page 3-17 */
    /* 0x038 */ 
    union
    {
        __IO uint32_t Reg;
        struct
        {
            __IOM uint32_t RIMIM      : 1;    /* [ 0 ]      nUARTRI modem interrupt mask. A read returns the current mask for the UARTRIINTR interrupt.
                                                            On a write of 1, the mask of the UARTRIINTR interrupt is set. A write of 0 clears the mask. */
            __IOM uint32_t CTSMIM     : 1;    /* [ 1 ]      nUARTCTS modem interrupt mask. A read returns the current mask for the UARTCTSINTR interrupt.
                                                            On a write of 1, the mask of the UARTCTSINTR interrupt is set. A write of 0 clears the mask. */
            __IOM uint32_t DCDMIM     : 1;    /* [ 2 ]      nUARTDCD modem interrupt mask. A read returns the current mask for the UARTDCDINTR interrupt.
                                                            On a write of 1, the mask of the UARTDCDINTR interrupt is set. A write of 0 clears the mask. */
            __IOM uint32_t DSRMIM     : 1;    /* [ 3 ]      nUARTDSR modem interrupt mask. A read returns the current mask for the UARTDSRINTR interrupt.
                                                            On a write of 1, the mask of the UARTDSRINTR interrupt is set. A write of 0 clears the mask. */
            __IOM uint32_t RXIM       : 1;    /* [ 4 ]      Receive interrupt mask. A read returns the current mask for the UARTRXINTR interrupt.
                                                            On a write of 1, the mask of the UARTRXINTR interrupt is set. A write of 0 clears the mask. */
            __IOM uint32_t TXIM       : 1;    /* [ 5 ]      Transmit interrupt mask. A read returns the current mask for the UARTTXINTR interrupt.
                                                            On a write of 1, the mask of the UARTTXINTR interrupt is set. A write of 0 clears the mask. */
            __IOM uint32_t RTIM       : 1;    /* [ 6 ]      Receive timeout interrupt mask. A read returns the current mask for the UARTRTINTR interrupt.
                                                            On a write of 1, the mask of the UARTRTINTR interrupt is set. A write of 0 clears the mask. */
            __IOM uint32_t FEIM       : 1;    /* [ 7 ]      Framing error interrupt mask. A read returns the current mask for the UARTFEINTR interrupt.
                                                            On a write of 1, the mask of the UARTFEINTR interrupt is set. A write of 0 clears the mask. */
            __IOM uint32_t PEIM       : 1;    /* [ 8 ]      Parity error interrupt mask. A read returns the current mask for the UARTPEINTR interrupt.
                                                            On a write of 1, the mask of the UARTPEINTR interrupt is set. A write of 0 clears the mask. */
            __IOM uint32_t BEIM       : 1;    /* [ 9 ]      Break error interrupt mask. A read returns the current mask for the UARTBEINTR interrupt.
                                                            On a write of 1, the mask of the UARTBEINTR interrupt is set. A write of 0 clears the mask. */
            __IOM uint32_t OEIM       : 1;    /* [ 10 ]     Overrun error interrupt mask. A read returns the current mask for the UARTOEINTR interrupt.
                                                            On a write of 1, the mask of the UARTOEINTR interrupt is set. A write of 0 clears the mask. */
            __IOM uint32_t RESERVED   : 21;   /* [ 11:31 ] */
        } Bit;
    } UARTIMSC;          /* RW 0x000 11 Interrupt Mask Set/Clear Register, UARTIMSC on page 3-17 */
    /* 0x03C */ 
    union
    {
        __O uint32_t Reg;
        struct
        {
            __OM uint32_t RIRMIS     : 1;    /* [ 0 ]       nUARTRI modem interrupt status. Returns the raw interrupt state of the UARTRIINTR interrupt. */
            __OM uint32_t CTSRMIS    : 1;    /* [ 1 ]       nUARTCTS modem interrupt status. Returns the raw interrupt state of the UARTCTSINTR interrupt. */    
            __OM uint32_t DCDRMIS    : 1;    /* [ 2 ]       nUARTDCD modem interrupt status. Returns the raw interrupt state of the UARTDCDINTR interrupt. */    
            __OM uint32_t DSRRMIS    : 1;    /* [ 3 ]       nUARTDSR modem interrupt status. Returns the raw interrupt state of the UARTDSRINTR interrupt. */    
            __OM uint32_t RXRIS      : 1;    /* [ 4 ]       Receive interrupt status. Returns the raw interrupt state of the UARTRXINTR interrupt. */    
            __OM uint32_t TXRIS      : 1;    /* [ 5 ]       Transmit interrupt status. Returns the raw interrupt state of the UARTTXINTR interrupt. */    
            __OM uint32_t RTRIS      : 1;    /* [ 6 ]       Receive timeout interrupt status. Returns the raw interrupt state of the UARTRTINTR interrupt. */    
            __OM uint32_t FERIS      : 1;    /* [ 7 ]       Framing error interrupt status. Returns the raw interrupt state of the UARTFEINTR interrupt. */    
            __OM uint32_t PERIS      : 1;    /* [ 8 ]       Parity error interrupt status. Returns the raw interrupt state of the UARTPEINTR interrupt. */    
            __OM uint32_t BERIS      : 1;    /* [ 9 ]       Break error interrupt status. Returns the raw interrupt state of the UARTBEINTR interrupt. */    
            __OM uint32_t OERIS      : 1;    /* [ 10 ]      Overrun error interrupt status. Returns the raw interrupt state of the UARTOEINTR interrupt. */    
            __OM uint32_t RESERVED   : 21;   /* [ 11:31 ] */
        } Bit;
    } UARTRIS;           /* RO 0x00- 11 Raw Interrupt Status Register, UARTRIS on page 3-19 */
    /* 0x040 */ 
    union
    {
        __O uint32_t Reg;
        struct
        {
            __OM uint32_t RIMMIS     : 1;    /* [ 0 ]       nUARTRI modem masked interrupt status. Returns the masked interrupt state of the UARTRIINTR interrupt. */
            __OM uint32_t CTSMMIS    : 1;    /* [ 1 ]       nUARTCTS modem masked interrupt status. Returns the masked interrupt state of the UARTCTSINTR interrupt. */
            __OM uint32_t DCDMMIS    : 1;    /* [ 2 ]       nUARTDCD modem masked interrupt status. Returns the masked interrupt state of the UARTDCDINTR interrupt. */
            __OM uint32_t DSRMMIS    : 1;    /* [ 3 ]       nUARTDSR modem masked interrupt status. Returns the masked interrupt state of the UARTDSRINTR interrupt. */
            __OM uint32_t RXMIS      : 1;    /* [ 4 ]       Receive masked interrupt status. Returns the masked interrupt state of the UARTRXINTR interrupt. */
            __OM uint32_t TXMIS      : 1;    /* [ 5 ]       Transmit masked interrupt status. Returns the masked interrupt state of the UARTTXINTR interrupt. */
            __OM uint32_t RTMIS      : 1;    /* [ 6 ]       Receive timeout masked interrupt status. Returns the masked interrupt state of the UARTRTINTR interrupt. */
            __OM uint32_t FEMIS      : 1;    /* [ 7 ]       Framing error masked interrupt status. Returns the masked interrupt state of the UARTFEINTR interrupt. */
            __OM uint32_t PEMIS      : 1;    /* [ 8 ]       Parity error masked interrupt status. Returns the masked interrupt state of the UARTPEINTR interrupt. */
            __OM uint32_t BEMIS      : 1;    /* [ 9 ]       Break error masked interrupt status. Returns the masked interrupt state of the UARTBEINTR interrupt. */
            __OM uint32_t OEMIS      : 1;    /* [ 10 ]      Overrun error masked interrupt status. Returns the masked interrupt state of the UARTOEINTR interrupt. */
            __OM uint32_t RESERVED   : 21;   /* [ 11 ] */
        } Bit;
    } UARTMIS;           /* RO 0x00- 11 Masked Interrupt Status Register, UARTMIS on page 3-20 */
    /* 0x044 */ 
    union
    {
        __I uint32_t Reg;
        struct
        {
            __IM uint32_t RIMIC      : 1;    /* [ 0 ]       nUARTRI modem interrupt clear. Clears the UARTRIINTR interrupt. */
            __IM uint32_t CTSMIC     : 1;    /* [ 1 ]       nUARTCTS modem interrupt clear. Clears the UARTCTSINTR interrupt. */
            __IM uint32_t DCDMIC     : 1;    /* [ 2 ]       nUARTDCD modem interrupt clear. Clears the UARTDCDINTR interrupt. */
            __IM uint32_t DSRMIC     : 1;    /* [ 3 ]       nUARTDSR modem interrupt clear. Clears the UARTDSRINTR interrupt. */
            __IM uint32_t RXIC       : 1;    /* [ 4 ]       Receive interrupt clear. Clears the UARTRXINTR interrupt. */
            __IM uint32_t TXIC       : 1;    /* [ 5 ]       Transmit interrupt clear. Clears the UARTTXINTR interrupt. */
            __IM uint32_t RTIC       : 1;    /* [ 6 ]       Receive timeout interrupt clear. Clears the UARTRTINTR interrupt. */
            __IM uint32_t FEIC       : 1;    /* [ 7 ]       Framing error interrupt clear. Clears the UARTFEINTR interrupt. */
            __IM uint32_t PEIC       : 1;    /* [ 8 ]       Parity error interrupt clear. Clears the UARTPEINTR interrupt. */
            __IM uint32_t BEIC       : 1;    /* [ 9 ]       Break error interrupt clear. Clears the UARTBEINTR interrupt. */
            __IM uint32_t OEIC       : 1;    /* [ 10 ]      Overrun error interrupt clear. Clears the UARTOEINTR interrupt. */
            __IM uint32_t RESERVED   : 21;   /* [ 11:31 ] */
        } Bit;
    } UARTICR;           /* WO - 11 Interrupt Clear Register, UARTICR on page 3-21 */
    /* 0x048 */ 
    union
    {
        __IO uint32_t Reg;
        struct
        {
            __IOM uint32_t RXDMAE     : 1;    /* [ 0 ]      Receive DMA enable. If this bit is set to 1, DMA for the receive FIFO is enabled. */
            __IOM uint32_t TXDMAE     : 1;    /* [ 1 ]      Transmit DMA enable. If this bit is set to 1, DMA for the transmit FIFO is enabled. */
            __IOM uint32_t DMAONERR   : 1;    /* [ 2 ]      DMA on error. If this bit is set to 1, the DMA receive request outputs, UARTRXDMASREQ or UARTRXDMABREQ, are disabled 
                                                            when the UART error interrupt is asserted. */
            __IOM uint32_t RESERVED   : 29;   /* [ 3:31 ] */                                        
        } Bit;
    } UARTDMACR;         /* RW 0x00 3 DMA Control Register, UARTDMACR on page 3-22 */
    /* 0x04C-0x07C */
    __O uint32_t RESERVED2[12U];
    /* 0x080-0x08C */
    __O uint32_t RESERVED3[3U];
    /* 0x090-0xFCC */
    __O uint32_t RESERVED4[975U];
    /* 0xFD0-0xFDC */
    __O uint32_t RESERVED5[3U];
    /* 0xFE0 */ 
    union
    {
        __O uint32_t Reg;
        struct
        {
            __OM uint32_t PartNumber0    : 8;    /* [ 0:7 ]     These bits read back as 0x11 */
            __OM uint32_t RESERVED       : 24;   /* [ 8:31 ] */
        } Bit;
    } UARTPeriphID0;     /* RO 0x11 8 UARTPeriphID0 Register on page 3-23 */
    /* 0xFE4 */ 
    union
    {
        __O uint32_t Reg;
        struct
        {
            uint32_t PartNumber1    : 4;    /* [ 0:3 ]          These bits read back as 0x0 */
            uint32_t Designer0      : 4;    /* [ 3:7 ]          These bits read back as 0x1 */
            uint32_t RESERVED       : 24;   /* [ 8:31 ] */
        } Bit;
    } UARTPeriphID1;     /* RO 0x10 8 UARTPeriphID1 Register on page 3-24 */
    /* 0xFE8 */ 
    union
    {
        __O uint32_t Reg;
        struct
        {
            __OM uint32_t Designer1      : 4;    /* [ 0:3 ]     These bits read back as 0x4 */
            __OM uint32_t Revision       : 4;    /* [ 3:7 ]     This field depends on the revision of the UART:
                                                                r1p0 0x0
                                                                r1p1 0x1
                                                                r1p3 0x2
                                                                r1p4 0x2
                                                                r1p5 0x3 */
            __OM uint32_t RESERVED       : 24;   /* [ 8:31 ] */
        } Bit;
    } UARTPeriphID2;     /* RO 0x_4a 8 UARTPeriphID2 Register on page 3-24 */
    /* 0xFEC */ 
    union
    {
        __O uint32_t Reg;
        struct
        {
            __OM uint32_t Configuration  : 8;    /* [ 0:7 ]     These bits read back as 0x00 */
            __OM uint32_t RESERVED       : 24;   /* [ 8:31 ] */
        } Bit;
    } UARTPeriphID3;     /* RO 0x00 8 UARTPeriphID3 Register on page 3-25 */
    /* 0xFF0 */ 
    union
    {
        __O uint32_t Reg;
        struct
        {
            __OM uint32_t UARTPCellID0   : 8;    /* [ 0:7 ]     These bits read back as 0x0D */
            __OM uint32_t RESERVED       : 24;   /* [ 8:31 ] */
        } Bit;
    } UARTPCellID0;      /* RO 0x0D 8 UARTPCellID0 Register on page 3-26 */
    /* 0xFF4 */ 
    union
    {
        __O uint32_t Reg;
        struct
        {
            __OM uint32_t UARTPCellID1   : 8;    /* [ 0:7 ]     These bits read back as 0xF0 */
            __OM uint32_t RESERVED       : 24;   /* [ 8:31 ] */
        } Bit;
    } UARTPCellID1;      /* RO 0xF0 8 UARTPCellID1 Register on page 3-26 */
    /* 0xFF8 */ 
    union
    {
        __O uint32_t Reg;
        struct
        {
            __OM uint32_t UARTPCellID2   : 8;    /* [ 0:7 ]     These bits read back as 0x05 */
            __OM uint32_t RESERVED       : 24;   /* [ 8:31 ] */
        } Bit;
    } UARTPCellID2;      /* RO 0x05 8 UARTPCellID2 Register on page 3-26 */
    /* 0xFFC */ 
    union
    {
        __O uint32_t Reg;
        struct
        {
            __OM uint32_t UARTPCellID3   : 8;    /* [ 0:7 ]     These bits read back as 0xB1 */
            __OM uint32_t RESERVED       : 24;   /* [ 8:31 ] */
        } Bit;
    } UARTPCellID3;      /* RO 0xB1 8 UARTPCellID3 Register on page 3-27 */
} tPL011;

#endif  //!__REGPL011__H__
