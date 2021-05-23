ENTRY(vector_start)     /* ENTRY: 시작 위치의 Symbol을 지정 */    
SECTIONS                /* SECTION 시작 */
{
    . = 0x0;            /* 첫 번째 섹션이 0x00000000에 위치 */

    .text :
    {
        *(vector_start)
        *(.text .rodata)
    }
    .data :
    {
        *(.data)
    }
    .bss :
    {
        *(.bss)
    }
}
