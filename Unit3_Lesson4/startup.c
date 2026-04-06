//Eng. Mahmood

#include <stdint.h>

void Reset_Handler();
void NMI_Handler();
void H_Fault_Handler();
void Bus_Fault ();
void Usage_Fault_Handler();

uint32_t vectors[] __attribute__((section(".vectors")))= 
{
    (uint32_t)  0x2001000,
    (uint32_t)  &Reset_Handler,
    (uint32_t)  &NMI_Handler,
    (uint32_t)  &H_Fault_Handler,
    (uint32_t)  &Bus_Fault,
    (uint32_t)  &Usage_Fault_Handler
};

void Reset_Handler ()
{

}