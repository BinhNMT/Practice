#include <iostream>
#include <unistd.h>
#include "ResumeState.h"

using namespace std;

ResumeState::ResumeState(TrafficControler* p_controler)
{
    m_controler = p_controler;
}

void ResumeState::stateHandling(unsigned int timeCount)
{
    cout << "Light are resume to working now" << endl;
}