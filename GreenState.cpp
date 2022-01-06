#include <iostream>
#include <unistd.h>
#include "GreenState.h"

using namespace std;

GreenState::GreenState(TrafficControler* p_controler)
{
    m_controler = p_controler;
    m_controler->setLightState(1);
}

void GreenState::stateHandling(unsigned int timeCount)
{
    if (m_controler->getSignalDirector() == 0)
    {
        cout << "Green light now" << endl;

        if (timeCount > 0)
        {
            sleep(timeCount);
            m_controler->setState(m_controler->getYellowState());
            m_controler->stateHandling(timeCount);
        }
    }
}