#ifndef DELAY_H_INCLUDED
#define DELAY_H_INCLUDED



#endif // DELAY_H_INCLUDED
void delay(unsigned int mseconds)//function for delay
{
    clock_t goal=mseconds+clock();
    while(goal>clock());
}
