/*
    Linker script for the STM32F103C done from scratch
    16/3/2026       9:25am
    @Mahmood Elyamani
*/

MEMORY
{
    flash(RX)   :   ORIGIN = 0x08000000, LENGTH = 128k
    sram(RWX)   :   ORIGIN = 0x20000000, LENGTH = 20k
}

SECTIONS
{
    .text :
    {
        *(.vectors*)
        *(.text*)
    } > flash
    .bss    : { *(.bss*) } > sram
}