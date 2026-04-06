/*
    Lesson_4 live write along with Eng.Keroles
    3/16/2026       12:54pm
    @copyright: Eng.Mahmood_Elyamani
*/
#define SYSCTL_RCGC2_R      (*(volatile unsigned long*)(0x400FE108))
#define GPIO_PORTF_DIR_R    (*(volatile unsigned long*)(0x40025400))
#define GPIO_PORTF_DEN_R    (*(volatile unsigned long*)(0x4002551C))
#define GPIO_PORTF_DATA_R   (*(volatile unsigned long*)(0x400253FC))

int main()
{
    volatile unsigned long delay_count;
    SYSCTL_RCGC2_R = 0x20;
    //delay to make sure GPIO is up and running
    for(delay_count = 0; delay_count<200000; delay_count++);        //we identified delay_count as volatile beforehand so the optimizer wouldn't delete this line during compile.
    GPIO_PORTF_DIR_R |= (1<<3);                                     //DIR is output for pin3 in Port F
    GPIO_PORTF_DEN_R |= (1<<3);                                     //PIN3 has been set as enabled in Port F
    while(1)
    {
        GPIO_PORTF_DATA_R |= (1<<3);                                //Setting pin 3
        for(delay_count = 0; delay_count<200000; delay_count++);    //Delay for a certain noticible period
        GPIO_PORTF_DATA_R &= ~(1<<3);
        for(delay_count = 0; delay_count<200000; delay_count++);    //Delay for a certain noticible period

    }
    return 0;
}