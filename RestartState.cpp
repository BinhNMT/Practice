#include <iostream>
#include <unistd.h>
#include "RestartState.h"

using namespace std;

RestartState::RestartState(TrafficControler* p_controler)
{
    m_controler = p_controler;
}

void RestartState::stateHandling(unsigned int timeCount)
{
    cout << "Light are Restart now" << endl;
    m_controler->setSignalDirector(0);
    m_controler->setState(m_controler->getGreenState());
    m_controler->stateHandling(timeCount);
}